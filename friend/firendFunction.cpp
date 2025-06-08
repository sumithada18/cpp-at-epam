#include <iostream>

class Demo {
private:
	int a, b; 
public:
	void setData(int val1, int val2) { // part of Demo class
		a = val1;
		b = val2;
	}
	friend void func(Demo); // not a part of class, just friend

	// declare a friend function as public, private, or protected it doesn't matter since it's not a part of
	// the class
};

void func(Demo d) {
	int c = d.a + d.b;
	std::cout << c << "\n";
}



//===========================================================
// an interesting real world scenerio of this friend function
// Problem:
// You need a single function to use private data from two unrelated classes(not base / derived).

//A member function of one class can't access another class’s private data.

// Solution : Use a friend function and declare it as friend in both classes.
// example:

class B;
class A {
	int a;
public:
	void setData(int val) {
		a = val;
	}
	friend void showSum(A, B);
};

class B {
	int b;
public:
	void setData(int val) {
		b = val;
	}
	friend void showSum(A, B);
};

void showSum(A obj1, B obj2) {
	std::cout << "sum is " << obj1.a + obj2.b;
}

// another example:

//class Complex {
//	int real, imag;
//public:
//	void setData(int r, int i) {
//		real = r;
//		imag = i;
//	}
//	void showData() {
//		std::cout << real << " + i" << imag;
//	}
//	Complex& operator+(Complex c) { // c1 -> caller object, c2 -> passed as parameter
//		Complex temp;
//		temp.real = real + c.real;
//		temp.imag = imag + c.imag;
//		return temp;
//	}
//};

//class Complex {
//	int real, imag;
//public:
//	void setData(int r, int i) {
//		real = r;
//		imag = i;
//	}
//	void showData() {
//		std::cout << real << " + i" << imag;
//	}
//	friend Complex& operator+(Complex&, Complex&);
//};
//
//Complex& operator+(Complex& c1, Complex& c2) { // c1 -> passed as argument, c2 -> passed as parameter
//	Complex temp;
//	temp.real = c1.real + c2.real;
//	temp.imag = c1.imag + c2.imag;
//	return temp;
//}
//=====================================================================

// Problem statement:  what if we wish to do c3=int+c2; that is not possible since 'int' is not an object of class Complex
// and it can't access member functions of it
// Solution: Make the operator+() as friend i.e outside the class

class Complex {
public:
	int real, imag;
	void setData(int r, int i) {
		real = r;
		imag = i;
	}
	void display() {
		std::cout << real << " + " << imag << "i\n";
	}
	Complex operator+(Complex& c) {
		Complex temp;
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		return temp;
	}
	Complex operator+(int val) {
		Complex temp;
		temp.real = real + val;
		temp.imag = imag;
		return temp;
	}
	friend Complex operator+(int, Complex&);
};

Complex operator+(int val, Complex& c) {
	Complex temp;
	temp.real = val + c.real;
	temp.imag = c.imag;
	return temp;
}
//============================================================


// Member Function of another class as friend function
class base;
class other {
public:
	void other_function(base&);
};

class base {
private:
	int privateData;
protected:
	int protectedData;
public:
	base(int data) {
		privateData = data;
		protectedData = data * 2;
	}
	friend void other::other_function(base&);
};

void other_function(base& b) {
	std::cout << "other::other_function()" << "\n";
}

int main()
{
	/*Demo d1, d2;
	d1.setData(10, 15);
	func(d1);*/

	/*A obj1;
	B obj2;
	obj1.setData(10);
	obj2.setData(12);

	showSum(obj1, obj2);*/



	//Complex c1, c2,c3;
	//c1.setData(2,5);
	//c2.setData(7,20);
	//c3 = c1 + c2; // c3 = c1.operator+(c2)
	//c3.showData();




	/*Complex c1, c2, c3;
	c1.setData(2, 3);
	c2.setData(3, 6);
	c3 = 5 + c2;
	c3.display();*/

	return 0;
}
