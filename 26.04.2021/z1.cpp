#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin>>N>>K;
    long long a = 1;
    long long b = K-1;
    for(int i = 0; i < N-2; i ++)
    {
        int c = b;
        b = (a + b)*(K-1);
        a = c;

    }
    cout<<(a+b)*(K-1);
    return 0;
}
