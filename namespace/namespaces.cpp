#include <iostream>

//using namespace std;
/*
Avoid using-directives (such as using namespace std;) at the top of your program or in header files. They violate the reason why namespaces were added in the first place.
*/

/*
property:
Even though namespace functions have global scope, functions in the true global scope (outside any namespace) take precedence when called without qualification inside main().
*/

namespace myNamespace {
    int x = 10;  //allowed
    //x=8; //not allowed

    //std::cout << "cpp" << endl; //gives error - solution: wrap it inside a function.
    void print() {
        std::cout << "cpp" << std::endl; //std::cout means cout defined in the std namespace
    } //this works fine.
};

//int cout() { //defines our own "cout" function in the global namesapce
//    return 5;
//}

namespace apple {
    void display() {
        std::cout << "apple::hi" << std::endl;
    }
    /*void display() {
        std::cout << "hi" << std::endl;
    }*/ //will give an error 

    namespace iphone {
        void charge() {
            std::cout << "iphone charging" << std::endl;
        }
    }
}

namespace orange {
    void display() {
        std::cout << "orange::hi" << std::endl;
    }
}


namespace X {
    static int count = 1;
    void increment() {
        count++;
    }
}
/*
With static → count is limited to the current file (internal linkage).
Without static → count can be accessed across multiple files (external linkage).
*/


namespace P {
    namespace Q //Q -> member of P - fully defined within P
    { 
        class R { void s(); }; //class R - member of Q - fully defined wihtin Q
        //R::s is only declared
        void t();
    }
    void Q::t() //definition of Q's member t outside of Q
    {
        extern void u(); //this declares ::P::Q::u
    }
    void Q::R::s() //definition of Q::R::s() outside of namespace (and the class)

    { }
}
//===================================================================

namespace { //anonymous namespace
    int hidden = 10;
    void showw() {
        std::cout << "inside anonymous" << std::endl;
    }
}
/*
All members inside an anonymous namespace have internal linkage, meaning they are not accessible outside this file.
*/
void showw() {
    std::cout << "inside showw" << std::endl;
}

//===================================================================

namespace Math {
    class Calculator {
    public:
        static void add(int a, int b) {
            std::cout << "calc::sum is" << a + b << std::endl;
        }
    };
    void add(int a, int b) {
        std::cout << "add::sum is" << a + b << std::endl;
    }
};

using namespace Math;

int main()
{
    //cout << "hello world"; // -> compile error! which cout do we want here ?
    
    //------------------------------------------------------------------------------------------------------

    // display(); //error
    /*apple::display();
    orange::display();*/

    //------------------------------------------------------------------------------------------------------

    //we can also do
    /*namespace a = apple;
    a::display();*/

    //------------------------------------------------------------------------------------------------------

   /* using namespace apple;
    display();

    using namespace orange;
    display();*/
    //Namespace conflict: using namespace causes ambiguity if multiple namespaces have functions with the same name.

    apple::iphone::charge();
    namespace a = apple::iphone;
    a::charge();

    //------------------------------------------------------------------------------------------------------

    X::increment();
    X::increment();
    std::cout << X::count << std::endl;


    //------------------------------------------

    add(2, 3); 
    Calculator::add(2, 3); 


    ::showw();

    return 0;
}