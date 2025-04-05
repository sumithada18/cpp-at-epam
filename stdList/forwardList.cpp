#include <iostream>
#include <forward_list>

template<typename T>
void print(std::forward_list<T>&flist) {
	for (auto& it : flist) {
		std::cout << it << " ";
	}
	std::cout << "\n";
}

int main() {
	// `std::forward_list` is** a STL container** for singly linked list.
	
	// different types of declaration of forward_list
	std::forward_list<int>flist1; // empty list;
	std::forward_list<int>flist2 = { 12,4,5,8,1 }; // initialization list
	std::forward_list<int>flist3{ 12,6,11,23 }; // uniform initialization
	std::forward_list<int>flist4(flist3); // copy constructor
	std::forward_list<int>flist5(std::move(flist2)); // move constructor
	std::forward_list<int>flist6 = flist3; // copy assignment operator
	std::forward_list<int>flist7 = std::move(flist4); // move assignment operator
	std::forward_list<int>flist8(5, 30); // 5 elements in list, all initialized with 30

	int n = 4;
	int arr[] = { 65,90,11,2 };
	std::forward_list<int>flist9(arr, arr + n);
	print(flist9);

	// insertion in the front and end
	flist3.push_front(7);

	auto itr = flist3.before_begin();
	for (auto it = flist3.begin(); it != flist3.end(); it++) {
		itr = it;
	}
	flist3.insert_after(itr, 29);

	std::cout << "after insertion from both ends: \n";
	// print(flist3);

	// insertion in the middle
	auto itr2 = flist3.begin();
	std::advance(itr2, 2); // moves itr2 to 2nd index
	flist3.insert_after(itr2, 88); // inserts just after 2nd index i.e 3rd
	print(flist3);

	// deletion from front
	flist3.pop_front();

	std::cout << "before deletion: " << "\n";
	print(flist3);
	// deletion from back
	auto i = flist3.begin();
	auto prev = flist3.before_begin();
	while (std::next(i)!=flist3.end()) {
		prev = i;
		i = std::next(i);
	}
	flist3.erase_after(prev);
	std::cout << "after deletion: " << "\n";
	print(flist3);


	// deletion in the middle
	std::forward_list<int>fl = {2,67,47,1};
	auto curr = fl.begin();
	auto pv = fl.before_begin();

	while (curr!=fl.end() && *curr!=47) {
		pv = curr;
		curr = std::next(curr);
	}
	fl.erase_after(pv);

	std::cout << "after deletion: " << "\n";
	print(fl);

	return 0;
}