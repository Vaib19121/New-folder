#include <iostream>
using namespace std;
int countgcd(int r1,int r2)
{
    int q , rem;
    while(r2>0)
    {
        q = r1/r2;
        rem = r1 - q*r2;
        r1 = r2;
        r2 = rem;
       
    }
    return r1;
}
int main()
{
    cout<<"\nVAIBHAV MEHAR || ROLL NO 58 || BATCH - B2"<<endl;
    int r1 ,r2, res;
    cout<<"Enter The First Value: "<<endl;
    cin>>r1;
    cout<<"Enter The Second Value: "<<endl;
    cin>>r2;
    res = countgcd(r1,r2);
    cout<<"gcd is : "<<res;
    return 0;
}