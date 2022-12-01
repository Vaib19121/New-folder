#include <iostream>
using namespace std;
int main(){
    int r,c;
    for(r=1;r<=9;r++){
        for(c=1;c<=9;c++){
            if( r==c && r<=5 || c-r>=0 && r<=5 && r+c<11   ){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
}