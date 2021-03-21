#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct List
{
    int num;
    List* next;
};



int main()
{
    int n, kol=0, nom, bol=1;
    string st;
    List *nach = NULL;
    cin>>n;
    cin>>st;
    cin>>nom;
    nach = new List;
    nach->num = nom;
    nach->next = NULL;
    List *end = nach;
    kol++;

    for(int i=1;i<n;i++)
    {
        string st;
        int nom;
        cin>>st;
        if(st=="+" && bol==1)
        {
            cin>>nom;
            end->next = new List;
            end = end->next;
            end->num = nom;
            end->next = NULL;
            kol++;

        }
        if(st=="+" && bol!=1)
        {
            cin>>nom;
            nach->num = nom;
            kol++;
            bol=1;

        }


        if(st=="*" && bol==1)
        {
            cin>>nom;
            List *a = nach;
            for(int i = 0; i<(kol-1)/2;i++)
            {
                a = a->next;
            }
            List *b = new List;
            b->num = nom;
            List *c = a->next;
            a->next = b;
            b->next = c;
            kol++;
            if(c==NULL)
                end = b;
        }
        if(st=="*" && bol!=1)
        {
            cin>>nom;
            nach->num = nom;
            kol++;
            bol=1;
        }


        if(st=="-")
        {
            cout<<nach->num<<endl;
            if(nach->next!=NULL)
            {
                List *aa = nach;
                nach = nach->next;
                delete aa;
                kol--;
            }
            else
            {
                bol=-1;
                kol--;
            }

        }
    }
    if(kol!=0)
    {
        for(int i = 0; i<kol; i++)
        {
            List *a = nach;
            nach = a->next;
            delete a;
        }
    }
    return 0;
}
