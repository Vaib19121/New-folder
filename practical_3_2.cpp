#include <iostream>
using namespace std;
void countgcd(int r1,int r2)
{
    int a= r1, b = r2;
    int t1 =0,t2= 1;
    int t,q, rem;
    while(r2>0)
    {
        q = r1/r2;
        rem = r1 - q*r2;
        r1 = r2;
        r2 = rem;
        t = t1 - q*t2;
        t1 = t2;
        t2 = t;
    }
    cout<<"gcd is : "<<r1<<endl;
    if(r1 == 1)
    {
        cout<<b<<" Inverse Exsist"<<endl;
        if(t1>0)
        {
            cout<<b<<" Inverse Is : "<<t1<<endl;
        }
        else
        {
            t1 = t1 + a;
            cout<<b<<" Inverse Is : "<<t1<<endl;
        }
    }
    else
    {
        cout<<"Inverse Does not Exsist : "<<endl;
    }
}
int main()
{
    int r1 ,r2, res;
    cout<<"\nVAIBHAV MEHAR || ROLL NO 58 || BATCH - B2"<<endl;
    cout<<"Enter The First Value: "<<endl;
    cin>>r1;
    cout<<"Enter The Second Value: "<<endl;
    cin>>r2;
    countgcd(r1,r2);
    return 0;
}