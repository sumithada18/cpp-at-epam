//#include <iostream>
//#include <set>
//
//template<typename T>
//void printSet(std::set<T>&st) {
//	for (auto& it : st) {
//		std::cout << it << " ";
//	}
//	std::cout << "\n";
//}
//
//int main() {
//	// std::set is an associative container that contains a sorted set of unique objects of type Key.
//
//	// type of declarations
//	std::set<int>st; // empty set
//	std::set<int>set1 = { 12,34,56,67 }; // initializer list
//	std::set<int>set2(set1);  // copy cons..
//	std::set<int>set3(set2.begin(), set2.end()); // range cons..
//	std::set<int, std::greater<int>> set4;
//
//	// insertion:
//	st.insert(10);
//	st.insert(20);
//
////	printSet(st);
//
//	// tryin to insert duplicates - set won't take
//	st.insert(10);
//	st.insert(20);
//
////	printSet(st);
//
//	// finding in set (set1)
//	auto itr = set1.find(56);
//	if (itr != set1.end()) {
//		std::cout << "value found!" << '\n';
//	}
//	else {
//		std::cout << "value not found!" << '\n';
//	}
//	// cross checking it using 'count()' and 'contains()'
//	std::cout << "value count: " << set1.count(56) << "\n";
//	std::cout << "value present? " << (set1.contains(56) ? "yes" : "no") << "\n";
//
//	set1.erase(itr);
//	// we can also pass the value to be deleted directly 
//
//	std::cout << "after erasing: \n";
////	printSet(set1);
//	std::cout << "value count: " << set1.count(56) << "\n";
//	std::cout << "value present? " << (set1.contains(56) ? "yes" : "no") << "\n";
//
//	// other imp member functions:
//	std::set<int>nums = {12, 13,23, 44, 55, 78,89};
//	auto lower = nums.lower_bound(14);
//	auto upper = nums.upper_bound(45);
//	for (auto it = lower; it != upper;it++) {
//		std::cout << *it << " ";
//	}
//	std::cout << "\n";
//
//	nums.erase(lower, upper); // erasing from lower to upper!
//	printSet(nums);
//
//
//	std::set<int>nums2{ 12, 66, 27, 9, 4 };
//	nums2.merge(nums);
//	std::cout << "nums: "; printSet(nums);
//	std::cout << "nums2: "; printSet(nums2);
//	// duplicates won't be merged. ex: 12 stays in the 'nums' even after the merge() happened
//
//	// printing the set in reverse
//	auto rb = nums2.rbegin();
//	auto re = nums2.rend();
//	for (auto i = rb;i != re;++i) {
//		std::cout << *i << " ";
//	}
//
//	return 0;
//}