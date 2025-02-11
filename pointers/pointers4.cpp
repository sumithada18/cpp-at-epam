// ConsoleApplicationSumit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void func(int arr[]) { //"not the whole array but just the pointer to it" i.e int *arr
	cout << sizeof(arr) << endl;
	//yeilds output as 8 
}

int getSum(int* arr, int n) {
	int sum = 0;
	for (int i = 0;i < n;i++) {
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int arr[] = { 11,12,13,14,23 };
	//all the three yeilds the same output(base address)
	/*cout << arr << endl;
	cout << &arr << endl;
	cout << &arr[0] << endl;*/

	//----------------------------------
	//understanding pointer & character array

	//char ch[6] = "hello";
	//cout << ch << endl; //in case of character array it behaves different, rather than giving base address it prints the whole array
	//
	//char* c = &ch[0];
	//cout << c << endl; //this also prints the whole character array


	//------------- pointer and functions -----------------
	func(arr);
	//get sum of last three elements only:- how pointer helps in passing half the array only to the getSum function!
	cout<< getSum(arr+2, 3)<< endl;

}

