window.DEBUG = true;

var fn_counter = function() {
  var counter = 0;
  var real_fn = function() {
    counter++;
    return counter;
  }
  return real_fn;
}

var is_like_text_data = function() {
  var data = [];

  return {
            'getData': function() { return data; },
             'add': function(pid) {
                var tobj = { post_id: pid };
                var fbuid = FB.getSession().uid;
                var request_path = '/facebook/util/delta/get/'+pid+'/'+fbuid;
                jQuery.getJSON(request_path, function(json) {
                    var isLike = json && json.delta;
                    if (isLike != false) {
                      tobj.isLike = true;
                    }
                    else {
                      tobj.isLike = false;
                    }
                });
                request_path = '/facebook/util/vote/get/'+pid;
                jQuery.getJSON(request_path, function(json) {
                    var votenum = json && json.votenum;
                    var voteme;

                    if (votenum == 0) {
                      voteme = 0;
                    }
                    else {
                      voteme = votenum;
                    }
                    tobj.voteme = voteme;
                })
                data.push(tobj);
              },
             'search': function(post_id) {
               var result;
               $.each(data, function(i, object) {
                   if (object.post_id == post_id) {
                     result = object;
                   }
               });
               return result;
             }
         }; //object
}
var text_data = is_like_text_data();

var ideas_promoted = function() {
  var promoted_ideas = [];
  $.getJSON('/facebook/idea/promoted', function(resp) {
      var ideas_length = resp.nodes.length;
      $.each(resp.nodes, function(i, j) {
        promoted_ideas.push(j.post_id['field_facebook_post_id_value']);
        text_data.add(j.post_id['field_facebook_post_id_value']);
        if (i == ideas_length - 1) {
         //do on the last
        }
      });
  });
  return function(post_id) {
    return promoted_ideas.indexOf(post_id);
  }
}
var is_promoted;
window.get_result = function () {
  $('#prepare-page').remove();
  $('#like-count').show();
  $('#results').html('<p class="loading">please wait, processing ...</p>');
/*
  var range_begin = $('#date-begin').datepicker('getdate').gettime();
  var range_tmp = $('#date-end').datepicker('getdate').gettime();
  var range_end = new date(range_tmp).sethours(17,0,0);
  if (typeof console != undefined)
    console.log(range_end, new date(range_end));
  generate_result(range_begin/1000, range_end/1000);
  */
  generate_result(ndaysago(30).getTime()/1000, today().getTime()/1000);
}
window.post_id_list = [];
window.create_post_id_to_check = function(list)  {
  var output = [];
  fb.array.foreach(list, function(v, k) {
    output.push('"' + v + '"');
  });
  output = output.join(',');
  output = "(" + output.tostring() + ")";
  return output;
}
window.generate_result = function(range_begin, range_end) {
  var query =
    "SELECT post_id, attachment, likes, created_time, actor_id, message, permalink, attribution " +
    "FROM stream " +
    "WHERE source_id = {0} AND actor_id != '220551554627180' AND attribution='happyschoolbreak.com' " +
/*          "created_time > '" + range_begin + "' AND " +
           "created_time <= '" + range_end + "' " + */
/*           "AND likes.count > 0 " +
    "ORDER BY likes.count DESC " + */
    " ORDER BY created_time DESC " +
    "LIMIT 9999";

  var posts = FB.Data.query(query, Drupal.settings.fb_util.pageid);
  var users = FB.Data.query(
     "SELECT uid, name " +
     "FROM user " +
     "WHERE uid in " +
     "(SELECT actor_id from {0})", posts);
  FB.Data.waitOn([posts, users], function() {
    $('#results').html('');
    var user_list = {};

    FB.Array.forEach(users.value, function(user) {
      user_list[user.uid] = user;
    });
    var cnt = fn_counter();
    var cnt2 = fn_counter();
    var cnt3 = fn_counter();

    FB.Array.forEach(posts.value, function(post) {
      if(typeof(console) !== 'undefined' && console != null) {
        //console.log('ALL', cnt());
      }

      if (post.attachment != undefined) {
        var actor = user_list[post.actor_id];
        var created = new Date(post.created_time * 1000);
        var picture = "http://graph.facebook.com/" + post.actor_id + "/picture";

        if (is_promoted(post.post_id) != -1) {
          jQuery.getJSON('/facebook/util/getnodeterm/' + post.post_id, function(res) {
            var category = '';
            if (res.length>0) {
              var item = generate_item(picture, post, actor, created);
              post_id_list.push(post.post_id);
              $('#results').append(item);
              prepare_function_is_like_text(post.post_id);
              prepare_function_vote_number(post.post_id);
              $('#results-count').html($('#results li').size() + " results");
              category = res[0].name;
              jQuery('li[post_id='+post.post_id+']').addClass('category-'+res[0].tid);
            }
            else {
              item = "";
              jQuery('li[post_id='+post.post_id+']').remove();
              if(0 && typeof(console) !== 'undefined' && console != null) {
                console.log('failed', cnt3());
                FB.api('/' + post.actor_id, function(resp) {
                });
              }

            }
          });//getJSON
        }
        else {

        }
      }
    });
  });
  FB.Canvas.setSize();
}

