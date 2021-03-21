#include <iostream>
using namespace std;
int main()
{
    int a, b, nod;
    cin>>a>>b;
    while(a!=0 and b!=0)
    {
        if (a>=b)
        {
            a=a%b;
        }
        else if (b>a)
        {
            b=b%a;
        }
    }

    nod = a + b;
    cout<<nod;
    return 0;
}
