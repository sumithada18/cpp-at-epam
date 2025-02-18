#include <bits/stdc++.h>
using namespace std;

class Book{
    public: 
  string Author;
  string* Titles;
  int BookCounter;
  
  Book(){
      Titles = nullptr;
      BookCounter = 0;
  }
  
  Book(string author){
      Titles = nullptr;
      Author = author;
      
      BookCounter = 0;
      Titles = new string[BookCounter];
      cout << "constructor called" << endl;
  }
  
  ~Book(){
      delete[] Titles;
      Titles = nullptr;
      cout<<"destructor called"<<endl;
  }
  
  Book(const Book& original){
      Author = original.Author;
      BookCounter = original.BookCounter;
      
      Titles = new string[BookCounter];
      for(int i=0; i<BookCounter; i++){
          Titles[i] = original.Titles[i];
      }
      
      cout<<"copy constructor called"<<endl;
  }
  
   void AddBook(string NewBookName){
      string* newBooks = new string[BookCounter+1];
      for(int i=0;i<BookCounter;i++){
          newBooks[i] = Titles[i];
      }
      
      newBooks[BookCounter] = NewBookName;
      
      delete[] Titles;
      Titles = newBooks;
      BookCounter++;
   }
   
   void printBook(){
       cout << "author name: " << Author << endl;
       cout << "no. of books: " << BookCounter << endl;
       
       cout << "books are: ";
       for(int i=0;i<BookCounter;i++){
           cout << Titles[i] << " ";
       }
       
       cout << endl;
   }
  
};


int main()
{
    Book book1("james b");
    Book book2("charles c");
    
    book1.AddBook("harry potter");
    book1.AddBook("twilight");
    
    //book1.printBook();
    
    Book book3 = book1;
    book3.AddBook("song of ice and fire");
    book3.printBook();

    
    
    return 0;
}
