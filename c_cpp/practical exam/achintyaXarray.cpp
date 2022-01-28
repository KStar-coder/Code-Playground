#include <iostream>
using namespace std;

class arr
{
    int ar[5];
    int res[5];
    int x, r, i;

public:
    arr()
    {
        if (x = NULL)
            cout << " empty" << r << endl;
    }

    

    arr(int x)
    {
        int ar[] = {2, 3, 4, 5, 6};

        for (i = 0; i < 5; i++)
        {
            res[i] = x * ar[i];
        }
    }

    void display()
    {
        cout << " After multiplication " << endl;
        for (i = 0; i < 5; i++)
        {
            cout << res[i] << endl;
        }
    }
};

int main()
{
    cout<<"enter the number to be multiplied:"<<endl;
    int x;
    cin>>x;
    arr a;
    // a.gets();
    a=arr(x);
    a.display();
    return 0;
}