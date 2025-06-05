#include <iostream>
#include <set>

struct node {
	int val;
	char ch;
	float fl;

	void print() const {
		std::cout << "val: " << val << " ch: " << ch << " fl: " << fl;
		printf("\n");
	}
};

struct comparator {
	bool operator()(const node& a, const node& b) const {
		return (a.val == b.val && a.ch == b.ch && a.fl == b.fl);
	}
};

int main() {
	// std::multiset is an associative container that contains a sorted set of objects of type Key. Unlike set, multiple keys with equivalent values are allowed.

	std::multiset<int>ms;
	ms.insert(5);
	ms.insert(10);
	ms.insert(2);
	ms.insert(10); // allowed in multiset

	/*for (auto& it : ms) {
		std::cout << it << " ";
	}*/

	std::cout << "size: " << ms.size() << " maxsize: " << ms.max_size() << "\n";

	// count and conatins
	/*std::cout << "is 10 there ? " << (ms.contains(10) ? "yes" : "no") << std::endl;
	std::cout << "count of 10 is " << ms.count(10) << "\n";*/

	// find
	/*std::multiset<int>::iterator itr = ms.find(10);
	if (itr != ms.end()) {
		std::cout << "element found!" << "\n";
	}
	else {
		std::cout << "element not found" << "\n";
	}*/

	/*ms.insert(12);
	ms.insert(15);
	for (auto& it : ms) {
		std::cout << it << " ";
	}*/
	std::cout << std::endl;
	//// upper and lower bound 
	//auto lb = ms.lower_bound(6);
	//auto ub = ms.upper_bound(13);
	//for (auto it = lb; it != ub; ++it) {
	//	std::cout << *it << " ";
	//}

	// deletion
	// multimap.erase(value) deletes instances of the value
	// to remove only one instance use erase(iterator)

	std::multiset<char>msc = { 'a', 'b', 'c', 'a', 'a', 'd','e','a','d'};
	std::cout << "initially: \n";
	for (auto& elem : msc) {
		std::cout << elem << " ";
	}
	std::cout << "\n";

	auto iter = msc.find('a'); 
	msc.erase(iter);
	// after erasing using iterator
	std::cout << ".erase(iter) \n";
	for (auto& elem : msc) {
		std::cout << elem << " ";
	}
	std::cout << "\n";

	// after erasing using value
	std::cout << ".erase(val) \n";
	msc.erase('a');  // erases all the 'a' 
	for (auto& elem : msc) {
		std::cout << elem << " ";
	}

	std::multiset<node, comparator>msn;
	msn.insert({26, 'z', 14.5});
	msn.insert({ 6, 'w', 4.45f });
	msn.insert({ 20, 's', 1.5f });
	msn.emplace(10, 's', 34.5);
	for (auto& it : msn) {
		it.print();
	}
	return 0;
}