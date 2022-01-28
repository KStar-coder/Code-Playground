#include <iostream>

using namespace std;

class numbers
{
private:
    int x;

public:
    void setdata(int a)
    {
        x = a; // passes the value of a to x
    }
    void showdata()
    {
        cout << "X = " << x << endl; // displays the data of x
    }
    friend numbers &operator++(numbers &);
};
numbers &operator++(numbers &n)
{
    n.x = n.x + 1;
    return n;
}
int main()
{
    numbers n;
    n.setdata(3);
    n.showdata();
    n = ++n;
    n.showdata();
    return 0;
}