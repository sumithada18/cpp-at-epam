#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(int a) {
	a = 10;
}

int main() {
	//int a = 5;
	//func(a);
	////auto lambda = [a]() {a = 10; cout << "inside lambda" << endl; };
	////above line gives error, why? lambda caoture variables 'by value' as const by default to ensure safety

	////use mutable
	//auto lambda = [a]() mutable {a = 10; cout << "inside lambda" << endl; };

	//lambda();

	//int x = 5;
	//auto fun = [](int x) -> int {return x * x * 3.12323;};
	//cout << fun(x) << endl;


	//vector<int>vec = { 12, 3, 1, 44, 2 };
	//sort(vec.begin(), vec.end(), [](int a, int b) {
	//	return a < b;
	//	});
	//for (auto elem : vec) {
	//	cout << elem;
	//}

	////lambda as a predicate to an STL algorithm
	//std::vector<int>array{2, 4, 21, 0, 10, 6};
	//std::cout << endl;
	//auto n_even = std::count_if(array.begin(), array.end(),
	//	[](int n) {
	//		return (n % 2 == 0);
	//	}
	//	);
	//cout << "the array has " << n_even << " even elements. \n";


	vector<string> stringVec(10);
	cout << "\n capture by reference \n";
	[&stringVec]() {
		cout << "size in lambda: " << stringVec.size() << endl;
		}();
	
	cout << "after lambda, size in main: " << stringVec.size();

	cout << "\n capture by move \n";
	[vec_string = move(stringVec)]() {
		cout << "size in lambda: " << vec_string.size() << endl;
		}();
	cout << "after lambda, size in main: " << stringVec.size();

	return 0;
}

/*
// Lambdas are internally implemented as compiler-generated functors (classes with overloaded operator()).

auto lambda = [](int x) { return x * 2; };
lambda(5); // Calls the lambda like a function

Equivalent Functor (what the compiler does internally):-
struct Functor {
    int operator()(int x) const { return x * 2; }
};

-> lambda's capture list becomes the member variables of the generated functor class, and the lambda's body is the implementation of the operator() method.
-> a lambda is said to hold a state only if capture '[]' is used
*/
