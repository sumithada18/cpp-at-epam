#include <iostream>
#include <memory>
using namespace std;
// ===============================================
// Passing std::shared_ptr to functions:
// ===============================================
// * By value (takes ownership share)
// * By const& (observes, doesn't affect ref count significantly)
// * By & (if the function needs to reseat the pointer)

void sptr_by_val(std::shared_ptr<int> p){
    // Copies shared_ptr → increases use_count temporarily (copy constructor)
    std::cout << "in sptr_by_val: " << p.use_count() << "\n";
}

void sptr_by_const_ref(const std::shared_ptr<int>& p){
    // Observes shared_ptr without copying → use_count unchanged
    std::cout << "in sptr_by_const_ref: " << p.use_count() << "\n";
}

void sptr_by_ref(std::shared_ptr<int>& p){
    // Direct access to shared_ptr → can modify original, use_count unchanged
    std::cout << "in sptr_by_ref: " << p.use_count() << "\n";
}


// ===============================================
// Returning smart pointers from functions 
// ===============================================

std::unique_ptr<int> createUnique(int val) {
    // Creates a unique_ptr owning a dynamically allocated int initialized with val
    // Returned by value → compiler applies move semantics (RVO/NRVO or move)
    return std::make_unique<int>(val);
}

std::shared_ptr<int> createShared(int val) {
    // Creates a shared_ptr managing a dynamically allocated int with val
    // Reference count starts at 1 → returned by value
    return std::make_shared<int>(val);
}


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
    //cout << *p1 << " " << *(p2.lock()) << endl; //we can't dereference a weak_ptr directly, we must use .lock() which converts it into a shared_ptr
    
    /*
    case1: we do p1.reset()
    
    p1.reset();
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    */
    
    /*
    case2: we do p2.reset()
    
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    
    */
    
    //conclusion: If we reset a shared_ptr, 
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

 //============================ Passing std::shared_ptr to functions:=========================
    std::shared_ptr<int>s_ptr = std::make_shared<int>(100); // use_count = 1

// sptr_by_val(s_ptr); 
// Copy made → use_count becomes 2 inside function → back to 1 after

// sptr_by_const_ref(s_ptr);
// No copy → just observes → use_count stays 1 throughout

sptr_by_ref(s_ptr); 
// Can reset/modify s_ptr from inside → use_count remains 1 unless manually changed
    
    return 0;
}
