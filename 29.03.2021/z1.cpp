#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;


int main()
{

    ifstream Fin;
    ofstream Fout;
    Fin.open("input.txt");
    Fout.open("output.txt");
    string s;
    while(!Fin.eof())
    {
        while(getline(Fin,s))
        {
            int a = s.size();
            int mas[a];
            int i = 0;
            while(s.size()!=0)
            {
                mas[i]=atoi(s.c_str());
                int x = s.find(' ');
                if(x!=-1)
                    s.erase(0, x+1);
                else
                    s.erase(0);
                i++;
            }
            //есть mas, его нужно отсортировать ивывести кол во эл и время;
            auto start = std::chrono::high_resolution_clock::now();
            for(int j = 0; j<i; j++)
            {
                for(int m = 0; m<i-1-j; m++)
                {
                    if(mas[m]>mas[m+1])
                    {
                        int el = mas[m+1];
                        mas[m+1] = mas [m];
                        mas[m] = el;
                    }
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> nsec = end - start;
            Fout<<i<<" "<<nsec.count()*1000.0f<<"ms";
            Fout<<endl;
        }
    }
    Fin.close();
    Fout.close();
    return 0;
}
