//#include <iostream>
//#include <unordered_set>
//#include <functional>
//
///*
//template<
//    class Key,                            // Type of the element (like int, string)
//    class Hash = std::hash<Key>,          // How to hash the key (default: std::hash)
//    class KeyEqual = std::equal_to<Key>,  // How to check equality (default: ==)
//    class Allocator = std::allocator<Key> // How memory is managed (default: new/delete)
//> class unordered_set;
//*/
//
//class Student {
//public:
//    int id;
//    std::string name;
//
//    bool operator==(const Student& obj) const
//    {
//        return (this->id == obj.id && this->name == obj.name);
//    }
//
//    void print_student() const {
//        std::cout << "id= " << id << " name= " << name << "\n";
//    }
//};
//
//// custom hash function - for class Student
//struct studentHash {
//    size_t operator()(const Student& s) const {
//        return (std::hash<int>{}(s.id) + std::hash<std::string>{}(s.name));
//    }
//};
//
//
//int main() {
//    // unordered_set ?
//    // - container that stores unique elements just like set
//    // - no ordering of elements
//    // - uses hash table internally for fast operations
//
//    // each data type(like int, char, string) has its own hash funciton already defined inside the <functional> header
//    // these functions decide how to convert a value into a number(hash) so it can be placed in a hash table.
//
//    std::cout << "hash for 5: " << std::hash<int>{}(5) << "\n";
//    std::cout << "hash for c: " << std::hash<char>{}('c') << "\n";
//    std::cout << "hash for sumit: " << std::hash<std::string>{}("sumit") << "\n";
//
//
//    // different tyes of declarations
//    std::unordered_set<int>us; // empty one
//    std::unordered_set<int>us2 = { 12,4,2,12,3 }; // initializer list
//    std::cout << "us2: ";
////    for (auto& it : us2) std::cout << it << " ";
//    std::cout << "\n";
//
//    std::unordered_set<int>us3{23,5,22,4,6,23}; // universal initialization
//    std::cout << "us3: ";
////    for (auto& it : us3) std::cout << it << " ";
//    std::cout << "\n";
//
//
//    std::unordered_set<int>us4(us3); // copy constrcutor
//    std::unordered_set<int>us5 = us3; // copy assignment operator
//
//    std::unordered_set<int>us6(std::move(us2)); // move constructor
//    std::cout << "size of us6(moved in): " << us6.size() << ", size of us2(moved from): " << us2.size() << "\n";
//
//    // insertion : O(1)
//    std::unordered_set<int>usi;
//    usi.insert(18); 
//    usi.insert(45);
//    usi.insert(7);
//
//
//
//    // Lookup - 3 ways
////    std::cout << "45 there? :" << ((usi.count(45) >= 1) ? "yes" : "no") << "\n";
//    // .count(elem) returns count of elem 
//
////    std::cout << "18 there? (1/0): " << (usi.find(18)==usi.end()) << std::endl;
//    // .find(key) returns iterator - if found then iterator to the key, if not then to .end()
//
////    std::cout << "7 there? (0/1): " << usi.contains(7) << std::endl;
//    // .contains(key) is c++20 feature and returns boolean value
//
//    // Lookup TC: Average = O(1) and Worst = O(n) - when collsions are there!
//
//
//    // printing the un_set using iterators
//    std::unordered_set<int>::iterator itr = usi.begin();
//    while (itr != usi.end()) {
//        std::cout << *itr << " ";
//        itr++;
//    }
//    std::cout << "\n";
//
//    // miscellaneous member functions
//    std::cout << "num. of buckets: " << usi.bucket_count() << std::endl; // returns how many buckets 
//    std::cout << "load factor: " << usi.load_factor() << std::endl; // retuns average number of elements per bucket
//    //high load factor = more collisions = slower performance
//
//
//    /*
//    - To store user-defined objects in an unordered_set, we must tell C++ how to compare objects and how to hash them.
//    - For that, we overload the == operator and create a custom hash functor (struct with operator()), marked as const.
//    */
//    std::unordered_set<Student, studentHash>uss = { {10, "sumit"},{20, "hada"}};
//    // printing objects
//    for (auto& itr : uss) {
//        itr.print_student();
//    }
//
//    return 0;
//}