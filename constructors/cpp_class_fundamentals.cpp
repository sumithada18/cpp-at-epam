Notes: C++ Class Fundamentals - Constructors, Destructors, Copy Semantics
1. Constructors
● Purpose: A special member function automatically called when an object of a class is created. Its primary role is to initialize the object's data members and establish a valid, usable state.
● Object Construction Process:
 1. Memory Allocation: Raw memory is allocated for the object (stack or heap).
 2. Initialization: The constructor runs, assigning initial values to members and acquiring necessary resources.
   ○ An object is fully constructed and usable only after its constructor completes successfully.
● Compiler-Generated vs. Explicitly Defined:
  ○  If no constructors are user-defined, the compiler may generate a public default constructor.
  ○  If any constructor is user-defined, the compiler will not automatically generate a default constructor.
● Categories:
 ○ Default Constructor: Can be called with no arguments. (e.g., ClassName();)
 ○ Parameterized Constructor: Accepts arguments to initialize the object. (e.g., ClassName(int x);)
 ○ Copy Constructor: Initializes a new object as a copy of an existing object of the same type. (e.g., ClassName(const ClassName& other);)

2. Destructors
● Purpose: A special member function automatically called when an object is about to be destroyed. Its primary role is to clean up resources acquired by the object during its lifetime.
● Object Destruction Process:
 1. Cleanup: The destructor runs, releasing resources (e.g., heap memory via delete, closing files).
 2. Memory Deallocation: The memory occupied by the object itself is reclaimed.
● Compiler-Generated vs. Explicitly Defined:
 ○ If no destructor is user-defined, the compiler generates one. This generated destructor is often trivial but will call destructors of member objects.
 ○ Crucial: Explicitly define a destructor if the class manages resources like heap memory (allocated with new) to prevent resource leaks.
● Order of Destruction:
 ○ Destructors are called in the reverse order of construction.
 ○ Reason: Ensures dependencies are handled correctly. Objects created later (which might depend on objects created earlier) are destroyed first. For local stack objects, this is Last-In, First-Out (LIFO).

3. Copy Constructor & Copy Semantics
● Copy Constructor:
○ Signature: Typically ClassName(const ClassName& other).
 ○ Invoked When:
  1. Initializing an object from another of the same type: ClassName obj2 = obj1; or ClassName obj2(obj1);.
  2. Passing an object by value to a function.
  3. Returning an object by value from a function (often optimized away by RVO/NRVO).
● Compiler-Generated Copy Constructor:
 ○ If not explicitly defined, the compiler provides one.
 ○ Performs a member-wise copy: copies the value of each data member from the source to the new object.
 ○ For pointer members, this means copying the pointer's address, not the data it points to. This is a shallow copy.
● Shallow Copy:
 ○ Mechanism: Only member values are copied. If a member is a pointer, the memory address it holds is copied. Both original and copied objects' pointers now point to the same external resource (e.g., the same block of heap memory).
 ○ Problems:
   1. Dangling Pointers: If one object is destroyed and its destructor deletes the shared resource, the other object's pointer now dangles (points to invalid memory).
   2. Double Free: When the second object is destroyed, its destructor will attempt to delete the already-freed resource, leading to undefined behavior (often a crash).
   3. Unintended Side Effects: Modifying the shared resource through one object affects the other.
● Deep Copy:
 ○ Mechanism: For members managing external resources (like pointers to heap memory):
  1. Allocate new memory for the copied object's resource.
  2. Copy the contents of the original object's resource into this new memory.
 ○ Each object manages its own independent copy of the resource.
 ○ Achieved by: Explicitly defining a copy constructor (and usually a copy assignment operator, operator=).
 ○ Benefits: Prevents double-free errors and unintended data sharing. Each object has its own lifecycle for its resources.
 ○ Cost: Slower and uses more memory due to new allocations and data copying.

4. The Problem with Shallow Copy (Demonstrated)
● Problematic Code (Illustrating Shallow Copy Issue):
#include <iostream> // Only for demonstration of the problem, can be removed for pure logic

class Test {
public:
    int* ptr;
    Test() {
        ptr = new int(10);
        // std::cout << "Default constructor: ptr=" << ptr << " (*ptr=" << *ptr << ")\n";
    }
    ~Test() {
        // std::cout << "Destructor: ptr=" << ptr;
        // if(ptr) std::cout << " (*ptr=" << (ptr ? *ptr : 0) << ")\n"; else std::cout << "\n";
        delete ptr; // ptr is deleted
        ptr = nullptr;
    }
    // Compiler provides a default copy constructor (shallow copy)
    // Test(const Test& other) : ptr(other.ptr) {} // This is what compiler does
};

int main() {
    Test t1;
    Test t2 = t1; // Invokes compiler-generated copy constructor (shallow copy)
                  // t1.ptr and t2.ptr point to the SAME int on the heap.

    // When main ends:
    // 1. t2's destructor runs: delete t2.ptr (deletes the shared int).
    // 2. t1's destructor runs: delete t1.ptr (tries to delete the SAME int again - DOUBLE FREE!).
    return 0;
}

● Explanation of the Problem:
1. t1 is created; t1.ptr points to an int on the heap.
2. t2 is created as a copy of t1. The compiler-generated copy constructor makes t2.ptr = t1.ptr. Both now point to the same int.
3. When main ends, t2 is destructed first. Its destructor deletes the int via t2.ptr.
4. Then, t1 is destructed. Its destructor attempts to delete the same memory location via t1.ptr. This is a double free error, leading to undefined behavior.

5. Solution: Implementing a Deep Copy
● Corrected Code (with Deep Copy Constructor):
// #include <iostream> // Not strictly needed for the logic

class Test {
public:
    int* ptr;

    Test() {
        ptr = new int(10);
    }

    // User-defined Copy Constructor (Deep Copy)
    Test(const Test& other) {
        ptr = new int(*(other.ptr)); // Allocate new memory and copy the value
    }

    ~Test() {
        delete ptr;
        ptr = nullptr;
    }
    
    // For completeness, a copy assignment operator would also be needed for robust deep copy
    // Test& operator=(const Test& other) {
    //     if (this == &other) return *this; // Self-assignment check
    //     delete ptr; // Free existing resource
    //     ptr = new int(*(other.ptr)); // Allocate new and copy
    //     return *this;
    // }
};

int main() {
    Test t1;
    Test t2 = t1; // Invokes user-defined deep copy constructor.
                  // t1.ptr points to its own int.
                  // t2.ptr points to a *different*, newly allocated int with the same value.

    // Now, when destructors run, each deletes its own distinct memory block. No double free.
    return 0;
}

● Explanation of Solution:
 ○ The explicitly defined copy constructor Test(const Test& other) allocates new memory for ptr in the new object (t2).
 ○ It then copies the value from the memory other.ptr points to into this new memory.
 ○ Now, t1.ptr and t2.ptr point to different memory locations on the heap, each holding a copy of the original data.
 ○ Each object's destructor safely deletes its own managed memory.
