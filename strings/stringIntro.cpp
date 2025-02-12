
//understanding strings
#include <iostream>
#include<string>
using namespace std;

int main()
{
    /*
    std::string is a part of c++ standard library(<string> header). 
    It is a class that dynamically manages strings. 
    std::string is a part of STL - there is no separate STL string.
    */

    /*
    String literal - fixed, immutable sequence of characters stored in read-only memory(data segment).
    It is not std::string - it's const char*(c-style string). Modifying a string literal causes undefined behaviour.
    
    example:-
    char* ptr = "Hello";
    ptr[0]='M'; //turns out to be an undefined behaviour since string literals are read-only
    cout << ptr << endl; //that'll also give error
    corrected code:-
    const char* ptr2 = 'hello';
    cout << "String literal" << ptr2 <<endl;
    */
    // string str;
    // str="sumit"; //way of declaration
    // cout<<str<<endl;
    
    //---taking input---
    //string name;
    // cin>>name; //input: sumit hada
    // cout<<name; //output: sumit
    //issue: as soon as it encounters a space, it stops  
    //solution: getline
    // getline(cin, name);
    // cout<<name;
    
    
    //string str2(10,'s'); 
    //cout<<str2<<endl; //sss.. upto 10 times

    //string str3 {str2}; //initializing with other string's value
    //cout<<str3<<endl;
     
    //string s="sumit hada";
    //cout<<s[4];
    
    //cout << "sumit" + "hada" << endl; //gives error
    //solution:
    // string fname="sumit";
    // string lname=" hada";
    // cout << fname + lname;
     
    return 0;
}
