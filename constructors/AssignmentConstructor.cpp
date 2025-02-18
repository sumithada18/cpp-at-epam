#include <bits/stdc++.h>
using namespace std;

class Book{
    public: 
  string Title;
  string Author;
  float* Rates;
  int RatesCounter;
  
  Book(){
      Rates = nullptr;
      RatesCounter = 0;
  }
  
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
  
  Book(const Book& original){
      Title = original.Title;
      Author = original.Author;
      RatesCounter = original.RatesCounter;
      
      Rates = new float[RatesCounter];
      for(int i=0; i<RatesCounter; i++){
          Rates[i] = original.Rates[i];
      }
      
      cout<<"copy constructor called"<<endl;
  }
  
  Book& operator=(const Book& original){
      if(this != &original){ //ensures that the object is not copied into itself, 
      //avoiding unintended deletion of its own resources.
      Title = original.Title;
      Author = original.Author;
      RatesCounter = original.RatesCounter;
      
      delete[] Rates;
      
      Rates = new float[RatesCounter];
      for(int i=0; i<RatesCounter; i++){
          Rates[i] = original.Rates[i];
      }
      
      cout<<"assignment overloading called"<<endl;
      }
      return *this;
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
    
    //printBook(book1);
    //printBook(book3);
    
    Book book4;
    book4 = book2;
    
    printBook(book4);
    printBook(book2);
    
    return 0;
}
