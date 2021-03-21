#include <fstream>
#include <string>
#include <stack>
#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    stack <int> postf;
    string st, znak="+-*/";
    while(fin>>st)
    {
        int p=znak.find(st);
        if(p==-1)
            postf.push(atoi(st.c_str()));
        else
        {
            if(postf.size()<=1)
            {
                fout<<"ERROR";
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
                fout<<postf.top();
            }
            else
            {
                fout<<"ERROR";
            }
    fin.close();
    fout.close();
    return 0;
}
