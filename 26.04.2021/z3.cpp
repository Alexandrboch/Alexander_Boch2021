#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
    int N;
    ifstream Fin;
    ofstream Fout;
    Fin.open("input.txt");
    Fout.open("output.txt");
    Fin>>N;
    string a[N];
    for(int i = 0;i<N;i++)
    {
        string x;
        Fin>>x;
        a[i] = x;
    }
    int d[N];

    for(int i = 0; i < N; i++)
    {
        d[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[i].substr(0,a[j].size()).find(a[j])!=-1)
            {
                d[i]  = max(d[i], 1+d[j]);
            }
        }
    }

    int max1 = d[0];

    for(int i=0; i<N;i++)
    {
        if(d[i]>max1)
            max1 = d[i];
    }

    Fout<<max1;
    Fin.close();
    Fout.close();
    return 0;
}
