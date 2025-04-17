//#include <iostream>
//#include <string> 
//#include <map>
//
//int main() {
//	// std::multimap is an associative container that contains a sorted list of key-value pairs, while permitting multiple entries with the same key.
//	std::multimap<int, std::string>mm;
//
//	// insertion
//	mm.insert({ 1,"sky" });
//	mm.insert({ 2,"book" });
//	mm.insert({ 1,"door" }); // duplicates are allowed
//
//	// printing the multimap using iterators
//	std::multimap<int, std::string>::iterator itr = mm.begin();
//	while (itr!=mm.end()) {
//		std::cout << "key: " << itr->first << " value: " << itr->second << "\n";
//		itr++;
//	}
//
//	/*
//	Q: How do iterators work in map and multimap if they're implemented using trees, not arrays?
//	- Iterators follow in-order traversal internally (Left → Root → Right).
//	- ++it moves to the next node in sorted key order.
//	- This makes tree-based containers behave like sorted sequences during iteration.
//	*/
//
//	// emmplace : constrcuts in-place
//	mm.emplace(2, "pin");
//	mm.emplace(4, "tin");
//
//	// count 
//	std::cout << "count of key:2 is = " << mm.count(2) << "\n";
//
//	// find
//	auto it = mm.find(1); // returns iterator to the first key found
//	if (it != mm.end()) {
//		std::cout << "key found! with key: " << it->first << " value: " << it->second << "\n";
//	}
//	else {
//		std::cout << "key not found!" << "\n";
//	}
//
//	// erase
//	mm.erase(4); // passing key O(log n)
//	auto e = mm.begin();
//	mm.erase(e); // passing iterator O(1)
//	
//	// important feature - equal_range()
//	std::multimap<int, char>mmic = { {2,'a'},{3,'a'},{2,'c'},{4,'c'}};
//	auto i = mmic.equal_range(2);
//
//	/*
//	equal_range(key) returns a pair of iterators:
//	first → points to the first occurrence of key
//	second → points to the iterator just after the last occurrence of key
//	*/
//
//	for (auto itr = i.first; itr != i.second;++itr) {
//		std::cout << "key: " << itr->first << " val: " << itr->second << "\n";
//	}
//	// helpful in getting all the values of a certain key in multimap!
//
//	return 0;
//}