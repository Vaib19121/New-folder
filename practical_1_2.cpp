#include <iostream>
using namespace std;
int main(){
    string aplhabet = "abcdefghiklmnopqrstuvwxyz";
    string key = "monarchy";
    string new_aplha = "";
    string plaintext = "vaibhav";
    int flag =0;
    char arr[5][5];
    int key_len = key.length();
    int x=0,y=0;
    for(int i=0;i<aplhabet.length();i++)
    {
        flag =0;
        for(int j=0;j<key.length();j++)
        {
            if(aplhabet[i]==key[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
           new_aplha = new_aplha + aplhabet[i];
        }
    }
    cout<<"The aplhabets Which are not in key are : "<<new_aplha<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(key_len>0)
            {
                arr[i][j] = key[x];
                x++;
                key_len--;
            }
            else
            {
                arr[i][j] = new_aplha[y];
                y++;
            }
        }
    }
    cout<<"The 5X5 matrixis as follows : "<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
 
    int start= 0;
    int end =1;
    char new_pt[6][2];
    x=0;
    y=0;
    //hello  //he // ll -> lx
    cout<<"The Pair Of the WORD is : "<<endl;
    while(end <= plaintext.length())
    {
        y=0;
        if(plaintext[start] == plaintext[end] || plaintext[end]=='\0' )
        {
            new_pt[x][y] = plaintext[start];
            y++;
            new_pt[x][y] = 'z';
            start = start + 1;
            end = end + 1;
            x++;
        }
        else
        {
            new_pt[x][y] = plaintext[start];
            y++;
            new_pt[x][y] = plaintext[end];
            start = start+2;
            end = end+2;
            x++;
        }
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<new_pt[i][j]<<" ";
        }
        cout<<endl;
    }

    int t=x;
    int i,j;
    int curr_i1=10, curr_j1=10,curr_i2=10, curr_j2=10;
    char encrypted_string[t][2];
    int index=0,k=0,col_cond=0,row_cond=0;
   
    for(k=0;k<t;k++)
    {
        col_cond=0;
        row_cond=0;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(arr[i][j]==new_pt[k][0])
                {
                    curr_i1=i;
                    curr_j1=j;
                    col_cond=1;
                }
                if(arr[i][j]==new_pt[k][1])
                {
                    curr_i2=i;
                    curr_j2=j;
                    row_cond=1;
                }
                if(row_cond==1 && col_cond==1)
                {
                    if(curr_i1==curr_i2 && (curr_i1!=10 && curr_i2!=10))
                    {
                        encrypted_string[index][0]=arr[curr_i1][(curr_j1+1)%5];
                        encrypted_string[index++][1]=arr[curr_i2][(curr_j2+1)%5];
                        break;
                    }
                    if(curr_j1==curr_j2 && (curr_j1!=10 && curr_i2!=10))
                    {
                        if(curr_i1==0)
                        {
                            curr_i1=5;
                        }
                        if(curr_i2==0)
                        {
                            curr_i2=5;
                        }
                        encrypted_string[index][0]=arr[(curr_i1-1)%5][curr_j1];
                        encrypted_string[index++][1]=arr[(curr_i2-1)%5][curr_j2];
                        break;
                    }
                    if(curr_i1!=curr_i2 && curr_j2!=curr_j1)
                    {
                        encrypted_string[index][0]=arr[curr_i1][curr_j2];
                        encrypted_string[index++][1]=arr[curr_i2][curr_j1];
                        break;
                    }
                }
            }
            if(row_cond==1 && col_cond==1)
            {
                break;
            }
        }
    }
    cout<<"The encrypted pairs are: \n";
    for(i=0;i<index;i++)
    {
        cout<<encrypted_string[i][0]<<encrypted_string[i][1]<<"";

    }
/**************************/
/***DECRYPTION OF CIPHER TEXT****************/
    cout<<endl<<endl;
    char decrypted_string[t][2];
    index=0;
    for(k=0;k<t;k++)
    {
        col_cond=0;
        row_cond=0;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(arr[i][j]==encrypted_string[k][0])
                {
                    curr_i1=i;
                    curr_j1=j;
                    col_cond=1;
                }
                if(arr[i][j]==encrypted_string[k][1])
                {
                    curr_i2=i;
                    curr_j2=j;
                    row_cond=1;
                }                if(row_cond==1 && col_cond==1)
                {
                    if(curr_i1==curr_i2 && (curr_i1!=10 && curr_i2!=10))
                    {
                        if(curr_j1==0)
                        {
                            curr_j1=5;
                        }
                        if(curr_j2==0)
                        {
                            curr_j2=5;
                        }
                        decrypted_string[index][0]=arr[curr_i1][(curr_j1-1)%5];
                        decrypted_string[index++][1]=arr[curr_i2][(curr_j2-1)%5];
                        break;
                    }
                    if(curr_j1==curr_j2 && (curr_j1!=10 && curr_i2!=10))
                    {
                        decrypted_string[index][0]=arr[(curr_i1+1)%5][curr_j1];
                        decrypted_string[index++][1]=arr[(curr_i2+1)%5][curr_j2];
                        break;
                    }
                    if(curr_i1!=curr_i2 && curr_j2!=curr_j1)
                    {
                        decrypted_string[index][0]=arr[curr_i1][curr_j2];
                        decrypted_string[index++][1]=arr[curr_i2][curr_j1];
                        break;
                    }
                }
            }
            if(row_cond==1 && col_cond==1)
            {
                break;
            }
        }
    }
    cout<<"The decrypted pairs are: \n";
    for(i=0;i<index;i++)
    {
        cout<<decrypted_string[i][0]<<""<<decrypted_string[i][1]<<" ";
    }

    return 0;
   
}