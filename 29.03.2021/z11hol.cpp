#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

long sortp (long * a, long low, long hight)
{
    long p = hight;
    int i = 0;
    long J = low;
    while(i==0)
    {
        long kol=0;
        for(long j=J; j < p; j++)
        {
            if(a[j]>=a[p])
            {
                kol++;
                J = j;
                long vr = a[j];
                a[j] = a[p-1];
                a[p-1] = a[p];
                a[p] = vr;
                p = p-1;
                break;
            }
        }
        if(kol == 0)
        {
            i=1;
        }
    }

    return p;
}

void holsort (long * a, long low, long hight)
{
    if(low<hight)
    {
        long p = sortp(a, low, hight);
        holsort(a, low, p-1);
        holsort(a, p+1, hight);
    }
}

int main()
{

    ifstream Fin;
    ofstream Fout;
    Fin.open("input.txt");
    Fout.open("outputhol.txt");
    long i = 10000;
    while(i!=1100000)
    {
        long * mas;
        mas = new long[i];
        for(long j = 0; j<i; j++)
        {
            *(mas+j) = rand();
        }
        auto start = std::chrono::high_resolution_clock::now();


        holsort(mas, 0, i-1);


        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> nsec = end - start;
        Fout<<i<<" "<<nsec.count()*1000.0f<<"ms";
        Fout<<endl;
        i=i+1000;
        cout<<i;
    }

    Fin.close();
    Fout.close();
    return 0;
}
