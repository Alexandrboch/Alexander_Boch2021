#include <iostream>
using namespace std;
struct mas{
    int * a;
    int pr;

    mas(int n)
    {
        a = new int [n];
        for(int i=0;i<n;i++)
        {
            a[i] = -1;
        }
    }
    ~mas()
    {
        delete [] a;
    }
};
int main()
{
    int N, sum=0;
    cin>>N;
    int a[N];
    float b[N];
    for(int i = 0; i<N;i++)
    {
        cin>>a[i];
    }
    b[0]=a[0];
    b[1]=a[1];
    mas M1 = mas(N);
    mas M2 = mas(N);
    M1.pr = 0;
    M2.pr = 1;
    M1.a[0] = 0;
    M2.a[1] = 1;
    for(int i = 2; i<N; i++)
    {
        int c;
        if(b[i-1]>=b[i-2])
        {
            c = b[i-1];
            if(M1.pr > M2.pr)
            {
                M2.pr = i-1;
                for(int i = 0; i<N;i++)
                {
                    M2.a[i] = M1.a[i];
                }
                M1.a[i] = i;
                M1.pr = i;

            }
            else
            {
                M1.pr = i-1;
                for(int i=0;i<N;i++)
                {
                    M1.a[i] = M2.a[i];
                }

                M2.a[i]  = i;
                M2.pr =i;

            }

        }
        else
        {
            c = b[i-2];
            if(M1.pr < M2.pr)
            {
                M1.a[i] = i;
                M1.pr = i;
            }
            else
            {
                M2.a[i]  = i;
                M2.pr = i;
            }
        }
        b[i] = a[i] + c;
    }
    cout<<b[N-1]<<endl;
    if(M1.a[N-1]>0)
    {
        for(int i = 0; i<N;i++)
        {
            if(M1.a[i]>=0)
            {
                cout<<M1.a[i]+1<<" ";
            }
        }
    }
    else
    {
        for(int i = 0; i<N;i++)
        {
            if(M2.a[i]>=0)
            {
                cout<<M2.a[i]+1<<" ";
            }
        }
    }


    return 0;
}
