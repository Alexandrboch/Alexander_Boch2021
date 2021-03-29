#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct List {
    int boo;
    int inf;
    string name;
    List * next;
};


int main()
{
    int n, b, kold, kol = 0;
    cin>>n>>b;
    List *head = new List;
    List *end = head;
    end->next = NULL;
    string name;
    int x;
    cin>>name>>x;
    head->name = name;
    head->boo = x;
    head->inf = b;
    for(int i = 1; i<n; i++)
    {
        cin>>name>>x;
        end->next = new List;
        end = end->next;
        end->boo = x;
        end->name = name;
        end->next = NULL;


    }
    cin>>kold;
    List *a = head;
    for(int i = 0; i<kold; i++)
    {
        if(a->inf == 0 && a->boo == 1 && n - kol != 1)
        {
            a->boo = -1;
            while(a->next->boo == -1)
            {
                a=a->next;
            }
            a->next->inf = 0;
            kol++;
            while(a->next->boo == -1)
            {
                a=a->next;
            }
            a=a->next;
        }
        else if(a->inf == 1 && a->boo == 1 && n - kol != 1)
        {
            while(a->next->boo == -1)
            {
                a=a->next;
            }
            a->next->inf = 1;
            while(a->next->boo == -1)
            {
                a=a->next;
            }
            a=a->next;
        }
        else if(a->inf == 0 && a->boo == 0 && n - kol != 1)
        {
            a->boo = 1;
            while(a->next->boo == -1)
            {
                a=a->next;
            }
            a->next->inf = 1;
            kol++;
            while(a->next->boo == -1)
            {
                a=a->next;
            }
            a=a->next;

        }
        else if(a->inf == 1 && a->boo == 0 && n - kol != 1)
        {
            while(a->next->boo == -1)
            {
                a=a->next;
            }
            a->next->inf = 0;
            while(a->next->boo == -1)
            {
                a=a->next;
            }
            a=a->next;
        }

    }
    List *nach = head;
    for(int i=0; i<n; i++)
    {
        if(nach->boo != -1)
        {
            cout<<nach->name<<" "<<nach->boo<<endl;
        }
        nach = nach->next;
    }
    return 0;
}
