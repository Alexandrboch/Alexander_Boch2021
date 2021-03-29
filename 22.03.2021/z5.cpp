#include <iostream>
using namespace std;





int main()
{
    int N;
    cin>>N;
    int a[N];
    int min_rast = INT_MAX;
    for(int i = 0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < N; i++)
    {
        if(a[i]<0)
        {
            int t = a[i];
            int kol = 0;
            for(int j = i + 1; j < N; j++)
            {
                kol++;
                if(a[j] == -t && kol < min_rast)
                {
                    min_rast = kol;

                }
            }
        }
    }
    if(min_rast == INT_MAX)
    {
        cout<<0;
    }
    else
    {
        cout<<min_rast;
    }
    return 0;
}
