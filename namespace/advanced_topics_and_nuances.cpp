1. Nested Namespaces
You can put boxes inside other boxes. This is great for even finer organization.
  namespace my_app {
    namespace graphics {
        namespace low_level {
            void draw_pixel() { /* ... */ }
        }
        void draw_line() { /* ... */ }
    }
    namespace networking {
        void send_packet() { /* ... */ }
    }
}

// How to use them:
my_app::networking::send_packet();
my_app::graphics::low_level::draw_pixel();

// C++17 introduced a cleaner syntax for nesting:
namespace my_app::graphics::v2 {
    void draw_triangle() { /* ... */ }
}


2. Unnamed (Anonymous) Namespaces
This is a critical, advanced feature. What if you want to create a helper function or variable that is only
visible inside one specific .cpp file and nowhere else?

The old C way was to use the static keyword on global functions/variables. The modern C++ way is the 
anonymous namespace.

// in my_file.cpp

namespace {
    // Everything in here is private to this file.
    // It's like 'static' but for C++.
    int file_local_secret = 42;

    void helper_function() {
        std::cout << "I can only be called from my_file.cpp" << std::endl;
    }
} // The namespace has no name

void public_function() {
    // I can see the things in the anonymous namespace
    // because I'm in the same file.
    helper_function();
    std::cout << "The secret is: " << file_local_secret << std::endl;
}

You cannot access file_local_secret or helper_function from any other .cpp file. The compiler gives
them an internal, unique name that prevents linking errors. This is the preferred way to achieve 
internal linkage in C++.

3. Namespace Aliases
If you have a very long namespace name, you can give it a shorter alias.
namespace very_long_and_descriptive_name {
    void do_work() {}
}

int main() {
    // This is too long to type repeatedly
    very_long_and_descriptive_name::do_work();

    // Let's create a short alias
    namespace vldn = very_long_and_descriptive_name;

    // Much cleaner!
    vldn::do_work();
}
This is extremely common in large projects to improve readability without causing pollution.

4. Edge Case: Argument-Dependent Lookup (ADL) or Koenig Lookup
This is a subtle but important rule that makes C++ feel more intuitive.

Consider this:
std::cout << "Hello";

Wait a minute. << is just an operator function. The full name of that function is std::operator<<. 
So why don't we have to write this?

std::operator<<(std::cout, "Hello");

Because of ADL. The rule is: When you call a function with an unqualified name (like operator<<), the 
compiler doesn't just look in your current scope. It also looks inside the namespaces of the
function's arguments.

-> The compiler sees cout << "Hello".
-> It knows cout is of type std::ostream.
-> Because one of the arguments (cout) lives in the std namespace, the compiler also searches inside 
   the std namespace for a matching function named operator<<.
-> It finds std::operator<< and uses it.

This is what allows operator overloading and many other features to work so cleanly. It finds the 
right function based on the types you're using.