window.generate_item = function(picture, post, actor, created) {
  var item;
  /*
  if (typeof console != undefined)
    console.log(post);
    */
  var post_id = post.post_id;
  if (is_promoted(post_id) != -1) {
    //console.log(post_id, 'IN', is_promoted(post_id));
    try {
      item = "\
        <li class='user-idea' post_id="+ post.post_id +">\
          <div class='item-profile'>\
            <img src='" + picture + "'>\
          </div> \
            <div class='item-info'>\
              <div class='item-author'>\
                <a href='http://facebook.com/profile.php?id=" + actor.uid + "'>" + actor.name + "</a>\
                <em>" + created.format('mmmm dd, yyyy HH:MM') + "</em>\
              </div>\
              <div class='item-message'>" + post.message + "</div>\ <div class='item-permalink'><!--link: <a href='" + post.permalink + "'>" + post.permalink + "</a> !--></div>\ </div>\
          <div class='item-like'> \
            <span class='item-like-count'>" + '-' + "</span>\
            <span class='item-like-button'></span>\
          </div>\
          <div style='clear:both'></div>\
        </li>";
    }// try
    catch (err) {
      if(1 && typeof(console) !== 'undefined' && console != null) {
        console.log(err);
      }

    }
    return item;
  }
  else {
    //console.log('-------', post_id, 'OUT');
  }
}

function prepare_function_vote_number(post_id, cache) {
  var fbuid = FB.getSession().uid;
  var request_path = '/facebook/util/vote/get/'+post_id;
  var selector = '.user-idea[post_id='+post_id+'] .item-like > .item-like-count';
  if (cache == 'fresh') {
    return function() {
        jQuery.getJSON('/facebook/util/get_contest_start', function(res) {
          if (res['status'] !== 0) {
            jQuery.getJSON(request_path, function(json) {
                var votenum = json && json.votenum;
                if (votenum == 0) {
                  $(selector).html('0');
                }
                else {
                  $(selector).html(votenum);
                }
            });
          }
          else {
            $(selector).html('?');
          }
        }); // get contest start
    };
  }
  else {
    var data = text_data.search(post_id);
    if (data != undefined) {
      var votenum = data.voteme;
      if (votenum == 0) {
        $(selector).html('0');
      }
      else {
        $(selector).html(votenum);
      }
    }
  }
}

