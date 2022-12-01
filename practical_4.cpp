#include <iostream>
using namespace std;
int gcd(int r1,int r2)
{
        int t,q, rem;
        int a =r1;
        int b= r2;
        while(r2>0)
        {
            q = r1/r2;
            rem = r1 - q*r2;
            r1 = r2;
            r2 = rem;
        }        
        return r1;
}
int inversem(int r1,int r2)
{
        int t,q, rem;
        int t1 =0;
        int t2= 1;
        int a=r1;
        int b=r2;
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
        if(r1 == 1)
        {
            if(t1>0)
            {
                return  t1;
            }
       
            else
            {
                t1 = t1 + a;
                return t1;
            }
        }
        return 0;
}
int main()
{
    int list1[] = {5,10,15};
    int list2[] = {1,1,3};
    int res,M =1;
    int sum=0;
    int Marr[3],Minv[3];
    cout<<"VAIBHAV MEHAR || ROLL NO: 58 || BATCH : B2"<<endl;
    cout<<"========================================================="<<endl;
    for(int i=0;i<2;i++)
    {
        res = gcd(list1[i],list1[i+1]);
        cout<<"GCD( "<<list1[i]<<","<<list1[i+1]<<") : "<<res<<endl;
    }
    for(int i=0;i<3;i++)
    {
        M = M*list1[i];
    }
    cout<<"Value of M :  "<<M<<endl;
    for(int i=0;i<3;i++)
    {
        Marr[i] = M/list1[i] ;
        cout<<"M"<<i<<" : "<<Marr[i]<<endl;
    }
    sum =0;
    for(int i=0;i<3;i++)
    {
        Minv[i] = inversem(list1[i],Marr[i]);
        cout<<"M-"<<i<<" : "<<Minv[i]<<endl;
        sum = sum + (Minv[i]*Marr[i]*list2[i]);
    }
    int flag =0;
    for(int i=0;i<3;i++)
    {
        if(Minv[i]<1)
        {
            flag =1;
        }
    }
    if(flag==0)
    {
        cout<<sum%M<<endl;
    }
    else
    {
        cout<<"Not Possible"<<endl;
    }
    cout<<"========================================================="<<endl;
    return 0;
}