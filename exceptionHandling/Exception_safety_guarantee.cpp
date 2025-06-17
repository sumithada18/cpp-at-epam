No - throw guarantee
The Nothrow Guarantee is a contract I make with the compiler, specified using noexcept.
By using it, I promise that my function will not allow an exception to escape its scope. In return, the compiler can perform significant optimizations.
If my function breaks this promise and an exception does escape, the program is immediately terminated via std::terminate() as a penalty.

How to Achieve It:
You explicitly mark the function with the noexcept specifier.
This is suitable for simple operations that cannot fail, such as moving data (which should be noexcept for performance), 
swapping pointers, or operations on fundamental types. Destructors must also adhere to this guarantee.

void swap(MyClass& a, MyClass& b) noexcept {
    using std::swap;
    swap(a.ptr, b.ptr);
    swap(a.size, b.size);
}



2. The Strong Exception Safety Guarantee (Commit-or-Rollback)
The Strong Exception Guarantee is a powerful promise a function makes about the program's state in case of an error.

The Core Promise: 
If a function fails by throwing an exception, it guarantees that the program's state is rolled back to exactly 
what it was before the function was called.

Think of it as an atomic transaction: the operation either succeeds completely, or it fails completely, leaving 
no partial or messy side effects.

The Goal: Why Do We Need It?
The primary goal is to maintain data consistency. It's essential for any operation where a partial change would
leave an object in a corrupted or invalid state. You want to prevent situations like, "I was trying to update this
user profile, but it failed halfway through, and now the name is new but the email is old."

The "How-To": The Copy-and-Swap Idiom
The most common and effective way to achieve the Strong Guarantee is with a technique called the Copy-and-Swap 
Idiom. It works in three simple steps:
1. Prepare: Create a temporary copy of the data you intend to modify.
2. Work: Perform all potentially-throwing operations on this temporary copy. This is the "danger zone." 
   If an exception is thrown here, the original object is completely unaffected and remains safe.
3. Commit: Once all the work on the temporary copy is successful, swap the state of the original object with the 
   state of the temporary one. This final swap step must be a non-throwing (noexcept) operation.

Example:
void pushStrong(std::vector<std::string>& vec, const std::string& item) {
    std::vector<std::string> temp = vec;   // makes a full copy
    temp.push_back(item);                  // may throw, but won't affect original
    vec = std::move(temp);                 // safe move if above succeeded
}
Yes, your example is excellent. It's simple, clear, and perfectly demonstrates the Strong Guarantee. It's a much better example for a quick interview explanation.

Here is how you should explain it:

"This function provides the Strong Guarantee using a simple 'copy, work, commit' strategy:
1. Copy: std::vector<std::string> temp = vec; creates a full, safe copy. If this fails (e.g., out of memory), 
   the original vec is completely untouched.
2. Work: temp.push_back(item); performs the risky operation on the copy. If push_back throws, again, the original
   vec is still safe and unchanged.
3. Commit: vec = std::move(temp); is the final step. The move-assignment for std::vector is a non-throwing operation.
   It atomically updates the original vec with the new state.
The operation either succeeds completely, or it fails leaving the original vector exactly as it was. It's a perfect
illustration of commit-or-rollback."



The Basic Exception Safety Guarantee

The Basic Exception Guarantee is the minimum requirement for any well-written C++ function. It's the foundation
of robust code.

The Core Promise:
If a function fails by throwing an exception, it guarantees two things:
1. No resources are leaked. (e.g., no memory leaks, no dangling file handles, no unreleased locks).
2. The program is left in a valid state. This means all objects are still internally consistent and usable.
   Their internal rules (invariants) still hold.

The crucial part is that the state, while valid, might be different from what it was before the function was 
called. You can safely continue using the program, but you may not know the exact value of the data that was being modified.

The Goal: Why Is It the Minimum?
The goal is to prevent program corruption. Without this guarantee, a simple exception could leak memory or corrupt data,
leading to unpredictable crashes later on. Adhering to the Basic Guarantee ensures that your program remains stable 
even when errors occur.

#include <vector>
#include <iostream>

// This function provides the Basic Guarantee.
void addTwoElements(std::vector<int>& vec) {
    vec.push_back(100); // This could throw std::bad_alloc
    
    // Imagine this is a more complex operation that could also fail
    vec.push_back(200); // This could also throw std::bad_alloc
}

int main() {
    std::vector<int> my_vec = {1, 2};
    try {
        addTwoElements(my_vec);
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occurred! " << e.what() << std::endl;
    }

    // IMPORTANT: Even after an exception, 'my_vec' is still a valid vector.
    // It might contain {1, 2, 100} if the second push_back failed.
    // Its state changed, but it's not corrupted.
    std::cout << "Vector is still valid. Its size is: " << my_vec.size() << std::endl;
    return 0;
}

The problem is that the function makes two separate changes.
If the first push_back(100) succeeds but the second push_back(200) fails, the vector is left in 
a partially modified state.
This fulfills the Basic Guarantee (it's valid, no leaks) but breaks the Strong Guarantee because 
the vector wasn't rolled back to its original state.
