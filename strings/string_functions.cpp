/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str="sumit hada's code";
    // string :: iterator it; //c++ iterator
    // for(it=str.begin();it!=str.end();it++){
    //     cout<<*it;
    // }
    
    //different member functions in string class
    
    //print size of string
    //cout<<"size of str is: "<<str.length()<<endl;
    //cout<<"capacity of str is: "<<str.capacity()<<endl;
    
    // str.append(" = best code ever"); //concatenates
    // cout<<str;
    
    //substring 
    cout<<str.substr(0,5)<<endl; //start index, length of substring
    
    //find: 
    //searches in string, gives first occurence of sequence specified
    cout<<str.find("hada"); 
    
    return 0;
}