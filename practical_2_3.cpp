#include <iostream>
using namespace std;
void generate_key(int arr[][5],int m, int n)
{
    int temp;
    for(int i=0;i<m;i++)
    {
        temp = arr[0][i];
        arr[0][i] = arr[1][i];
        arr[1][i] = temp;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(arr[1][i]>arr[1][j])
           {
               temp = arr[1][i];
               arr[1][i] = arr[1][j];
               arr[1][j] = temp;
               
               temp = arr[0][i];
               arr[0][i] = arr[0][j];
               arr[0][j] = temp;
           }
        }
    }
}
int main()
{
    int m = 5;
    string str = "enemy attacks tonight";
    string plaintext = "";
    int key[2][5] = {{3,1,4,5,2},
                    {1,2,3,4,5}};
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == 32)
        {
            continue;
        }
        else
        {
            plaintext = plaintext + str[i];
        }
    }
    if(plaintext.length()%5!=0)
    {
        while(plaintext.length()%5!=0)
        {
            plaintext = plaintext + 'x';
        }
    }
    cout<<"The plaintext is : "<<plaintext<<endl;
    int n = plaintext.length()/5;
    int k=0;
    char arr[n][m];
    cout<<"Matrix of plaintext is :  "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            arr[i][j] = plaintext[k];
            k++;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    char new_arr[n][m] ;
    int y1,y2;
    for(int i=0;i<m;i++)
    {
        y1= (key[0][i])-1;
        y2 = (key[1][i])-1;
       
        for(int j=0;j<n;j++)
        {
            new_arr[j][y2] = arr[j][y1];
        }
    }
    cout<<"Matrix for Encryption is:  "<<endl;
    string Encrypted = "";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<new_arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            Encrypted = Encrypted + new_arr[j][i];
        }
    }
    cout<<"Encrypted text is : "<<endl;
    cout<<Encrypted;
    int dekey[2][5] ;
   
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<5;j++)
        {
            dekey[i][j] = key[i][j];
         
        }
        cout<<endl;
    }
    generate_key(dekey,m,n);
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            arr[i][j] = new_arr[i][j];
       
        }
    }
    cout<<endl;
   
    for(int i=0;i<m;i++)
    {
        y1= (dekey[0][i])-1;
        y2 = (dekey[1][i])-1;
       
        for(int j=0;j<n;j++)
        {
            new_arr[j][y2] = arr[j][y1];
        }
    }

    cout<<"Matrix for Decryption is:  "<<endl;
    string Decrypted = "";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<new_arr[i][j]<<" ";
        }
        cout<<endl;
    }
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            Decrypted = Decrypted + new_arr[i][j];
        }
    }
    cout<<"Decrypted text is : ";
    cout<<Decrypted;
   
    return 0;
   
}