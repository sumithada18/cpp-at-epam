A Comprehensive Guide to C++ Exception Handling

Exception handling is a C++ mechanism for responding to runtime anomalies or errors. It provides a structured way to transfer control from the point of an error to a dedicated handler, separating error-handling code from the main logic of a program. This makes code cleaner, more robust, and easier to maintain than traditional error-handling techniques like return codes.

1. The Core Mechanics: try, throw, and catch

At its heart, exception handling revolves around three keywords:

-> try: A try block encloses a section of code that might cause an error. It essentially says, "Try to execute 
   this code, but be prepared for something to go wrong."
-> throw: When an error occurs within the try block, the program can signal it by "throwing" an exception. 
   The throw statement is similar to a return statement, but instead of returning a value to the immediate 
   caller, it transfers control to the nearest exception handler.
-> catch: A catch block is the exception handler. It immediately follows a try block and specifies the 
   type of exception it can "catch." If an exception thrown within the try block matches the type specified by a 
   catch block, that block is executed.

A Basic Example:

#include <iostream>
#include <stdexcept> // Required for std::runtime_error

double divide(int numerator, int denominator) {
    if (denominator == 0) {
        // Signal an exceptional situation
        throw std::runtime_error("Division by zero error!");
    }
    return static_cast<double>(numerator) / denominator;
}

