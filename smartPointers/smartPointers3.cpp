#include <iostream>
#include <memory>
using namespace std;

class B; //forward declaration

class A {
public:
	shared_ptr<B>ptr1; //shared pointer to B
	void setPtr(shared_ptr<B>&p1) {
		ptr1=p1; //assigning shared ownership to ptr1
	}
	~A() {
		cout << "A's destructor called" << endl;
	}
};

class B {
public:
	shared_ptr<A>ptr2; //shared pointer to A
	void setPtr(shared_ptr<A>&p2) {
		ptr2=p2; //assigning shared ownership to ptr2
	}
	~B() {
		cout << "B's destructor called" << endl;
	}
};

void fun() {
	//creating shared_ptr instances for A and B
	shared_ptr<A>objAptr(new A());
	shared_ptr<B>objBptr(new B());

	//creating manual references, creating a cyclic dependency
	objAptr->setPtr(objBptr);
	objBptr->setPtr(objAptr);
	
	cout << objAptr.use_count() << endl;

	// When fun() ends, objAptr and objBptr go out of scope,
	// but their reference count never reaches zero due to cyclic dependency.
	// This results in a memory leak as neither A nor B gets destroyed.
}

int main()
{
	fun();
	// Memory leak occurs because A and B hold shared_ptr references to each other.
	// The use count never drops to zero, preventing automatic deletion.
	return 0;
}
/*
    solution:
    shared_ptr<B>ptr1; -> make this -> weak_ptr<B>ptr1;
    shared_ptr<A>ptr2; -> make this -> weak_ptr<A>ptr2;
    
    since weak_ptr does not increase the reference count, the cyclic dependency 
    is broken, and objects can be properly destroyed when no shared_ptr owns them.
*/