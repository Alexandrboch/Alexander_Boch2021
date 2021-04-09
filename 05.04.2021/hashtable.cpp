#include <iostream>
using namespace std;

int HasFunction(int x, int key, size_t size)
{
    x = x%size;
    return x;
}

struct Node
{
    int t; // t=1 €чейка заполена, t=0 €чейка пуcта€
    int key;
    int value;
    Node * next;
};

struct HashMap
{
    int key_not;
    size_t size;
    size_t n_elements;
    Node * table;

    HashMap()
    {
        table = new Node[100];
        for(int i=0; i<100; i++)
        {
            table[i].t = 0;
            table[i].next = NULL;
        }
        size = 100;
        n_elements = 0;
        key_not = size-1;
    }

    void add(int key, int value)
    {
        if(n_elements<=size/2)
        {
            int i = HasFunction(key,key_not,size);
            if (table[i].t == 0)
            {

                table[i].key = key;
                table[i].value = value;
                table[i].t = 1;
                n_elements++;
            }
            else
            {
                Node * a = new Node;
                a->key = table[i].key;
                a->value = table[i].value;
                a->next = table[i].next;
                a->t = 1;
                table[i].key = key;
                table[i].value = value;
                table[i].t = 1;
                table[i].next = a;
            }
        }
        else
        {
            reallocate();
            add(key,value);
        }
    }

    int get(int key)
    {
        int i = HasFunction(key,key_not,size);
        if(table[i].key == key)
            return table[i].value;
        else
        {
            Node * a = table[i].next;
            while(a != NULL && a->key != key)
            {
                a = a->next;
            }
            if(a == NULL)
                return INT_MIN;
            else
                return a->value;
        }
    }

    void reallocate()
    {
        Node * new_table = new Node[size*2];
        for(int i=0; i<size*2; i++)
        {
            new_table[i].t = 0;
            new_table[i].next = NULL;
        }
        key_not = size*2-1;


        for(int i=0; i<size; i++)
        {
            Node * a = table+i;
            while(a!=NULL)
            {
                if(a->t == 1)
                {
                    int kay = a->key;
                    int val = a->value;
                    int i = HasFunction(kay,key_not,size*2);
                    if (new_table[i].t == 0)
                    {

                        new_table[i].key = kay;
                        new_table[i].value = val;
                        new_table[i].t = 1;
                    }
                    else
                    {
                        Node * b = new Node;
                        b->key = new_table[i].key;
                        b->value = new_table[i].value;
                        b->next = new_table[i].next;
                        b->t = 1;
                        table[i].key = kay;
                        table[i].value = val;
                        table[i].t = 1;
                        table[i].next = b;
                    }

                }
            }
        }

        for(int i = 0; i<size; i++)
        {
            Node * a = table+i;
            while(a != NULL)
            {
                Node * b = a;
                a = a->next;
                delete b;
            }
        }
        size = size*2;
        Node * table = new Node[size];
        for(int i = 0; i<size; i++)
        {
            table[i].key = new_table[i].key;
            table[i].value = new_table[i].value;
            table[i].t = new_table[i].t;
            table[i].next = new_table[i].next;

        }

        for(int i = 0; i<size; i++)
        {
            Node * a = new_table+i;
            while(a != NULL)
            {
                Node * b = a;
                a = a->next;
                delete b;
            }
        }

    }

    void pop(int key)
    {
        int i = HasFunction(key,key_not,size);
        if(table[i].key == key)
        {

            table[i].key = table[i].next->key;
            table[i].value = table[i].next->value;
            Node * a = table[i].next->next;
            delete table[i].next;
            table[i].next = a;
        }
        else
        {
            Node * a = (table+i);
            while(a->next != NULL && a->next->key != key)
            {
                a = a->next;
            }
            if(a->next!= NULL)
            {
                if(a->next->next != 0)
                {
                    Node * b = a->next->next;
                    delete a->next;
                    a->next = b;
                }
                else
                {
                    delete a->next;
                    a->next = NULL;
                }
            }
        }
    }
};

int main()
{

    return 0;
}
