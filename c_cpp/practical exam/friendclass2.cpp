//wap to exchange values between two classes
#include<iostream>
  
using namespace std;
class xyz;
class abc{
    int a ;
    public:
    abc()
    {
        a=10;
    }
     void show()
        {
                cout<<"\n Value of Number 2 : "<<a;
        }

    friend void swap(abc *num1, xyz *num2);

};

class xyz
{
    private:
        int b;
    public:
        xyz()
        {
                b=20;
        }

         void show()
        {
                cout<<"\n Value of Number 2 : "<<b;
        }

        
        friend void swap(abc *num1,xyz*num2);
};

void swap(abc *no1, xyz *no2)
{
        int no3;
        no3=no1->a;
        no1->a=no2->b;
        no2->b=no3;
}

int main()
{
        abc b;
        xyz d;
        swap(&b, &d);
        b.show();
        d.show();
        return 0;
}