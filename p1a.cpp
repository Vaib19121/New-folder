#include <bits/stdc++.h>
using namespace std;

void encrypt(char cipher_text[],char key[]){
    char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cout<<"Plaintext: "<<cipher_text<<endl;
    for(int i = 0; i<strlen(cipher_text);i++){
        for(int j =0; j<26;j++){
            if(alpha[j]== cipher_text[i]){
                cipher_text[i]=key[j];
                break;
            }
        }
    }
    cout<<"cipher_text: "<<cipher_text<<endl;
}

void decrypt(char cipher_text[],char key[]){
    char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i=0; i<strlen(cipher_text); i++){
        for(int j=0; j<26; j++){
            if(cipher_text[i]==key[j]){
                cipher_text[i]=alpha[j];
                break;
            }
        }
    }
    cout<<"cipher_text: "<<cipher_text;
}

int main()
{
    char cipher_text[10];
    cin>>cipher_text;
    char key[] = "qwertyuiopalskdjfhgzmxncbv";
    encrypt(cipher_text,key);

    decrypt(cipher_text,key);
    return 0;
}