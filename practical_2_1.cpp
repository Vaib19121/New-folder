#include<bits/stdc++.h>

using namespace std;

int main(){
    int m=5;
    string str = "enemy attacks tonight";
    string plaintext = "";
    int key[2][5] = {{3,1,4,5,2},{1,2,3,4,5}};

    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == 32){
            continue;
        }
        else{
            plaintext += str[i];
        }
    }
    int y1,y2;
    cout<<"Plaintext: "<<plaintext<<endl;
    string block="";
    string block_new="";
    string Encry="";
    int start=0;
    int end=5;
    int count = 0;
    char new_block[5];
    

    if(plaintext.length()%5 != 0){
       while (plaintext.length()%5 != 0)
       {
           plaintext += "x";
       }
       
    }
    while (end<=plaintext.length())
    {
        block="";
        for (int i = start; i < end; i++)
        {
            block += plaintext[i];
        }
        cout<<block<<"  : ";
        block_new= block;
        for (int j = 0; j < 5; j++)
        {
            y1 = key[0][j];
            y2 = key[1][j];
            block_new[y2-1] = block[y1-1];
        }
        cout<<block_new<<endl;
        for(int k=0;k<5;k++){
            Encry += block_new[k];
        }
        start = start + 5;
        end = end + 5;
    }
    start=0;
    end=5;
    cout<<"Encrypted Text: "<<Encry<<endl;
    string decry="";
    while (end<=Encry.length())
    {
        block="";
        for (int i = start; i < end; i++)
        {
            block += Encry[i];
        }
        cout<<block<<"  :";
        block_new= block;
        for (int j = 0; j < 5; j++)
        {
            y1 = key[0][j];
            y2 = key[1][j];
            block_new[y1-1] = block[y2-1];
        }
        cout<<block_new<<endl;
        for(int k=0;k<5;k++){
            decry += block_new[k];
        }
        start = start + 5;
        end = end + 5;
    }
    cout<<"\nDecrypted Text: "<<decry<<endl;
    return 0;
}