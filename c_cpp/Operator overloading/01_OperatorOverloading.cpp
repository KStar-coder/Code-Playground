#include <iostream>
using namespace std;
class int_array
{
public:
    int a[5];
    friend istream &operator>>(istream &inp, int_array &x) // overloading extraction operator
    {
        cout << "Enter the values of the array: \n";
        for (int i = 0; i < 5; i++) // this loop takes input from user
        {
            inp >> x.a[i]; // using inp instead of cin
        }
        return inp;
    }
    friend ostream &operator<<(ostream &outp, int_array &x) // overloading insertion operator
    {
        outp << "The array entered is: \n";
        for (int i = 0; i < 5; i++) // displaying the array using this loop
        {
            outp << x.a[i] << " "; // using outp instead of cout
        }
        return outp;
    }
};
int main()
{
    int_array a; // object created
    cin >> a;
    cout << a; // overloading
    return 0;
}