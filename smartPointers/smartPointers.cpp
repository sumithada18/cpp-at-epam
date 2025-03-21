#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int>unPtr = make_unique<int>(25);
    /*
    make_unique<int>(25) -> dynalically allocates an int with value 25, ans returns
    unique_ptr<int> managing that m/m
    
    unique_ptr<int> unPtr = ... -> unPtr is a unique_ptr<int> that now owns the allocates int
    
    */
    
    cout << unPtr.get() << endl; //prints m/m address
    
    cout << *unPtr << endl; //dereferences unique pointer
    
    /*
    properties of unique_ptr
    -> only one unique_ptr can own a resource at a time.
    -> when unique_ptr goes out of scope, it deletes the object
    ->  Copying a unique_ptr is not allowed (unique_ptr can't be shared).
    -> Ownership can be transferred using std::move().
    */

    return 0;
}