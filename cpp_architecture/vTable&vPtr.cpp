#include <iostream>
using namespace std;

class Base {
public:
    // Virtual functions create a vtable entry for each function
    virtual void function1() {
        cout << "Base function1" << endl;
    }
    virtual void function2() {
        cout << "Base function2" << endl;
    }
    virtual void function3() {
        cout << "Base function3" << endl;
    }
};

class Derived1 : public Base {
public:
    // Overriding function1(), vtable now points to this function instead of Base::function1()
    void function1() override {
        cout << "Derived1 function1()" << endl;
    }
    // function2() and function3() are inherited as-is from Base
};

class Derived2 : public Derived1 {
public:
    // Overriding function2(), vtable updates function2() entry to Derived2::function2()
    void function2() override {
        cout << "Derived2 function2()" << endl;
    }
    // function1() is inherited from Derived1
    // function3() is inherited from Base
};

int main() {
    // Creating objects and storing them in Base* to observe vptr behavior
    Base* ptr1 = new Base;       // vptr -> Base_vtable
    Base* ptr2 = new Derived1;   // vptr -> Derived1_vtable
    Base* ptr3 = new Derived2;   // vptr -> Derived2_vtable
    
    // Base object calls its own functions (early binding, vptr -> Base_vtable)
    ptr1->function1(); // Calls Base::function1
    ptr1->function2(); // Calls Base::function2
    ptr1->function3(); // Calls Base::function3
    
    // Derived1 overrides function1(), but function2() & function3() remain from Base
    ptr2->function1(); // Calls Derived1::function1 (overridden)
    ptr2->function2(); // Calls Base::function2 (not overridden in Derived1)
    ptr2->function3(); // Calls Base::function3 (not overridden in Derived1)
    
    // Derived2 overrides function2(), inherits function1() from Derived1, and function3() from Base
    ptr3->function1(); // Calls Derived1::function1 (inherited)
    ptr3->function2(); // Calls Derived2::function2 (overridden in Derived2)
    ptr3->function3(); // Calls Base::function3 (inherited)
    
    return 0;
}
