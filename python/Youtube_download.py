import webbrowser

url = input("Enter your youtube url: ")

url = url[:12]+ 'ss' + url[12:]

webbrowser.open(url)


