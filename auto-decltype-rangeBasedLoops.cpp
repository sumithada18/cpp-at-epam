#include <iostream>
#include <vector>
#include <typeinfo>
#include <vector>
#include <map>

class Base {public: virtual ~Base() {} };
class Derived : public Base {};


template<typename T1, typename T2>

/*
//this code will give output as int since return type is int

int add(T1 a, T2 b) {
	return a + b;
}

//solution:-
*/
//auto add(T1 a, T2 b) {
//	return a + b;
//}

//better approach
auto add(T1 a, T2 b) -> decltype(a+b) {
	return a + b;
}
// '->' - It is used when the return type depends on function parameters and is written after the function signature.

int main() {
	// auto a; this line will give error
	// because 'a' is not initialized at
	// the time of declaration
	// a=33;

	std::map<int, std::string>mpp = { {1,"one"},{2,"two"}};
	for (std::map<int, std::string>::iterator it = mpp.begin(); it != mpp.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	//rather than doing this we can simply do:-
	for (auto it = mpp.begin();it != mpp.end();it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}

	int newVar = 10;
	const int& ref = newVar;

	auto t = ref; //'t' is int, ignores 'const&'
	decltype(ref) u = newVar; //'u' is const int&, preserves exact type
	
	t = 10; //works because it's int
	//u = 10; //gives error -> 'const int&' ->  You cannot modify or rebind a const int& after initialization.

	Base* objPtr = new Derived();
	std::cout << typeid(*objPtr).name() << std::endl;
	decltype(objPtr) obj;




	//--------------------------------------------------------------

	std::cout << add(3.67, 4) << std::endl;


	const int a = 10;
	decltype(a) x = 1;
	std::cout << typeid(x).name() << std::endl;

	const int b = 11, &c = b;
	decltype(b) var = 12;
	/*decltype(c) var2;*/ //gives error since reference values must be initialized
	decltype(c) var2 = b;
	std::cout << typeid(var).name() << std::endl;
	std::cout << typeid(var2).name() << std::endl;

	int i;
	/*
	decltype((i)) d; //gives error - d must be initalized
	//decltype of a paranthesized variable is always a reference
	*/
	decltype(i) e; //no error



	/*
	Syntax of Range Based for Loop
		for (declaration : range) {
			// statements
		}
	 */

	std::vector<int> v = { 10, 20, 30 };
	for (auto& it : v) {  // Using reference
		it *= 10;  // Modify the actual element
	}
	for (auto it : v) {
		std::cout << it << " ";  // Prints: 100 200 300
	}
	// Using `auto it : v` creates a copy of each element, so modifications don't affect the original vector.
// To modify elements, use `auto& it : v` to iterate by reference.

	std::vector<int>v2 = { 1,2,3,4 };
	for (const auto it : v2) {
		std::cout << it << " ";
	}
}