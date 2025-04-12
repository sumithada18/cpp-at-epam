#include <iostream>
#include <functional>
#include <unordered_set>

template<typename T>
void print(std::unordered_multiset<T>&ums) {
	for (auto& it: ums) {
		std::cout << it << " ";
	}
	std::cout << "\n";
}

class Employee {
public:
	int id;
	std::string name;

	bool operator==(const Employee& e) const
	{
		return (this->id == e.id && this->name == e.name);
	}

	void printVal() const
	{
		std::cout << "id: " << id << " name: " << name << "\n";
	}
};

struct hashEmployee {
	size_t operator()(const Employee& e) const
	{
		return (std::hash<int>{}(e.id) + std::hash<std::string>{}(e.name));
	}
};

int main() {

	// unordered_multiset ?
	// std::unordered_multiset is an associative container that contains set of possibly non-unique objects of type Key. 
	// Search, insertion, and removal have average constant-time complexity.

	// declerations
	std::unordered_multiset<int>ums; // empty 
	std::unordered_multiset<int>ums2{23,4,5,23}; // universal initialzation
	std::unordered_multiset<int>ums3 = {44,7,9,88}; // initializer list
	// ... 


	// insertion
	ums.insert(18);
	ums.insert(10);
	ums.insert(99);

	std::vector<int>vec = { 10,45,18 };
	ums.insert(vec.begin(), vec.end());
	//ums.insert(8, 10);

	// prinitng
	print(ums);

	// deletion
	ums.erase(10); 
	// erase(key) - erases all the instances of the key ( all the 10's are erased )

	std::cout << "after deleting 10: \n";
	print(ums);


	// finding an element
	std::unordered_multiset<int>::iterator itr = ums.find(18);
	std::cout << "before deleting 18: ";
	print(ums);

	ums.erase(itr);
	// erase(iterator) - erases only that instance which iter. is pointing to!

	std::cout << "after deleting 18: ";
	print(ums);

	ums.insert(10);
	ums.insert(45);

	// lookup APIs
	std::cout << "is 10 present? (0/1): " << ums.contains(10) << std::endl; // returns true/false
	std::cout << "no. of 45: " << ums.count(45) << std::endl;
	// using find
	std::cout << "18 there? : " << (ums.find(18) != ums.end()) << std::endl;

	ums.insert(45);
	auto i = ums.equal_range(45); // returns range of elements matching a specific key
	for (auto it = i.first; it != i.second; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	for (auto& iter : ums) {
		std::cout << "bucket for " << iter << " : " << ums.bucket(iter) << "\n";
	}

	// for user-defined objects
	std::unordered_multiset<Employee, hashEmployee>ume = { {10,"sumit"},{12,"lalit"},{10,"sumit"}};
	for (auto& it : ume) {
		it.printVal();
	}
	
	return 0;
}