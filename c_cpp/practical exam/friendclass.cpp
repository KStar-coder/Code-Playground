//friend class
#include<iostream>
  
using namespace std;

class myclass1{
    friend class myclass2;   //myclass2 is a friend of myclass 1
    int x;
    public:
    myclass1(int a){
        x=a;
    }
};
class myclass2{
    public:
    void showData(myclass1 obj){
        cout<<"The value of x is "<<obj.x<<endl;
    }
};
  
int main()
{
    myclass1 obj(5);
    myclass2 obj2;   
    obj2.showData(obj);
    return 0;
}