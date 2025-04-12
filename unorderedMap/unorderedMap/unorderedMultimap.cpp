#include <iostream>
#include <unordered_map>
//std::unordered_multimap is an unordered associative container that supports equivalent keys(an unordered_multimap may contain multiple copies of each key value) and that associates values of another type with the keys.
// The unordered_multimap class supports forward iterators.
// Search, insertion, and removal have average constant - time complexity.

//Internally, the elements are not sorted in any particular order, but organized into buckets.
// Which bucket an element is placed into depends entirely on the hash of its key.
// This allows fast access to individual elements, since once the hash is computed, it refers to the exact bucket the element is placed into.

int main() {

	std::unordered_multimap<int, char>ummic = { {1,'a'},{3,'c'},{26,'z'}};

	// insertion
	ummic.insert({ 1,'a' }); // mulitmap takes duplicates
	ummic.insert(std::pair<int, char>(3, 'c'));
	ummic.insert(std::make_pair(5, 'e'));

	// emplace
	ummic.emplace(4, 'd'); // constructs in place

	// print
	/*for (auto& it : ummic) {
		std::cout << it.first << " " << it.second << "\n";
	}*/

	// find 
	auto result = ummic.find(2);
	std::cout << "2 there? : " <<
		(result == ummic.end() ? "no" : "yes") << std::endl;

	// lookup
//	std::cout << ummic.at(1) << "\n"; // multimap does not have this function
	std::cout << "is 1? : (0/1)" << ummic.contains(1) << "\n";

	// other APIs
	std::cout << "num of buckets: " << ummic.bucket_count() << "\n";
	std::cout << "bucket for 1: " << ummic.bucket(1) << "\n";
	std::cout << "size of bucket for 1: " << ummic.bucket_size(ummic.bucket(1)) << "\n";

	std::cout << "load factor: " << ummic.load_factor() << "\n";
	
	// check hash of a key
	auto hf = ummic.hash_function();
	std::cout << "hash of 1: " << hf(1) << std::endl;

	// check equality of two keys
	std::cout << "equal? : " << (ummic.key_eq())(11,10) << "\n";


	return 0;
}