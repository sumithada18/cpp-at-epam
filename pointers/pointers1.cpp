#include <iostream>
using namespace std;

int main()
{
	/*
 pointer -> a varible that stores the memory address as it's value.
 example:-
 	string name = "sumit"; //a name variable of type string.
 	string* ptr = &name; //a pointer variable with the name ptr.

   	cout << name << endl; //outputs value of name(sumit).
    	cout << &name << endl; //outputs memory address of name.
     	cout << ptr << endl; //m/m address of name is printed.
	*/

	/*
 Note: Both are the same.
 int *ptr;
 int* ptr
	*/
	
	//derefrence pointer(*)->value at address
	int a=10;
	int *ptr=&a;
	//cout << ptr << " " << &a << endl; //&a means value at address started 

	//double pointer
	int **parPtr = &ptr;
	cout<<*(parPtr)<<endl; //value at address stored by parPtr
	cout<<**(parPtr)<<endl;

	//Null pointer: a pointer that doesn't point to any location
	int* ptr2=NULL;

	return 0;
}
