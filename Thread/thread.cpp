//#include<iostream>
//#include <thread>
//
//using namespace std::literals;
///*
//Q) what is thread entry point function ?
//Ans: -> it is function that executes when a thread starts
//-> The function's execution defines what the thread does.
//-> The thread begins execution from this function and runs independently.
//
//Q) How is it related to std::thread constructor ?
//Ans: When you create a std::thread object, the constructor takes the entry point function as an argument.
//
//This function gets executed in a separate thread.
//*/
//
////callable objct - thread entry point
////void hello() {
////	std::cout << "hello thread! \n";
////}
//
////functor class
////class Hello {
////public:
////	void operator()() {
////		std::cout << "Hello, functor thread \n";
////	}
////};
//
////thread function with argument
////void hello(std::string str) {
////	std::cout << str << std::endl;
////}
//
//
////void func(std::string&& str) {
////	std::cout << "ownership of " << str << " is transferred to thread!" << std::endl;
////}
//
//void func2(std::string& str) {
//	str = "xyz";
//}
//
//class Greet {
//public:
//	void hello() {
//		std::cout << "hello, thread member funciton" << std::endl;
//	}
//};
//
////=== for printing Thread ID ===
////void hello() {
////	std::cout << "hello thread! had thread ID: " << std::this_thread::get_id() << std::endl;
////}
//
////=== pausing the thread ===
//void hello() {
//	std::this_thread::sleep_for(3s);
//	std::cout << "hello from thread \n";
//}
//
//int main() {
//	//creating std::thread object and passing task function to the constructor
//	//std::thread thr(hello);  //1
//
//	
//	//Hello hello;
//	//std::thread thr(hello);  //2
//
//
//	/*auto hello = []() {
//		std::cout << "lambda thread" << std::endl;
//		};
//	std::thread thr(hello);*/  //3 
//
//	//function with argument
//	//std::thread thr(hello, "hello thread!");  //4
//
//	/*std::string str = "movable";
//	std::cout << "starting thread \n";
//
//	std::thread thr(func, std::move(str));*/ //5
//
//	/*std::string str = "hello thread!";
//	std::thread thr(func2, std::ref(str));*/ //6
//
//	//7
//	//Greet greet;
//	//std::thread thr(&Greet::hello, &greet); //we say to the thread: "Hey, use this function (hello()) and call it on this object (greet)."
//
//
//	//8
//	/*std::thread thr([](int i1, int i2) {
//		std::cout << "sum of i1 and i2 is: " << i1 + i2;
//	}, 2, 3);*/
//
//	//9
//	/*int i1 = 2, i2 = 10;
//	std::thread thr([&]() {
//		std::cout << "product is: " << i1 * i2;
//		});*/
//
//
//	/*std::thread thr(hello);
//	std::cout << "thr has native handle: " << thr.native_handle() <<std::endl;*/
//
//
//	/*std::cout << "Main thread has ID: " << std::this_thread::get_id() << std::endl;
//	std::thread thr(hello);
//	std::cout << "Hello thread has ID: " << thr.get_id() << std::endl;*/
//
//	std::cout << "starting thread" << std::endl;
//	std::thread thr(hello);
//
//	/*
//	joining a thread
//	=> std::thread has a join() member function
//	=> this is a 'blocking' call
//	 - does not return until thread has completed execution
//	 - the parent has to stop and wait for the thread to complete
//	=> 
//	*/
//	thr.join();
//
//	/*std::cout << "do i still have any data? \n";
//	std::cout << (str.empty() ? "No" : "YES") << std::endl;*/
//
//
//	//std::cout << "str, after: " << str << std::endl;
//
//
//	//std::cout << "thr now has native handle: " << thr.native_handle();
//
//
//	//std::cout << "Hello thread now, has ID: " << thr.get_id() << std::endl;
//
//	return 0;
//}
//
///*
//if a std::thread object is still running when it goes out of scope, it's destructor calls std::terminate()
//std::terminate() then calls abort(), which crashes the program
//to avoid this, always call join() or detach() before thr thread object is destroyed
//*/
//
//
//// When std::thread is created, it stores function arguments in its internal storage.
//// By default, std::thread **copies or moves** the arguments, treating them as rvalues.
//// If a function expects an lvalue reference (e.g., void func(std::string&)), 
//// passing a normal variable (std::string str) causes an error because a copy is made.
//// std::ref(str) solves this by wrapping str in std::reference_wrapper<std::string>.
//// The wrapper itself is copied, but it still holds a reference to str,  
//// ensuring the function receives an actual reference instead of a temporary copy.