int main() {
    try {
        // The "guarded" block where an exception might occur
        std::cout << "Trying to divide 10 by 2..." << std::endl;
        double result1 = divide(10, 2);
        std::cout << "Result: " << result1 << std::endl;

        std::cout << "\nTrying to divide 10 by 0..." << std::endl;
        double result2 = divide(10, 0); // This line will throw
        std::cout << "Result: " << result2 << std::endl; // This line will never be reached

    } catch (const std::runtime_error& e) {
        // The handler for the specific exception type
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << "\nProgram continues after handling the exception." << std::endl;
    return 0;
}
When you run this code, the call to divide(10, 0) throws an exception. Normal program flow is immediately
suspended, and the runtime looks for a matching catch block. It finds one, executes it, and then the 
program continues from after the try-catch structure.


2. The Exception Object: A Hierarchy of Errors

Is an exception a class? Yes. While you can technically throw almost anything (like an int or a const char*), 
this is highly discouraged because it loses crucial information about the error.

The C++ standard library provides a hierarchy of exception classes in the <exception> and <stdexcept> 
headers. The base class for all standard exceptions is std::exception.

Best Practice: Always throw objects of a class that inherits (directly or indirectly) from std::exception.

The base std::exception class provides a key virtual function:

-> virtual const char* what() const noexcept;
  - This function returns a C-style string describing the general nature of the error. Derived classes
    override it to provide more specific messages.

Standard Exception Types:
The standard exceptions are broadly divided into two categories, both inheriting from std::exception:

1. std::logic_error: Represents errors in program logic that, in theory, could be detected before runtime. These
   are violations of preconditions.
  - std::invalid_argument: e.g., passing a non-numeric string to a function that expects a number.
  - std::domain_error: e.g., passing a negative number to a function that requires a non-negative one (like sqrt).
  - std::out_of_range: e.g., accessing an element outside the bounds of a std::vector using the .at() method.

2. std::runtime_error: Represents errors that can only be detected at runtime, often due to external factors.
  - std::overflow_error: An arithmetic overflow occurred.
  - std::underflow_error: An arithmetic underflow occurred.
  - std::range_error: A result could not be represented (e.g., in a calculation).
  - std::bad_alloc: Thrown by new when it fails to allocate memory. Found in the <new> header.

When to expect which one?

- Use a logic_error derivative when a function's caller violates its contract (e.g., passing bad arguments).
- Use a runtime_error derivative when something outside the program's direct control fails (e.g., a file 
  can't be opened, memory allocation fails, a network connection drops).

3. Stack Unwinding: The Journey of an Exception

When a throw statement is executed, the magic of stack unwinding begins. This is the process of the C++ 
runtime searching for a handler by moving backward up the call stack.

How does it actually happen?

Imagine the call stack as a stack of books, where each book is a function call (main calls funcA, funcA calls funcB, etc.).

1. The Throw: A function deep in the call stack, say funcC, executes throw.
2. Immediate Halt: The normal execution of funcC stops instantly.
3. Destruction of Local Objects: The runtime begins to exit funcC. As it does, it destroys all fully 
   constructed local objects within funcC's scope. This is a critical feature and the foundation of 
   the RAII (Resource Acquisition Is Initialization) idiom.
4. Moving Up the Stack: Control is then passed to the point where funcC was called, inside its caller 
   funcB. The runtime checks if this call site is within a try block.
5. Repeat or Catch:
  - If not in a try block, the unwinding process continues. All of funcB's local objects are destroyed, 
    and control moves to its caller, funcA.
  - If yes, the runtime checks the catch blocks associated with that try. If a catch block's type matches
    the thrown exception, the unwinding stops. Control is transferred to that catch block.

How does the callee reach the caller? The runtime system manages the call stack and keeps track of the 
return address for every function call. During unwinding, it uses this information to walk backward 
from the current function to its caller, and so on, until it finds a suitable try-catch block.

If the unwinding process reaches the top of the stack (main) without finding a matching catch block, 
the program is terminated by calling std::terminate().

The Power of RAII and Stack Unwinding:
Stack unwinding automatically cleans up resources as long as they are managed by objects with 
destructors (like std::vector, std::unique_ptr, std::ifstream, std::lock_guard). You don't need catch
blocks for cleanup; you only need them to handle the error.

void processFile(const std::string& filename) {
    std::ifstream file(filename); // RAII: file handle is acquired
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    // ... process the file ...
} // `file` object goes out of scope here. Its destructor is called,
  // automatically closing the file, whether the function exits
  // normally or via an exception.



4. Catching Exceptions: Precision and Best Practices

You can have multiple catch blocks to handle different types of exceptions. They are checked in the order 
they appear, and the first one that matches the exception type is executed.

cpp code: 
try {
    // some code that might throw different exceptions
} catch (const std::out_of_range& e) {
    // Handle out_of_range specifically
} catch (const std::runtime_error& e) {
    // Handle any other runtime_error (but not out_of_range, as it was caught above)
} catch (const std::exception& e) {
    // Handle any other standard exception
}
Important: Order matters. You should always catch more specific, derived exception types before their 
base types. If you put catch (const std::exception& e) first, it would catch everything, and the more specific handlers would never be reached.

You can catch an exception in three ways, but one is strongly preferred.

-> catch (MyException e): Catch by value. This works, but it's inefficient as it creates a copy. More
   importantly, it can lead to object slicing. If a derived exception is thrown, it gets "sliced" down 
   to the base type e, losing all its specific information.
-> catch (MyException* e): Catch by pointer. This avoids slicing but introduces messy ownership semantics.
   Who is responsible for deleteing the pointer? Avoid this.
-> catch (const MyException& e): Catch by const reference. This is the best practice.
  - It's efficient (no copy).
  - It avoids slicing, preserving the original exception object's type.
  - It's const, so you can't accidentally modify the exception object.

The ellipsis ... acts as a wildcard and will catch any exception, regardless of its type.

cpp code: 
try {
    // ...
} catch (...) {
    // Something was thrown, but we have no idea what it was.
    // Cannot access the exception object.
}
When to use it: Use catch(...) sparingly. It's a tool of last resort, typically used at the highest level of 
an application (e.g., in main or a thread's main function) to log that an unknown error occurred and 
terminate gracefully, or to clean up a critical resource before rethrowing.


5. Advanced Topics
Sometimes a catch block can only partially handle an error. For example, it might log the error before 
passing it on to a higher-level handler that knows how to recover. To rethrow the current, active 
exception, use the throw keyword with no operand.

cpp code:
void intermediate_function() {
    try {
        // ... call a function that might throw ...
    } catch (const std::exception& e) {
        log_error("Error occurred: " + std::string(e.what()));
        throw; // Rethrow the original exception object.
               // The slicing problem is avoided.
    }
}
Important: Do not do this: throw e;. If e is a sliced base class reference, this will throw a new 
exception that is a copy of that sliced object, losing the original derived type. throw; preserves the original exception.

The noexcept specifier is a promise to the compiler that a function will not throw any exceptions.

void does_not_throw() noexcept;

If a noexcept function does emit an exception (either directly or from a function it calls that 
isn't noexcept), the program is terminated immediately via std::terminate. There is no stack unwinding.

Why use noexcept?

-> Performance: It allows the compiler to perform significant optimizations, as it doesn't need 
   to generate cleanup code for stack unwinding.
-> Clarity: It's a clear contract to the caller.
-> Essential for some operations: Move constructors and move assignment operators should almost 
   always be noexcept to allow standard library containers to use them for strong exception guarantees.

-> Constructors: If a constructor throws, the object's creation is considered to have failed. 
   Its memory is deallocated, and its destructor will not be called because the object never fully 
   existed. However, the destructors of any fully constructed base classes or member variables will be 
   called. This is another reason why RAII is essential for member variables.

-> Destructors: NEVER LET AN EXCEPTION ESCAPE A DESTRUCTOR.
- A destructor might be called as part of stack unwinding for another, active exception. If that destructor 
  then throws its own exception, you have two simultaneous exceptions, which C++ cannot handle. The result 
  is an immediate call to std::terminate.
- If an operation inside a destructor might fail, wrap it in a try-catch(...) block and handle it locally 
   (e.g., log the error).
