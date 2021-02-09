#include <iostream>
using namespace std;
int main()
{
    int a, kol;
    cin>>a;
    while(a!=0)
    {

        if(a%2==0)
            kol++;

        cin>>a;
    }

    cout<<kol;
    return 0;
}

