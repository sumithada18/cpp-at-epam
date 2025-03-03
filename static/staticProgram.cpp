/********************************** static function and static members ********************************************/
#include <iostream>
using namespace std;

//example: making a class of customer of a bank
class Customer{
  string name;
  int acc_number, balance;
  static int total_customer; //privatestatic data member
  public:
  //static int total_customer; //public static data member
  Customer(string n, int an, int b)
  {
      name = n;
      acc_number = an;
      balance = b;
      total_customer++;
  }
  
  void customerCnt(){
      cout << total_customer << endl;
  }
  static int accessStatic(){ //static function
      return total_customer;
  }
  //Static functions are shared across all instances (no this pointer).
};
int Customer::total_customer = 0;

//==========================================================================================================
class Test{
    public:
    virtual static void fun(){};
};
//above class code snippet gives error when instantiated - static functions can't be virtual since virtual functions are not tied to 
//instance of a class but the class itself. 

// Also, static member function cannot be const and volatile. Following code also fails in compilation,
class Test2{
    public:
    virtual static void fun() const {};
};

int main()
{
    //not using static:-
    /*
    Customer c1("sumit", 9090, 100);
    c1.customerCnt(); // output: 1
    Customer c2("sumit", 7191, 7000);
    c1.customerCnt(); // output: 1
    */
    
    //using static:
    Customer c1("sumit", 9090, 100);
    c1.customerCnt(); // output: 1
    
    Customer c2("amit", 7191, 7000);
    c1.customerCnt(); // output: 2
    
    Customer c3("udit", 9197, 7000);
    c1.customerCnt(); // output: 3
    
    //cout << "total customer are: " << Customer::total_customer << endl; //no problem if static member is public:
    
    //when static member is private - we create static function in class to access the static data member
    cout << "total customers are " << Customer::accessStatic() << endl;
    
    
    return 0;
}
