#include <iostream>
using namespace std;
int main()
{
    int n, sum=0, s=0;
    float sr;
    cin>>n;
    int N[n];


    for(int i=0; i<n; i++)
    {
        int num;
        cin>>num;
        N[i]=num;
        s=s+num;
    }

    sr=(s*1.0)/n;

    for(int i = 0; i<n; i++)
    {
        if(N[i]>sr)
        {
            sum=sum+N[i];
        }
    }

    cout<<sum;

    return 0;
}
