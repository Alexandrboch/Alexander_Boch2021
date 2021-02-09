#include <iostream>
using namespace std;
int main()
{
    int a, kol, MAX;
    cin>>a;
    MAX=a;
    kol=1;
    while(a!=0)
    {
        cin>>a;
        if (a==MAX)
            kol++;
        else if (a>MAX)
        {
            kol=1;
            MAX=a;
        }

    }

    cout<<kol;
    return 0;
}

