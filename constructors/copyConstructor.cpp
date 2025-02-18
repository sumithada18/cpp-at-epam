
#include <bits/stdc++.h>
using namespace std;

class Book{
    public: 
  string Title;
  string Author;
  float* Rates;
  int RatesCounter;
  
  Book(string title, string author){
      Title = title;
      Author = author;
      
      RatesCounter =2;
      Rates = new float[RatesCounter];
      Rates[0]=5;
      Rates[1]=4;
  }
  
  ~Book(){
      delete[]Rates;
      Rates = nullptr;
      cout<<"destructor called"<<endl;
  }
  
  /*
  -> ways of passing object to a function:- by value or by reference
  
  Book(Book original) -> will cause infinite loop, here's why:
  
  -> passing obj by value would require copying the object, which calls copy constructor again,
  causing an infinite loop.
  -> const prevents modification to the original object during copying, w/o const copy constr. 
  could modify the source object which is unexpected
  
  */
  
  
  Book(const Book& original){
      Title = original.Title;
      Author = original.Author;
      RatesCounter = original.RatesCounter;
      
      //Rates = original.Rates;
      /*
      if we do the above way of copying:-
      -> original obj allocatec m/m for Rates in it constructor and copy constructor copies 
      the pointer, not the data.
      -> both objects now share the same m/m.
      -> when one obj is destroyed -> it delets the shared m/m.
      -> when second obj is destroyed -> it tries to delete the same m/m again -> undefined
      behaviour
      */
      
      //solution:-
      Rates = new float[RatesCounter]; //allocate new m/m
      for(int i=0; i<RatesCounter; i++){
          Rates[i] = original.Rates[i]; //copy values
      }
      
      cout<<"copy constructor called"<<endl;
  }
  
};

void printBook(Book book){
      cout << "Book's title: " << book.Title << endl;
      cout << "Book's author: " << book.Author << endl;
      
      int sum=0;
      for(int i=0;i<book.RatesCounter; i++){
          sum+=book.Rates[i];
      }
      cout<< "sum of rates: " << sum << endl;
  }

int main()
{
    Book book1("millionaire fastlane", "deMacro");
    Book book2("C++ lambda story", "bartek f");

    Book book3(book1);
    
    printBook(book1);
    printBook(book3);
    //both should be same - yes!
    
    return 0;
}