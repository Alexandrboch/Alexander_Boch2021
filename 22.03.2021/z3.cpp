#include <iostream>
#include <iomanip>
using namespace std;


struct vector_new {
    int * vec;
    size_t size;
    size_t capacity;

    vector_new()
    {
        vec = new int[2];
        size = 0;
        capacity = 2;
    }
    void add(int a)
    {
        if(size == capacity)
        {
            capacity = capacity * 2;
            int *b = new int[capacity];
            for(size_t i=0; i<size;i++)
            {
                b[i]=vec[i];
            }
            delete [] vec;
            vec = b;
            vec[size] = a;
            size++;

        }
        else
        {
            vec[size] = a;
            size++;
        }

    }

     ~vector_new()
    {
        delete [] vec;
    }


};


int main()
{
    int x, sum = 0, sumkv = 0;
    float srk, dsp;
    vector_new V;
    cin>>x;
    while(x!=0)
    {
        V.add(x);
        cin>>x;
    }

    for(size_t i=0; i<V.size; i++)
    {
        sum = sum + V.vec[i];
        sumkv = sumkv + V.vec[i]*V.vec[i];
    }

    srk = (1.0*sum)/(1.0*V.size);
    dsp = (1.0*sumkv)/(1.0*V.size) - srk*srk;

    cout.precision(3);
    cout<<std::fixed<<srk<<" "<<dsp;
    return 0;

}
