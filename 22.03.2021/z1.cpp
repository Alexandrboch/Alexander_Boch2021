#include <iostream>
using namespace std;
int main()
{
    int kol=0;
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        if((a[i]%4 == 0 && a[i]/1000!=4 && a[i]/1000!=7) || (a[i]%7 == 0 && a[i]/1000!=7 && a[i]/1000!=1) || (a[i]%9 == 0 && a[i]/1000!=9 && a[i]/1000!=8))
        {
            cout<<a[i]<<" ";
            kol++;
        }
    }
    if(kol==0)
        cout<<0;
    return 0;
}
