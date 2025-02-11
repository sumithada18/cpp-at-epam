#include <iostream>
using namespace std;

int main()
{
	//derefrence pointer(*)->value at address
	int a=10;
	int *ptr=&a;
	//cout<<ptr<<" "<<&a<<endl;

	//double pointer
	int **parPtr = &ptr;
	cout<<*(parPtr)<<endl; //value at address stored by parPtr
	cout<<**(parPtr)<<endl;

	//Null pointer: a pointer that doesn't point to any location
	int* ptr2=NULL;

	return 0;
}