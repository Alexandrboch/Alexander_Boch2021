#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, S, i, j;
    cin >> S >> N;
    int mon[N];
    vector<vector<int>> v(S+1, vector<int>(N+1, 0));

    for (int i=0; i<N; i++)
    {
        cin>>mon[i];
    }
    for(i=1; i<=S; i++)
    {
        v[i][0]=10*mon[0]+S;
    }
    for(i=1; i<=S; i++)
     {
        for(j=1; j<=N; j++)
        {
            if (i>=mon[j-1])
            {
                if(v[i][j-1]<=v[i-mon[j-1]][j]+1)
                {
                         v[i][j]=v[i][j-1];
                }
                else
                {
                    v[i][j]=v[i-mon[j-1]][j]+1;
                }
            }
            else
            {
                v[i][j]=v[i][j-1];
            }
        }
    }

    cout<<v[S][N]<<endl;;
    return 0;
}
