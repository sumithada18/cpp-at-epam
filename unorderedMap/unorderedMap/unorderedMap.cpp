//#include <iostream>
//#include <unordered_map>
//// std::unordered_map is an associative container that contains key - value pairs with unique keys.
//// Search, insertion, and removal of elements have average constant - time complexity.
//// Internally, the elements are not sorted in any particular order, but organized into buckets.
//// Which bucket an element is placed into depends entirely on the hash of its key.
//// Keys with the same hash code appear in the same bucket.This allows fast access to individual elements, since once the hash is computed, it refers to the bucket containing the element.
//
//int main() {
//
//	std::unordered_map<int, char>umap = { {1,'a'}, {2,'b'}, {1,'b'}}; 
//	// duplicates will be discarded
//
//	// other types of declarations
//	std::unordered_map<int, int>umii{ {1,1},{2,3},{2,4} };
//	std::unordered_map<int, int>umii2(umii); // copy constructor
//	std::unordered_map<int, int>umii3(std::move(umii)); // move constructor
//	// ... etc
//	
//	// access
//	std::cout << umap[1] << "\n";
//	std::cout << umap[2] << '\n';
//	
//	// update
//	umap[2] = 'c';
//
//	// iterate
//	for (auto& elem : umap) {
//		std::cout << elem.first << " " << elem.second << "\n";
//	}
//
//	// find 
//	auto result = umap.find(2);
//	std::cout << "2 there? : " <<
//		(result == umap.end() ? "no" : "yes") << std::endl;
//
//	// lookup
//	std::cout << umap.at(1) << "\n";
//	std::cout << "is 1? : (0/1)" << umap.contains(1) << "\n";
//
//	// other APIs
//	std::cout << "num of buckets: " << umap.bucket_count() << "\n";
//	std::cout << "bucket for 1: " << umap.bucket(1) << "\n";
//	std::cout << "size of bucket for 1: " << umap.bucket_size(umap.bucket(1)) << "\n";
//
//	std::cout << "load factor: " << umap.load_factor() << "\n";
//	
//	// check hash of a key
//	auto hf = umap.hash_function();
//	std::cout << "hash of 1: " << hf(1) << std::endl;
//
//	// check equality of two keys
//	std::cout << "equal? : " << (umap.key_eq())(11,10) << "\n";
//	
//	return 0;
//}