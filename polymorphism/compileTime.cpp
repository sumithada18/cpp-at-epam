//compile time polymorphism
#include <iostream>
using namespace std;

/*
//not function overloading - return type cant decide
int fun(int var){
    return var;
}
void fun(int var){
    cout << "yes" << endl;
}
*/

//function overloading ? - yes!
void fun(int a, float b) {
	cout << a << endl;
}

void fun(float a, int b) {
cout << a << endl;
}

/*
not an example of function overloading
void fun(int var){
    cout << "okay" << endl;
}
void fun(int var){
    cout << "yes" << endl;
}
*/


//operator overloading example
class Number{
    public:
  int val;
  
  Number(int x){
      val = x;
  }
  
  Number operator+(Number& obj){
      return val+obj.val; //temporRY OBJECT is created and returned 
      // above is same as return Number(30); 
  }
};



int main()
{
	//fun(10);
	//fun(10);
	
	//fun(10, 10.5f);
	//fun(10.5f, 10);
	
	/*
	Number n1(10);
	Number n2(20);
	Number n3 = n1+n2; //temporary object is assogned to n3 through copy/move semantics depending upon the compiler
	
	cout << "sum is: " << n3.val << endl;
    */
    
    
    
	return 0;
}