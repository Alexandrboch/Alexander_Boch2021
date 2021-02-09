#include <iostream>
#include <string>
using namespace std;
int main()
{
    string nom;
    int i=0, s;
    int sum=0;
    cin>>s;
    cin>>nom;
    while(nom!="A999AA")
    {
            if(s>60 && nom[1]==nom[2] && nom[1]==nom[3])
                sum=sum+1000;
            else if(s>60 && (nom[1]==nom[2] || nom[1]==nom[3] || nom[2]==nom[3]))
                sum=sum+500;
                cout<<"500"<<endl;
            else if(s>60 && nom[1]!=nom[2] && nom[1]!=nom[3] && nom[2]!=nom[3])
                sum=sum+100;


            cin>>s;
            cin>>nom;

    }



    cout<<sum;
    return 0;
}

