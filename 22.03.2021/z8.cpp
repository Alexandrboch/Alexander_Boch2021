#include <iostream>
#include <climits>
using namespace std;





int main()
{
    int x, i = 0;
    int a[10000];
    while(cin>>x)
    {
        a[i]=x;
        i++;
    }
    int N = i;
    for(i = 0; i<N; i++)
    {
        for(int j = 0; j<(N-i-1); j++)
        {
            if(a[j]>a[j+1])
            {
                int c = a[j+1];
                a[j+1] = a[j];
                a[j] = c;
            }
        }
    }
    for(i = 0; i<N; i++)
    {
        if(a[i]%2 == 0)
        {
            cout<<a[i]<<" ";
        }
    }

    for(i = 0; i<N; i++)
    {
        if(a[i]%2 != 0)
        {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
