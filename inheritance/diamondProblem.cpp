//******************************** Diamond problem and its solution **********************************************/

#include <iostream>
using namespace std;

/*
Problem:
class Base
{
public:
	int _b;
};

class derived1 : public Base
{
public:
	int _d1;
};

class derived2 : public Base
{
public:
	int _d2;

};

class Final : public derived1, public derived2
{
public:
	int _f;
};
*/


//solution: virtual inheritance
class Base { public: int _b; };

class derived1 : virtual public Base { public: int _d1; };

class derived2 : virtual public Base { public: int _d2; };

class Final : public derived1, public derived2 { public: int _f; };

int main()
{

	//Final obj;
	//obj._b = 10; // error: request for member _b is ambiguous

	//problem: deamond problem
	/*
	      Base 
	      /  \
	derived1 derived2   (ech has its own Base copy)
	      \  /
	      Final  (gets 2 Base copies - confusion)
	*/
	
//memory layout of base
// _b

//memory layout of derived1:
// _b
// _d1

//memory layout of derived2:
// _b
// _d2

//memory layout of final:
// _b
// _d1
// _d2
// _f

// Issue: Final class inherits two separate Base instances via Derived1 and Derived2, causing ambiguity.

//inherit virtually: Only the Base class gets a vtable, and all derived classes access the single shared Base instance via their vptrs.

    Final obj;
    obj._b = 102;
    
    cout << obj._b << endl; //program runs smoothly!
    
	return 0;
}