#include<iostream>
using namespace std;

int main(){
    //array pointers
    int arr[]={1,2,3,4,5};
    
    // cout<<arr<<endl; //prints base address of array
    // cout<<*arr<<endl; //prints first element
    
    // int a=10;
    //arr=&a; //gives error since arr is constant pointer
    
-------//pointer arithmetic:- --------------------------
    //increment(++) / decrement(--)
    //new address = old address + n*(sizeof(data type))
    
    //cout<<arr[2]<<" is same as "<<*(arr+2)<<endl;
    
    //increment:-
    // int val=10;
    // int *ptr=&val;
    // cout<<ptr<<endl;
    // ptr++;
    // cout<<ptr<<endl;
    
    //subtraction:--
    // int* ptr2;
    // int* ptr1=ptr2+2;
    // cout<<(ptr1-ptr2)<<endl;
    
    //comparision w.r.t same example as above
    // cout<<(ptr2 > ptr1)<<endl;
    // cout<<(ptr1 == ptr2)<endl;
    
    //copying a pointer
    // int num=5;
    // int *p=&num;
    
    // int *q=p;
    // cout<<p<<" is same as "<<q<<endl;
    // cout<<*p<<" is same as "<<*q<<endl;
    
    
    return 0;
}