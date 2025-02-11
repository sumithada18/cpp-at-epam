#include<iostream>
using namespace std;

void changeA(int *ptr){ //pass by reference
    *ptr=20; //dereference ptr and change value to 20
}

void changePtr(int *ptr){
    ptr=ptr+1;
}
/*
void changePtr(int *ptr){
    ptr = ptr + 1;
}
When we try to print ptr in the main function, its value remains the same 
before and after calling changePtr. 

Reason: The function receives a copy of the pointer (call by value), 
so modifications inside the function do not affect the original pointer.

Solution: Use call by reference to modify the original pointer.

Corrected:
void changePtr(int *&ptr) {
    ptr = ptr + 1;
}
*/


int main(){
    int a=30;
    
    changeA(&a); //address of 'a' is passed
    cout << "value inside main func: " << a << endl; //gives output as 20.

   int *ptr = &a;
   cout << "value before: " << ptr << endl;
   changePtr(ptr);
   cout << "value after: " << ptr << endl;
    return 0;
}
