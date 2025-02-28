#include <iostream>
using namespace std;

class base {
public:
	void display() { //use virtual or not
		cout << "base" <<endl;
	}
};
class derive: public base {
public:
	void display() {
		cout << "derive" <<endl;
	}
};
//==============================================================================

class A {
public:
	virtual void fun(int x = 0) {
		cout << "A::fun(), x=" << x << endl;
	}
};

class B : public A {
public:
	void fun(int x) {
		cout << "B::fun(), x=" << x << endl;
	}
};

//==============================================================================

class shape { //abstract class
public:
	virtual void draw() = 0;
};

class circle : public shape {
public:
	void draw() {
		cout << "draw" << endl;
	}
	//if a derived class does not override all the pure virtual functions from its base class - it also remains abstract
	//and it can't be instantiated
	void area() {
		cout << "pie r square" << endl;
	}
};

//=======================================================================================

class base1 {
public:
	base1() {
		cout << "base1 constructor called" << endl;
	}
	virtual ~base1() {
		cout << "base1 destructor called" << endl;
	}
};

class derived1 : public base1 {
public:
	derived1() {
		cout << "derived1 constructor called" << endl;
	}
	~derived1() {
		cout << "derived1 destructor called" << endl;
	}
};


int main()
{
//    base* b = new derive;
	//pointer is of type base so base class member function is invoked - when virtual keyword is not
	//added to display func of base class - static binding is done - compile time polymorphism
//    b->display();
	/*
	If you don't use virtual, the base class pointer will always call the base class function (static binding).
	If you use virtual, the function is resolved at runtime, and the derived class function gets called (dynamic binding).
	*/

//    circle c;
//    c.area();

//    A* a;
//    B b;
//    a = &b;
//    a->fun(); //calling derived class's member funciton - fun() of derived is called but default value of base fun() is uned
	// value of x is substituted at compile-time, and at run-time derived class fun() function is called.


	derived1* d1 = new derived1();
	base1* b1 = d1;

	//delete b1;
	/*
 Without virtual destructor:
	delete b1;
	calls only base::~base(), skipping derived::~derived(), causing a memory leak.

 With virtual destructor:
	delete b1;
	looks up the vtable, calls derived::~derived(), then base::~base(), ensuring proper cleanup.
    */
    
    //adding virutal keyword and calling delete b1 again
    delete b1;
    
	return 0;
}