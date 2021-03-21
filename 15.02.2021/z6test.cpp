#include <iostream>
using namespace std;

int main()
{
    int N, M, K;
    cin>>N>>M>>K;
    int **pol = new int* [N];
    for(int i=0;i<N;i++)
        pol[i]=new int [M];
    for(int i=0; i<N; i++)
        for(int j=0;j<M;j++)
            pol[i][j]=0;



    for(int i=0; i<K; i++)
    {
        int n, m;
        cin>>n;
        cin>>m;
        pol[n-1][m-1]=-1;

    }

    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<M-1;j++)
        {
            if(pol[i][j]!=-1)
            {
                int kol=0;

                if(pol[i-1][j]==-1)
                    kol++;
                if(pol[i-1][j+1]==-1)
                    kol++;
                if(pol[i][j+1]==-1)
                    kol++;
                if(pol[i+1][j+1]==-1)
                    kol++;
                if(pol[i+1][j]==-1)
                    kol++;
                if(pol[i+1][j-1]==-1)
                    kol++;
                if(pol[i][j-1]==-1)
                    kol++;
                if(pol[i-1][j-1]==-1)
                    kol++;

                pol[i][j]=kol;

            }
        }
    }

    for(int i=1; i<N-1; i++)
    {
        if(pol[i][0]!=-1)
        {
            int kol=0;

            if(pol[i-1][0]==-1)
                kol++;
            if(pol[i-1][1]==-1)
                kol++;
            if(pol[i][1]==-1)
                kol++;
            if(pol[i+1][1]==-1)
                kol++;
            if(pol[i+1][0]==-1)
                kol++;

            pol[i][0]=kol;
        }

         if(pol[i][M-1]!=-1)
        {
            int kol=0;

            if(pol[i-1][M-1]==-1)
                kol++;
            if(pol[i-1][M-2]==-1)
                kol++;
            if(pol[i][M-2]==-1)
                kol++;
            if(pol[i+1][M-2]==-1)
                kol++;
            if(pol[i+1][M-1]==-1)
                kol++;

            pol[i][M-1]=kol;
        }
    }

    for(int i=1; i<M-1; i++)
    {
        if(pol[0][i]!=-1)
        {
            int kol=0;

            if(pol[0][i-1]==-1)
                kol++;
            if(pol[1][i-1]==-1)
                kol++;
            if(pol[1][i]==-1)
                kol++;
            if(pol[1][i+1]==-1)
                kol++;
            if(pol[0][i+1]==-1)
                kol++;

            pol[0][i]=kol;
        }

         if(pol[N-1][i]!=-1)
        {
            int kol=0;

            if(pol[N-1][i-1]==-1)
                kol++;
            if(pol[N-2][i-1]==-1)
                kol++;
            if(pol[N-2][i]==-1)
                kol++;
            if(pol[N-2][i+1]==-1)
                kol++;
            if(pol[N-1][i+1]==-1)
                kol++;

            pol[N-1][i]=kol;
        }
    }

    if(pol[0][0]!=-1)
    {
        int kol=0;

        if(pol[0][1]==-1)
            kol++;
        if(pol[1][1]==-1)
            kol++;
        if(pol[1][0]==-1)
            kol++;
        pol[0][0]=kol;
    }

    if(pol[0][M-1]!=-1)
    {
        int kol=0;

        if(pol[0][M-2]==-1)
            kol++;
        if(pol[1][M-2]==-1)
            kol++;
        if(pol[1][M-1]==-1)
            kol++;
        pol[0][M-1]=kol;

    }

    if(pol[N-1][M-1]!=-1)
    {
        int kol=0;

        if(pol[N-2][M-1]==-1)
            kol++;
        if(pol[N-2][M-2]==-1)
            kol++;
        if(pol[N-1][M-2]==-1)
            kol++;
        pol[N-1][M-1]=kol;

    }

    if(pol[N-1][0]!=-1)
    {
        int kol=0;

        if(pol[N-2][0]==-1)
            kol++;
        if(pol[N-2][1]==-1)
            kol++;
        if(pol[N-1][1]==-1)
            kol++;
        pol[N-1][0]=kol;
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout<<pol[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<N; i++)
        delete []pol[i];
    delete [] pol;
    cout<<pol[100][100];
    return 0;
}
