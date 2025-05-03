//#include <iostream>
//#include <thread>
//#include <exception>
//
////============== thread object ownership transfer ===============
////void hello() {
////	using namespace std::literals;
////	std::this_thread::sleep_for(1s);
////	std::cout << "hello thread" << std::endl;
////}
//
////Function taking thread object as an argument
////The object must be moved into the argument 
////void func(std::thread thr){   // this can take both lavlue and ravlue - but if lavalue is passed, copy constructor is called of thr object which is deleted - compilation error
////	std::cout << "recieved thread with ID: " << thr.get_id()<<std::endl;
////	
////	//the function argument now "owns" the system thread
////	//it is responsible for calling join()
////	thr.join();
////}
////=========================================================
//
//
//// for 'returning thread' implementation =======================
////void hello() {
////		std::cout << "hello thread" << std::endl;
////}
//// function returning a std::thread object
////std::thread func() {
////	// starting thread   
////	std::thread thr(hello);
////
////	//return a local variable
////	return thr;
////}
////=============================================================
//
////========================= thread exception
////for case1: 
////void hello() {
////	try {
////		throw std::exception();
////	}
////	catch (std::exception& e) {
////		std::cout << "exception caught! " << e.what() << std::endl;
////	}
////	std::cout << "hello thread!" << std::endl;
////}
//
////for case2:
////void hello() {
////	throw std::exception();
////	std::cout << "hello thread!" << std::endl;
////}
//
//
//void hello() {
//	std::cout << "hello thread!" << std::endl;
//}
//
//class thread_guard {
//	std::thread thr;
//public:
//	// cons.. takes rvalue reference argument (std::thread is move-only)
//	explicit thread_guard(std::thread&& thr) : thr(std::move(thr)) {
//	}
//
//	//destructor - join the thread if necessary
//	~thread_guard() {
//		if (thr.joinable()) {
//			thr.join();
//		}
//	}
//
//	thread_guard(const thread_guard&) = delete;
//	thread_guard& operator=(const thread_guard&) = delete;
//};
//
//int main() {
//	/*
//	//std::thread is a move-only object
//	std::thread thr(hello);
//	
//	//printing child thread's id:
//	std::cout << "Hello thread has ID: " << thr.get_id()<<std::endl;
//
//	func(std::move(thr));
//	
//	The `std::thread` object manages a system-level thread. Initially, `main()` creates and manages the `hello` thread via `thr`. When ownership of `thr` is moved to `func()`, `func()` takes over its management, 
//	but the OS-level parent-child relationship remains unchanged—`main()` is still the parent of `hello`. After `std::move(thr)`, the `thr` object in `main()` becomes empty and can no longer be used to manage the thread.
//	
//	//thr.join();
//	*/
//
//	/*
//	std::thread thr = func();
//	std::cout << "thread recieved with ID: " << thr.get_id() << std::endl;
//	thr.join();
//	*/
//
//
//	//case 1: when exception is handled in the thread itself
//	//std::thread thr(hello);
//	//thr.join();
//
//	//case 2: when exception thrown from the thread is handled in main
//	/*try {
//		std::thread thr(hello);
//		thr.join();
//	}
//	catch (...) {
//		std::cout << "exception caught!" << std::endl;
//	}*/
//	/*
//	 what happens in above snippet : program is terminated - why ?
//	 reason:
//	- Each thread has its own execution stack.
//	- When an exception is thrown inside a thread, stack unwinding happens within that thread only.
//	- If no handler is found in the thread's stack, std::terminate() is called.
//	- The main thread is separate, with its own execution stack, so it cannot catch exceptions from another thread.
//	*/
//
//	/*
//	std::thread thr(hello);
//	try {
//		throw std::exception();
//
//		thr.join();
//	}
//	catch(std::exception& e){
//		std::cout << "exception caught: " << e.what() << std::endl;
//		thr.join();
//	}
//	*/
//
//	try {
//		std::thread thr(hello);
//		thread_guard tguard(std::move(thr));
//
//		throw std::exception();
//
//		thr.join();
//	} //calls _thread_guard followed by ~thread
//	catch (std::exception& e) {
//
//	}
//
//	return 0;
//}