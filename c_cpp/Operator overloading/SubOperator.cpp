// Sub operator using friend function
#include <iostream>

using namespace std;

class numbers
{
private:
    int x;

public:
    void setdata(int a)
    {
        x = a;
    }
    void showdata()
    {
        cout << "x=" << x << endl;
    }
    friend numbers &operator-(numbers &);
};
numbers &operator-(numbers &n)
{
    n.x = -n.x;
    return n;
}
int main()
{
    numbers number;
    number.setdata(3);
    number.showdata();
    number = -number;
    number.showdata();
    return 0;
}