#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base() = 0; //pure virtual destructor
};

Base::~Base() {
	cout << "Base destructor called" << endl;
}

class Derived : public Base {
public:
	~Derived() {
		cout << "Derived destructor called" << endl;
	}

};
/*
 - A pure virtual destructor makes a class abstract but still needs a definition.
 - Used when a base class should not be instantiated but must have a destructor.
 - Forces derived classes to provide cleanup while ensuring base class cleanup.
*/

int main()
{
    Base* b = new Derived();
    delete b;
	return 0;
}