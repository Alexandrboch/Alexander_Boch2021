#include <iostream>
using namespace std;
int main()
{
    int a, i;
    cin>>a;
    for(i=2;i<(a/2+1);i++)
    {
        if(a%i==0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
