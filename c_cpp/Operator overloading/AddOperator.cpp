#include <iostream>

using namespace std;

class complex
{
private:
    int real;
    int imaginary;

public:
    void setdata(int r, int i)
    {
        real = r;
        imaginary = i;
    }
    complex operator+(complex &c)
    {
        complex temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
    void showdata()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main()
{
    complex c1, c2, c3;
    c1.setdata(2, 3);
    c2.setdata(4, 1);
    c3 = c1 + c2;
    c3.showdata();
    return 0;
}