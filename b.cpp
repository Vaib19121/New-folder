#include <iostream>
using namespace std;
int main()
{
    //Rhombus of n*n matrix
    int r, c,n;
    cin>>n;
    for (r = 1; r <= n; r++)//n
    {
        for (c = 1; c <= (2*n)-1; c++)//2n-1
        {
            if(r==1 && c>n-1 || r==n && c<r+1 || r+c==n+1 || r+c==2*n){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
            
        }
        cout << "\n";
    }
    return 0;
}