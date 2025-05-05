//#include <iostream>
//#include <mutex>
//#include <thread>
//#include <string>
//#include <vector>
//#include <exception>
//using namespace std::literals;
//
////global mutex object
////std::mutex task_mutex;
//
//
///*
//void task(std::string&& str) {
//	for (int i = 0;i < 4;i++) {
//		std::cout << str[0] << str[1] << str[2] << std::endl;
//	}
//}
//*/
////above function results in scrabled output as we've already seen
////solution: mutex
//
////uses mutex object for synchornization:
////void task(std::string&& str) {
////	// lock the mutex before critical section
////	task_mutex.lock();
////
////	// start of the critical section
////	for (int i = 0;i < 4;++i) {
////		std::cout << str[0] << str[1] << str[2] << std::endl;
////	}
////	// end of critical section
////
////	// unlock the mutex after the critical section
////	task_mutex.unlock();
////}
//
///*
//std::mutex the_mutex;
//
//void task1() {
//	std::cout << "Task1 trying to lock the mutex" << std::endl;
//	the_mutex.lock();
//	std::cout << "Task1 has locked the mutex" << std::endl;
//	std::this_thread::sleep_for(500ms);
//	std::cout << "Task1 unlocking the mutex" << std::endl;
//	the_mutex.unlock();
//}
//
//void task2() {
//	std::this_thread::sleep_for(100ms);
//	std::cout << "Task2 trying to lock the mutex" << std::endl;
//	while (!the_mutex.try_lock()) {
//		std::cout << "Task2 could not lock the mutex" << std::endl;
//		std::this_thread::sleep_for(100ms);
//	}
//	std::cout << "Task2 has locked the mutex" << std::endl;
//	the_mutex.unlock();
//}
//*/
//
///*
//class vector {
//public:
//	std::vector<int>vec;
//	std::mutex mut;
//
//	void push_back(const int& i) {
//		mut.lock();
//
//		//start of the critical section
//		vec.push_back(i);
//
//		//end of critical section
//		mut.unlock();
//	}
//
//	void print() {
//		mut.lock();
//
//		// start of critical section
//		for (auto i : vec) {
//			std::cout << i << ", ";
//		}
//		std::cout << std::endl;
//
//		//end of critical section
//		mut.unlock();
//	}
//};
//
//void func(vector& arg) {
//	for (int i = 0;i < 5;++i) {
//		arg.push_back(i);
//		std::this_thread::sleep_for(50ms);
//		arg.print();
//	}
//}
//*/
//
////case: exception thrown before mutex unlocks - deadlock situation
//std::mutex task_mutex;
////void strTask(const std::string& s) {
////	
////	for (int i = 0;i < 5;i++) {
////		try {
////			//lock the mutex before entring critical section
////			task_mutex.lock();
////
////			// start of critical section
////			std::cout << s[0] << s[1] << s[2] << std::endl;
////			
////			throw std::exception();
////			//end of critical section
////
////
////			task_mutex.unlock(); //never gets called
////		}
////		catch (std::exception& e) {
////			std::cout << "exception caught: " << e.what() << std::endl;
////		}
////	}
////}
//
////solution: use lock guard class - wrapper around mutex 
////void strTask(const std::string& s) {
////	for (int i = 0;i < 5;i++) {
////		try {
////			// create an std::lock_guard object
////			//this calls task_mutex.lock()
////			std::lock_guard<std::mutex>lck_grd(task_mutex);
////			
////			// start of critical section
////			std::cout << s[0] << s[1] << s[2] << "\n";
////
////			// critical section throws an exception
////			throw std::exception();
////			// end of critical section
////
////		//	std::this_thread::sleep_for(50ms);
////		} // calls ~std::lock_guard
////		catch (std::exception& e) {
////			std::cout << "exception caught: " << e.what() << "\n";
////		}
////	}
////}
///*
//lck_grd is created
// - it's constructor calls lock()
//lck_grd goes out of scope
// - it's destructor calls unlock()
//if an exception is thrown
// - lck_grd's destrcutor is called and unlocks the mutex
//
// => the mutex is never left unlocked
//*/
//
///*
//drawback of using std::lock_guard - in the above function if I uncomment std::sleep_for - what happens:
// - Even after the critical section, the lock remains held until lock_guard goes out of scope.
// - This means other threads cannot access the critical section until the function ends, leading to performance issues.
//*/
//
//void strTask(const std::string& s) {
//	for (int i = 0;i < 5;i++) {
//		try {
//			//this calls task_mutex.lock()
//			std::unique_lock<std::mutex>uniq_lck(task_mutex);
//
//			// start of critical section
//			std::cout << s[0] << s[1] << s[2] << "\n";
//			// end of critical section
//
//			//unlock the mutex
//			uniq_lck.unlock();  // comment this and run code - flickering is there ! - "major performance issue"
//
//			std::this_thread::sleep_for(100ms);
//		} // calls ~std::unique_lock
//		catch (std::exception& e) {
//			std::cout << "exception caught: " << e.what() << "\n";
//		}
//	}
//}
//
//std::recursive_mutex rmut;
////try using mutex in-place of recursive_mutex
//
//int bad_factorial(int n) {
//	if (n <= 1) {
//		std::cout << "Returning " << 1 << "\n";
//		return 1;
//	}
//
//	//rmut.lock();
//	std::lock_guard<std::recursive_mutex>rec_lock(rmut);
//	
//	// critical section 
//	int returnVal = n * bad_factorial(n - 1);
//	std::cout << "Returning " << returnVal << "\n";
//	// end of critical section
//
//	//rmut.unlock();
//
//	return returnVal;
//}
//
//
//int main() {
//	/*
//	std::thread thr1(task, "abc");
//	std::thread thr2(task, "def");
//	std::thread thr3(task, "ghi");
//
//	thr1.join();
//	thr2.join();
//	thr3.join();
//	*/
//
//	/*
//	std::thread thr1(task1);
//	std::thread thr2(task2);
//
//	thr1.join();
//	thr2.join();
//	*/
//
//	/*
//	vector v;
//
//	std::thread thr1(func, std::ref(v));
//	std::thread thr2(func, std::ref(v));
//	std::thread thr3(func, std::ref(v));
//
//	thr1.join();
//	thr2.join();
//	thr3.join();
//	*/
//	
//	//using the same code for 2 cases - exception before unlocking and it's solution
//	// + 2 : drawback of std::lock_guard and std::unique_lock
//	/*std::thread thr1(strTask, "abc");
//	std::thread thr2(strTask, "def");
//	std::thread thr3(strTask, "pqr");
//
//	thr1.join();
//	thr2.join();
//	thr3.join();*/
//	/*
//	* std::lock_gurad vs std::unique_lock :-
//	 - If performance is the priority → Use std::lock_guard
//	 - If flexibility is required (manual unlock, deferred lock, ownership transfer) → Use std::unique_lock, but be aware of the overhead.
//	*/
//
//	std::thread thr(bad_factorial, 6);
//	thr.join();
//
//	return 0;
//}