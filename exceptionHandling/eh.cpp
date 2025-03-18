#include<iostream>
using namespace std;

class Test {
public:
	Test() {
		cout << "test cons.. called" << endl;
	}
	~Test() {
		cout << "test des.. called" << endl;
	}
};


class myClass1 {
	int x;
public:
	myClass1() {
		x = 10;
		cout << "myclass1::cons.. called" << endl;
	}
	~myClass1() {
		cout << "myclass1::des.. called" << endl;
	}
};

class myClass2 {
	int x;
	int* ptr;
	myClass1 obj;
public:
	myClass2() {
		try {
			x = 10;
			ptr = new int(10);
			cout << "inside myclass2::myclass2() try" << endl;
			throw runtime_error("crash");
		}
		catch (exception e) {
			cout << "catched! error is:" << e.what() << endl;
			throw;
		}
	}
	~myClass2() {
		cout << "myclass2::des.. called" << endl;
	}

};
// Stack unwinding is the process of destroying fully constructed objects ("has-a" relationship)  
// whenever an exception is thrown, ensuring proper cleanup before propagating the exception.  

//void f1() {
//	cout << "f1() start" << endl;
//	throw 100;
//	cout << "f1() end" << endl;
//}
//
//void f2() {
//	cout << "f2() start" << endl;
//	f1();
//	cout << "f2() end" << endl;
//}
//
//void f3() {
//	cout << "f3() start" << endl;
//	try {
//		f2();
//	}
//	catch(int i){
//		cout << "exception caught" << i << endl;
//	}
//	cout << "f3() end" << endl;
//}


void f1() {
	cout << "f1() start" << endl;
	throw 100;
	cout << "f1() end" << endl;
}

void f2() {
	cout << "f2() start" << endl;
	try {
		f1();
	}
	catch (int) {
		cout << "inside f2 try" << endl;
	}
	cout << "f2() end" << endl;
}

void f3() {
	cout << "f3() start" << endl;
	try {
		f2();
	}
	catch (int i) {
		cout << "exception caught" << i << endl;
	}
	cout << "f3() end" << endl;
}


int main() {
	/*
	int x = -1;
	cout << "before try" << endl;
	try {
		cout << "inside try" << endl;
		if (x < 0) {
			throw x;
		}
	}
	catch (int x) {
		cout << "exception caught" << endl;
	}
	cout << "After catch (Will be executed)" << endl;
	*/

	//============ example one ==========
	/*
	cout << endl;
	try {
		int num_r = 10;
		int deno_r = 0;
		int res;

		if (deno_r == 0) {
			throw runtime_error("division by zero not allowed!"); //runtime_error is a class, you can create objects of it. - in this line it creates a obj with error message in it
		}

		res = num_r / deno_r;
		cout << "result after division: " << res << endl;
	}
	catch (const exception& e) {
		cout << "exception" << endl;
	}
	*/

	//============== property one : catch-all ===================
	/*cout << endl;
	try {
		throw 10;
	}
	catch (char* excp) {
		cout << "caught" << endl;
	}
	catch (...) {
		cout << "default exception" << endl;
	}*/
	//there is no catch block for int, catch(...) will be executed

	//============== property two : IMPLICIT type-conversion does not happen for primitive types ===================
	/*cout << endl;
	try {
		throw 'a';
	}
	catch (int x) {
		cout << "caught" << x;
	}
	catch (...) {
		cout << "default exception" << endl;
	}*/

	//=============== property three : Thrown exception destroys try objects. =========================
	/*cout << endl;
	try {
		Test t;
		throw 10;
	}
	catch (int) {
		cout << "inside catch" << endl;
	}*/

	//================================ stack unwinding =======================================================
	/*try {
		myClass2 obj;
	}
	catch (exception e) {
		cout << "inside main:" << e.what() << endl;
	}*/

	//=========================== stack unwinding =========

	f3();

	return 0;
}