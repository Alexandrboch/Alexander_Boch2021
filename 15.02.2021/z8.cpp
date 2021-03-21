#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int main()
{
    stack <int> postf;
    string st, znak = "+-*/";
    while(cin>>st)
    {
        int p=znak.find(st);
        if(p==-1)
            postf.push(atoi(st.c_str()));
        else
        {
            if(postf.size()<=1)
            {
                cout<<"ERROR";
                return 0;
            }
            int a=postf.top(); postf.pop();
            int b=postf.top(); postf.pop();
            if(st=="+")
                postf.push(a+b);
            if(st=="-")
                postf.push(b-a);
            if(st=="*")
                postf.push(a*b);
            if(st=="/")
                postf.push(b/a);
        }
    }
    if(postf.size()==1)
    {
        cout<<postf.top();
    }
    else
    {
        cout<<"ERROR";
    }
    return 0;
}
