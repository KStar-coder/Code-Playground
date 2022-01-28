// WAP to fin the larger of the twi numbers using template
#include <iostream>

using namespace std;

template <class t>
t maxi(t a, t b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << maxi(a, b) << endl;

    return 0;
}