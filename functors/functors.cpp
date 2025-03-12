#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//class Test {
//	int _val;
//public:
//	Test(int x=0) : _val(x) {
//
//	}
//
//	int operator() (int val) {
//		return _val * val;
//	}
//};

//example 2
//class Test {
//	int a;
//public:
//	Test(int a = 0) : a(a) {}
//
//	int operator() (int b, int c) {
//		return a + b + c;
//	}
//};

class IntComparator {
public:
	bool operator() (const int& a, const int& b) const {
		return a < b;
	}
};


class Employee {
public:
	string name;
	int age;
	int id_num;

	Employee(string s, int a, int id) : name(s), age(a), id_num(id) {}
};

struct CompareBy {
	const std::string SORT_FIELD;

	CompareBy(const std::string& sort_field = "name") : SORT_FIELD(sort_field) {
		/* validate sort_field */
	}

	bool operator() (const Employee& a, const Employee& b) {
		if (SORT_FIELD == "name") 
			return a.name < b.name;
		else if (SORT_FIELD == "age") 
			return a.age < b.age;
		else if (SORT_FIELD == "idnum") 
			return a.id_num < b.id_num;
	}
};

int main() {
	/*Test t(10);
	cout << t(2) << endl;
	cout << t(3) << endl;*/


	/*Test t(1);
	cout << "result1: " << t(2, 3) << endl;
	cout << "result1: " << t(5, 2) << endl;*/

	/*std::vector<int>items{ 4,3,1,2 };
	IntComparator obj;
	std::sort(items.begin(), items.end(), obj);
	
	for (auto it : items) {
		std::cout << it << " ";
	}*/
	//Functors are inlined by the compiler, unlike function pointers, making them faster.


	vector<Employee>employees = {
		{"sumit", 21, 1},
	{ "sparsh", 34, 4 },
	{ "ankit", 10, 0 }
	};
	
	CompareBy cmp("name");
	std::sort(employees.begin(), employees.end(), cmp);
	for (auto it : employees) {
		std::cout << it.name << " " << it.age << " " << it.id_num << std::endl;
	}
	return 0;
}

/*
problem: traditional functions does not maintain states, they don't have the concept. We pass the value and get the returned
value after some operations. (we can use static variables for that -> overhead)
solution: use functors, in functors i tis not required to use any static variables, they contain the state until they get destroyed.
*/