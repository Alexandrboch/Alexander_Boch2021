#include <iostream>
using namespace std;
int main()
{
    int a, MAX=0;
    cin>>a;
    while(a!=0)
    {

        if(a%2==0 and a>=MAX)
            MAX=a;

        cin>>a;
    }

    cout<<MAX;
    return 0;
}
