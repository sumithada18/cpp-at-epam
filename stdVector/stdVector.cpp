#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

// Write a function that takes two parameters: a std::vector and an index. If the index is out of bounds, print an error. If the index is in bounds, print the value of the element.
template<typename T>
void printElement(std::vector<T>&vec, int i) {
    if (i < 0 || i >= vec.size()) {
        std::cout << "Invalid index" << std::endl;
    }
    else {
        std::cout << "Valid index" << std::endl;
    }
}


class myClass {
public:
    myClass() {
        std::cout << "def cons..." << "\n";
    }
    myClass(int x) {
        std::cout << "cons. called with value: " << x << "\n";
    }
    myClass(const myClass& obj) {
        std::cout << "copy cons.." << "\n";
    }
    myClass(myClass&& obj) noexcept {
        std::cout << "move cons.." << "\n";
    }
};

class Demo {
public:
    int val;
    Demo(){
        std::cout << "default cons..\n";
    }
    Demo(int x) : val(x) {
        std::cout << "cons. called with value: " << x << "\n";
    }
    Demo(const Demo& obj) {
        std::cout << "copy cons.." << "\n";
    }
    Demo(Demo&& obj) noexcept {
        std::cout << "move cons.." << "\n";
    }
};

int main()
{
    /*
    std::vector<int>v1{ 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector<double>v2{ 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);


    // iterators and vector
    std::vector<int>nums = { 1,13, 34, 4, 29 };
    std::vector<char>charArr = { 'f','u','k','c' };
    // printing vector
    std::vector<char>::iterator it;
    for (it = charArr.begin(); it != charArr.end(); it++) {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    // printing vector
    std::for_each(nums.begin(), nums.end(), 
        [](const int i) {
            std::cout << i << " ";
        }
        );
    // begin() -> mutable iterator
    // cbegin() -> immutable iterator
    */


    // shrink_to_fit() ?
    /*
    std::vector<int>integers;
    std::cout << "1 integers capacity: " << integers.capacity() << std::endl;
    integers.push_back(10);
    integers.push_back(12);
    std::cout << "2 integers capacity: " << integers.capacity() << std::endl;
    integers.push_back(1);
    integers.push_back(18);
    integers.push_back(15);
    std::cout << "3 integers capacity: " << integers.capacity() << std::endl;
    integers.shrink_to_fit();
    std::cout << "4 integers capacity: " << integers.capacity() << std::endl;
    */


    std::vector<std::string>v;
    v.push_back("hello"); // "hello" is a temporary value (rvalue), so move semantics (move constructor) would be invoked - moving the temporary object directly in vector's storage

    std::string str = "Hello";
    v.push_back(str); // str is an lvalue, so the copy constructor of the vector class would be invoked

    //std::vector<myClass>vec;
    //vec.reserve(5);
    //vec.push_back(myClass());
    //vec.emplace_back(myClass());

    //std::vector<myClass>myVec;
    //myVec.reserve(5);
    //myVec.push_back(10); // temporary object is created first, then copied/moved into the vector
    //myVec.emplace_back(20); // constructs in-place inside vector


    /*
    If you pass an existing object (lvalue), both push_back and emplace_back will perform a copy (or a move if the object is movable).

    If you pass an rvalue (like a temporary object), both will perform a move (if move semantics are supported).

    The key benefit of emplace_back is when you pass constructor arguments directly, as it constructs the object in place, avoiding extra moves or copies.
    */
    //let's understand with an example:
    
    std::vector<Demo>demoVec;
    demoVec.reserve(20);

    // passing a lvalue:
    std::cout << "passing a lvalue:" << "\n";
    Demo d(10);
    demoVec.push_back(d);
    demoVec.emplace_back(d);
    std::cout << std::endl;

    // passing a rvalue :
    std::cout << "passing a rvalue:" << "\n";
    demoVec.push_back(Demo(10));
    demoVec.emplace_back(Demo(10));
    std::cout << std::endl;

    // passing the constructor argument directly:
    std::cout << "passing constructor argument directly" << "\n";
    demoVec.push_back(34);
    demoVec.emplace_back(31);

    // emplace back even works with the classes that requires no arguements
    // just do :
    demoVec.emplace_back();
    // Directly constructs the Demo object in place inside the vector 
    // using its default constructor. No separate temporary object is created and then moved/copied.


    // invalidation of iterators in std::vector
    std::vector<int>intVec;
    intVec.reserve(2);
    intVec.push_back(10);
    auto it = intVec.begin();
    std::cout << *it << "\n"; // successfuly prints first value of vector i.e 10

    // forcing resizing of vector:
    intVec.push_back(30);
    intVec.push_back(20); // vector resizes here

    // accessing the iterator now:
    //std::cout << *it << "\n"; // crash!!! - The vector has resized, and the iterator is invalidated 
    

    // NOTE: Vector resizing invalidates all iterators, pointers, and references.

    return 0;
}
