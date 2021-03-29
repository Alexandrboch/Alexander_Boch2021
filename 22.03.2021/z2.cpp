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
    int x;
    float srk, dsp;
    vector_new V;
    while(cin>>x)
    {
        V.add(x);
    }
    for(size_t i=0; i<V.size; i++)
    {
        cout<<V.vec[i]<<endl;
        cout<<V.size;
    }


    return 0;

}
