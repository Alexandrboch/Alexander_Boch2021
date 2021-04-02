#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;


int main()
{

    ifstream Fin;
    ofstream Fout;
    Fin.open("input.txt");
    Fout.open("outputpuz.txt");
    long i = 10000;
    while(i!=110000)
    {
        long* mas;
        mas = new long[i];
        for(long j = 0; j<i; j++)
        {
            *(mas+j) = rand();
        }
        auto start = std::chrono::high_resolution_clock::now();
        for(long j = 0; j<i; j++)
        {
            for(long m = 0; m<i-1-j; m++)
            {
                if(*(mas+m)>*(mas+m+1))
                {
                    long el = *(mas+m+1);
                    *(mas+m+1) = *(mas+m);
                    *(mas+m) = el;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> nsec = end - start;
        Fout<<i<<" "<<nsec.count()*1000.0f<<"ms";
        Fout<<endl;
        i=i+1000;
        cout<<i;
    }

    Fout.close();
    Fout.open("outputvb.txt");

    i = 10000;
    while(i!=110000)
    {
        long mas[i];
        for(long j = 0; j<i; j++)
        {
            mas[j] = rand();
        }
        auto start = std::chrono::high_resolution_clock::now();

        long min;
        long ind;
        for(long j = 0; j<i-1; j++)
        {
            for(long m = j; m<i; m++)
            {
                min = LONG_MAX;
                if(mas[m]<min)
                {
                    min = mas[m];
                    ind = m;
                }
            }
            if(ind != j)
            {
                long a = mas[j];
                mas[j] = min;
                mas[ind] = a;
            }
        }


        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> nsec = end - start;
        Fout<<i<<" "<<nsec.count()*1000.0f<<"ms";
        Fout<<endl;
        i=i+1000;
        cout<<i;
    }

    Fout.close();
    Fout.open("outputvs.txt");

    i = 10000;
    while(i!=110000)
    {
        long mas[i];
        for(long j = 0; j<i; j++)
        {
            mas[j] = rand();
        }
        auto start = std::chrono::high_resolution_clock::now();


        long massort[i];
        massort[0] = mas[0];
        for(long j = 1; j<i; j++)
        {
            long a = mas[j];
            long ind;
            for(long m = j-1; m>=0; m--)
            {
                if(massort[m]>a)
                {
                    massort[m+1] = massort[m];
                    ind = m;
                }
            }
            massort[ind] = a;
        }


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
