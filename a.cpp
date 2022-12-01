#include <iostream>
using namespace std;
int main()
{
    int r, c;
    for (r = 1; r <= 4; r++)//n
    {
        for (c = 1; c <= 7; c++)//2n-1
        {
            if(r==1 && c>3 || r==4 && c<5 || r+c==5 || r+c==8){
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