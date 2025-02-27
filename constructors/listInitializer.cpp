#include <iostream>
using namespace std;

/*
A const member must be initialized at the time of object creation because
its value cannot be changed once set.

class Base{
  const int _x;
  public:
  Base(int x){
      _x = x;
  }
};

solution: list initialization
class Base{
  const int _x;
  public:
  Base(int x) : _x(x) {}
  void print(){ cout << _x << endl; }
};

reason:
-> Const members must be initialized when the object is created.
-> Initializer lists allow initialization before the constructor body executes.

*/

/*
class Base {

	int &_x;

public:
	Base(int x) {
		_x = x;
	}

	void print() { cout << _x << endl; }
};
    problem with above code:
    references must be initialized when they are declared/created

    solution: initializer list:

class Base {

	int &_x;

public:
	Base(int x) : _x(x) {}
	void print() { cout << _x << endl; }
};

*/

//==============================================================================

/*
class One{
  int _x;
  public:
  One(){
      cout << "inside ones cons.." << endl;
  }
  One(int x) : _x(x) {};
};

// class Two{
//     One a;
//     public:
//     Two(One x){
//         a=x; //error
//     }
// };

class Two{
    One a;
    public:
    Two(One x) : a(x) {}
};

key takeaway : Member initializer lists are not just for cases where a default constructor is missing; they also ensure direct initialization, 
avoiding unnecessary default construction and assignment.
Even if a default constructor exists, using initializer lists is more efficient and preferred.
*/


//==============================================================================

/*
class demo{
  int var;
  public:
  demo(int var){
      var = var;
  }
  void print(){
      cout << var << endl;
  }
};
problem:
Shadowing: If the constructor parameter has the same name as the member variable
and you're missing this-> or an initializer list, it may not initialize correctly.
*/
//corrected:
class demo {
	int var;
public:
	demo(int var) : var(var) {}
	void print() {
		cout << var << endl;
	}
};

//==============================================================================

//another use case:
class myBase {
public:
	myBase(int x) {
		cout << "inside base cons.." << endl;
	}
};

class myDer : public myBase {
public:
	//this will give error
	// myDer(){
	//     myBase(10);
	// }

	myDer() : myBase(10) {
		cout << "inside der cons..";
	}
};
//In C++, the base class constructor must be initialized using the member initializer list, not inside the body.
/*
Issue:
myBase(10); creates a temporary, separate base class object, but it does not initialize the actual base part of myDer.
Since myBase does not have a default constructor, compilation fails.
*/

//========================================================================================================
//Note: members are initialized in the order they are declared in the class, not in the order they appear in the initialization list
class Test{
public:
//int _a;
//int _b;
//Test() : _b(10), _a(_b) {} //undefined behaviour

//correct way:-
int _b;
int _a;
Test() : _b(10), _a(_b) {} //undefined behaviour

};

int main()
{
	/*
	Base b(10);
	b.print();
	*/


	//One one(10);
	//Two two(one);


	//demo d(9);
	//d.print();


	myDer md;

	return 0;
}
