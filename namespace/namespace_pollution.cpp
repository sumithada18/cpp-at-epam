// ============= The using Keyword: The Good, The Bad, and The Ugly ===============
The using keyword is a shortcut to avoid typing the namespace name and :: all the time. There are two ways to use it.

1. The using Declaration (The Good)
  This brings one specific name from the namespace into your current scope.
#include <iostream>
#include <string>

namespace string_stuff {
    std::string value = "Hello";
    void print(std::string s) { /* ... */ }
}

int main() {
    // I plan to use 'cout' and 'endl' a lot.
    // Let's bring just those two names into this function's scope.
    using std::cout;
    using std::endl;

    // I also plan to use the 'print' function from string_stuff
    using string_stuff::print;

    cout << "This works without std::" << endl;
    print("This works without string_stuff::");

    // But 'string' is not declared, so I still need the full name
    std::string my_name = "Alice";
    cout << my_name << endl;
}



2. The using Directive (The Bad and The Ugly)
 This dumps the entire contents of the namespace into your current scope.
#include <iostream>
#include <string>

// This is the line you're often told to avoid
using namespace std;

int main() {
    // I dumped the entire 'std' toolbox onto the floor.
    // Now I can use its names directly.
    cout << "Hello" << endl;
    string s = "World";
}


// ========= Namespace Pollution: Why using namespace is Dangerous =====================
Namespace Pollution is when you dump so many names into your global scope that you increase the chance of name collisions, often without realizing it.

  Let's look at a concrete example of how using namespace std; can break your code.
#include <iostream>

// Imagine this is some code you wrote a long time ago,
// or it comes from a library you're using.
int count = 100;

// Now, let's use the 'std' namespace
using namespace std;

int main() {
    // You want to print your global 'count' variable
    cout << count << endl; // AMBIGUITY ERROR!
}

This code will not compile. Why?
  
Because <iostream> (and other standard headers) has a function in the std namespace called std::count. 
When you wrote using namespace std;, you dumped std::count into the global scope. Now, when the 
compiler sees count, it gets confused. Does count refer to:
1. Your global integer variable ::count?
2. The standard library function std::count?

It can't decide, so it gives you an "ambiguity" error. You have polluted your own namespace.

This is ESPECIALLY DANGEROUS in header files (.h or .hpp). If you put using namespace std; at the 
top of a header file, every single file that includes your header will have the std namespace dumped
into it. You are forcing namespace pollution on everyone who uses your code, and you will almost
certainly break their code eventually.
  
Golden Rule: NEVER put using namespace ...; in a header file. It's acceptable (but still a bit lazy)
in your own .cpp files if you're sure there are no conflicts. The safest habit is to use std:: or using declarations.
