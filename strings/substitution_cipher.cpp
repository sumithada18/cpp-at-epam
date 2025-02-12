#include <iostream>
#include<string>
using namespace std;

int main()
{
    string alphabets {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba"};
    string msg="";
    
    cout<<"enter the message"<<endl;
    getline(cin,msg);
    
    cout<<"Encrypting message..."<<endl;
    
    string encrypted="";
    for(char ch:msg){
        size_t position = alphabets.find(ch);
        if(position!=string::npos){
            encrypted+=key[position];
        }
        else{
            encrypted+=ch;
        }
    }
    cout<<"encrypted message is: "<<encrypted<<endl;
    
    cout<<"wish to decrypt ? (y/n)"<<endl;
    string ans;
    cin>>ans;
    if(ans=="y"){
    
    //decryption
    string decrypted="";
    for(char ch:encrypted){
        size_t position = key.find(ch);
        if(position!=string::npos){
            decrypted+=alphabets[position];
        }
        else{
            decrypted+=ch;
        }
    }
    cout<<"decrypted message: "<<decrypted<<endl;
    }
    
    return 0;
}