#include<iostream>
using namespace std;

void changeA(int *ptr){ //pass by reference
    *ptr=20; //defrefrence ptr and change value to 20
}

int main(){
    int a=30;
    
    changeA(&a); //adress of 'a' is passed
    cout<<"value inside main func: "<<a<<endl;
    return 0;
}