function prepare_function_is_like_text(post_id) {
  var data = text_data.search(post_id);
  if(data != undefined) {
    var selector = '.user-idea[post_id='+post_id+'] .item-like > .item-like-button';
    var isLike =  data.isLike;
    if (isLike != false) {
      $(selector).addClass('liked').html('Liked');
    }
    else {
      $(selector).html('Not Like');
    }
  }
  else {
    var fbuid = FB.getSession().uid;
    var request_path = '/facebook/util/delta/get/'+post_id+'/'+fbuid;
    return function() {
      jQuery.getJSON(request_path, function(json) {
          var isLike = json && json.delta;
          if (isLike != false) {
            $(selector).addClass('liked').html('Liked');
          }
          else {
            $(selector).html('Not Like');
          }
      });
    };
  }
}
window.today = function() {
  var d = new Date();
  return new Date(d.getFullYear(), d.getMonth(), d.getDate());
}

window.midnight = function() {
  return new Date(today().getTime() + 86400000);
}

window.now = function() {
  return new Date();
}

window.ndaysago = function(n) {
  return new Date(today().getTime() - n*86400000);
}
window.DEBUG = false;
window.fbAsyncInit = function() {
  // Init facebook sdk.
  FB.init({
    appId  : Drupal.settings.fb_util.appid,
    status : false, // check login status
    cookie : true, // enable cookies to allow the server to access the session
    xfbml  : false  // parse XFBML
  });
  FB.Canvas.setAutoResize(91);
  FB.getLoginStatus(function(response) {
    if (response.session) {
      if(0 && typeof(console) !== 'undefined' && console != null) {
        console.log('logged in');
      }
      is_promoted = ideas_promoted();
      get_result();
    }
    else {
      if(0 && typeof(console) !== 'undefined' && console != null) {
        console.log('redirect');
      }
      var login_url = "http://www.facebook.com/dialog/oauth/?scope=email&client_id=" + Drupal.settings.fb_util.appid +"&redirect_uri=http://www.happyschoolbreak.com/facebook/util/verify&response_type=code_and_token&display=page";

      top.window.location.href = login_url;
    }
  });
};


jQuery(document).ready(function ($) {
  jQuery('#like-count').hide();
  (function() {
    var e = document.createElement('script'); e.async = true;
    e.src = document.location.protocol +
      '//connect.facebook.net/en_US/all.js';
      document.getElementById('fb-root').appendChild(e);
  }());

  $('#get-result').click(function (e) {  });

});

$('.category-item').live('click', function(e) {
    var self = $(this);
    var tid = self.attr('tid');
    var user_idea_selector = '.user-idea.category-'+tid;
    if (tid == 'all') {
      $('.user-idea').show();
    }
    else {
      $('.user-idea').hide();
    }
    $('.category-item').removeClass('active');
    self.addClass('active');
    $(user_idea_selector).show();
});

$('.item-like-button').live('click', function(e) {
  var self = $(this);
  var li = self.parent().parent('li');
  self.toggleClass('liked');
  var friend = self.siblings('.item-like-count').eq(0);
  friend.html('?');
  if (self.is('.liked')) {
    if(1 && typeof(console) !== 'undefined' && console != null) {
      friend.html('+');
    }
  }
  else {
    if(1 && typeof(console) !== 'undefined' && console != null) {
      friend.html('-');
    }
  }
  var post_id = li.attr('post_id');
  if(1 && typeof(console) !== 'undefined' && console != null) {
    jQuery.post('/facebook/util/vote/toggle/'+post_id, { fb_session: JSON.stringify(FB.getSession()) }, function(res) {
      var json_obj = JSON.parse(res);
      var _status = json_obj && json_obj['status'];
      if(0 && typeof(console) !== 'undefined' && console != null) {
        console.log('_status = ', _status, res);
      }
      if (_status == 'voted') {
        self.removeClass('liked');
        self.addClass('liked');
        self.html('LIKED');
      }
      else {
        self.removeClass('liked');
        self.html('Not Like');
      }
      prepare_function_vote_number(post_id, 'fresh')();
    });
  }
});