#include <iostream>
using namespace std;
int main()
{
    int a, i=2;
    cin>>a;
    while(i!=(a/2+1))
    {
        while(a%i==0)
        {
            cout<<i<<endl;
            a=a/i;
        }
    i++;

    }
    return 0;
}

