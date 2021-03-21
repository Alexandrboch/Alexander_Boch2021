#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int main()
{
    int a;
    stack <int> st;
    cin>>a;
    while(a!=0)
    {
        if(a>0)
            st.push(a);
        else if(a<0 && st.size()!=0 && abs(a)<st.top())
        {
            int b = st.top();
            st.pop();
            b = b + a;
            st.push(b);
        }
        else if(a<0 && st.size()!=0 && abs(a)>=st.top())
            st.pop();
        cin>>a;
    }
    if(st.size()>0)
        cout<<st.size()<<" "<<st.top();
    else
        cout<<st.size()<<" "<<-1;
    return 0;
}
