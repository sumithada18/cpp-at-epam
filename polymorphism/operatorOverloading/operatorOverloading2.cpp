#include<iostream>
using namespace std;

class Int {
	int elem;
public:
	Int() {
	}

	Int(int val) : elem{val} {}
	void printVal() {
		cout << elem << endl;
	}
	Int& operator++() { //pre-increment
		elem++;
		return *this;
	}
	Int operator++(int dummy) { //post increment
		Int tmp = *this;
		elem++;
		return tmp;
	}
	/*
	Q) why do we make temporary object in post-increment ?
	Ans: post-increment should return the original value before incrementing.
	since elem gets increased -> we need to store its old value before modification, which we do 
	
	Q) Q) Why does pre-increment (`++i`) return by reference, but post-increment (`i++`) returns by value?
	Ans: - `++i` modifies and returns the same object.  
		 - `i++` creates a copy, increments the original, and returns the copy.  
	*/
};

int main() {
	Int i(100);
	i.printVal();

	//i++; -. throws error if operator is not overloaded
	//i.printVal();
	//i++; //post-increment
	//i.printVal();
	//++i; //pre-increment
	//i.printVal();

	Int obj;
	obj = (++i);
	obj.printVal();

	Int obj2;
	obj2 = (i++);
	obj.printVal();

	i.printVal();

	return 0;
}
