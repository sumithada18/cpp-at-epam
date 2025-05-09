#include <iostream>
#include <memory>
using namespace std;

int main()
{
    /*
    shared_ptr<int>p1(new int(10));
    shared_ptr<int>p2;
    p2=p1;
    
    cout << "no. of reference of p1: " << p1.use_count() << endl;
    cout << "no. of reference of p2: " << p2.use_count() << endl;
    
    cout << "address stored by p1: " << p1.get() << endl;
    cout << "address stored by p2: " << p2.get() << endl;
    
    p1.reset();
    
    cout << "no. of reference of p1: " << p1.use_count() << endl;
    cout << "no. of reference of p2: " << p2.use_count() << endl;
    
    cout << "address stored by p1: " << p1.get() << endl;
    cout << "address stored by p2: " << p2.get() << endl;
    */
    
    //==========================================================================
    
    
    //shared_ptr<int>p1(new int(100));
    //weak_ptr<int>p2 = p1;
    //cout << *p1 << " " << *(p2.lock()) << endl; //we can't derefeence a weak_ptr direstly, we must use .lock() which converts it inot a shared_ptr
    
    /*
    case1: we do p1.reset()
    
    p1.reset();
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    */
    
    /*
    case2: we do p2.reset()
    
    cout << p2.use_count() << endl;
    cout << p2.use_count() << endl;
    
    */
    
    //conslusion: If we reset a shared_ptr, 
    //the weak_ptr loses access to the resource, but resetting a weak_ptr does not affect the shared_ptr or the resource.
    
    
    //==========================================================================
    
    //Note: .lock() temporarily increases the reference count since it converts the weak_ptr into a shared_ptr. example code:  
    auto sharedPtr = make_shared<int>(10);
    weak_ptr<int> weakPtr(sharedPtr);

    cout << "Before lock(): " << sharedPtr.use_count() << endl; // Output: 1

    if (auto tempPtr = weakPtr.lock()) { // Creates a new shared_ptr
    cout << "Inside lock(): " << tempPtr.use_count() << endl; // Output: 2
    }

    cout << "After lock() scope: " << sharedPtr.use_count() << endl; // Output: 1

    
    //==========================================================================
    
    /*
    auto sharedPtr = make_shared<int>(100);
    weak_ptr<int> weakPtr(sharedPtr);
    
    cout << "weakPtr.use_count(): " << weakPtr.use_count() << endl;
    cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << endl;
    cout << "weakPtr.expired(): " << weakPtr.expired() << endl;

    //lock() is a member function of weak_ptr that attempts to create a shared_ptr from it safely
    //if the managed object still exists, it returns a valid shared_ptr otherwise, it returns an empty shared_ptr to prevent crashes
    if(shared_ptr<int>sharedPtr2 = weakPtr.lock()){ 
        cout << "sharedPtr: " << *sharedPtr << endl;
        cout << "sharedPtr2.use_count(): " << sharedPtr2.use_count() << endl;
    }
    else{
        cout << "didnt get the resource" << endl;
    }
    
    weakPtr.reset();
    //reset() disassociates weakPtr from the shared object 
    //After calling reset(), weakPtr no longer tracks the object (it becomes empty).
    //This means weakPtr.lock() will always return an empty shared_ptr.
    if(shared_ptr<int>sharedPtr2 = weakPtr.lock()){
        cout << "sharedPtr: " << *sharedPtr << endl;
        cout << "sharedPtr2.use_count(): " << sharedPtr2.use_count() << endl;
    }
    else{
        cout << "didnt get the resource" << endl;
    }
    
    
    -> Demonstrates how weak_ptr tracks shared_ptr without increasing its reference count.  
    -> Shows how lock() safely converts weak_ptr to shared_ptr if the resource still exists.  
    -> Highlights that after reset(), weak_ptr no longer tracks the object, making lock() return an empty shared_ptr.  


    */
    
    return 0;
}