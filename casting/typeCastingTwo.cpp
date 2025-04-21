//#include <iostream>
//using namespace std;
//
//int main() {
//    const int num = 100;
//    const int* ptr = &num;
//
//    cout << *ptr << endl; // prints 100
//
//    int* ptr2 = const_cast<int*>(ptr);
//    *ptr2 = 10;
//
//    cout << "*ptr: " << *ptr << " and ptr2: " << *ptr2 << endl;
//    cout << num << endl;
//    cout << &num << " : " << ptr << " : " << ptr2 << endl;
//    /*
//this could have happened:
//- Since num is declared as const, the compiler assumes its value never changes.
//- It may cache or inline num = 100 in the code instead of actually reading from memory.
//- So, when you print num, it directly fetches 100 from its cache, ignoring the actual memory modification.
//*/
//
//    return 0;
//}
//
