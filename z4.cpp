#include <iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    if(a==1)
    {
        cout<<"NO";
        return 0;
    }
    while(a%2==0)
    {
        a=a/2;
    }
    if(a==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

