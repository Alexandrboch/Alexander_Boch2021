#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int W, N, i, j;
    cin>>W>>N;
    vector<vector<int>> v(2, vector<int> (N, 0));
    vector<vector<int>> V(W+1, vector<int>(N+1, 0));
    for (i=0; i<2; i++)
    {
        for (j=0; j<N; j++)
        {
            cin>>v[i][j];
        }
    }

    for (i=1; i<=W; i++)
    {
        for (j=1; j<=N; j++)
        {
            if (i>=v[1][j-1])
            {
                if(V[i][j-1]>=V[i-v[1][j-1]][j-1]+v[0][j-1])
                {
                    V[i][j]=V[i][j-1];
                }
                else
                {
                    V[i][j]=V[i-v[1][j-1]][j-1]+v[0][j-1];
                }

            }
            else V[i][j]=V[i][j-1];
        }
    }
    cout<<V[W][N]<<endl;
    return 0;
}
