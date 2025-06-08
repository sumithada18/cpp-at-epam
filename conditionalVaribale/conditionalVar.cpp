//// condition variable
//#include "common.h";
//
//// CV are used for two purpose
//// a. notify other threads
//// b. waiting for some conditions
//
//// condition variable allows running threads to wait on some condition and when the condition is met, the waiting thread 
//// is notified using notify_one() or notify_all()
//
//// we need mutex to use condition variable
//// if some thread want to wait for some condition then it has to do:
//	// acquire mutex lock using unique_lock 
//	// execute wait, wait_for, wait_until. Wait operations atomically release the mutex and suspend the execution of the thread
//	// 
//
////int balance = 0;
////std::condition_variable cv;
////std::mutex mx;
////
////void withdraw(int money) {
////	std::unique_lock<std::mutex>ul(mx);
////	cv.wait(ul, []() {return (balance != 0) ? true : false; });
////	if (balance >= money) {
////		balance -= money;
////	}
////	else {
////		std::cout << "insufficient balance" << "\n";
////	}
////	std::cout << "current balance: " << balance << std::endl;
////}
////
////void addMoney(int money) {
////	std::lock_guard<std::mutex>lg(mx);
////	balance += money;
////	std::cout << "amount added: " << money << "\n";
////	cv.notify_one();
////}
////
////int main() {
////
////	std::thread thr(withdraw, 200);
////	std::thread thr2(addMoney, 500);
////
////	thr.join();
////	thr2.join();
////
////	return 0;
////}
//
//// second example
//#include <iostream>
//#include <thread>
//#include <condition_variable>
//#include <mutex>
//
//std::mutex mtx;
//std::condition_variable cv;
//bool ready = false;
//
//void worker() {
//    std::unique_lock<std::mutex> lock(mtx);
//    cv.wait(lock, [] { return ready; });
//    std::cout << "Worker thread is running\n";
//}
//
//int main() {
//    std::thread t(worker);
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    {
//        std::lock_guard<std::mutex> lock(mtx);
//        ready = true;
//        cv.notify_one(); // notifying just before locking 
//    }
//
//    t.join();
//}
//
///*
//The waiting thread locks the mutex, checks the condition. If false, it releases the lock and suspends itself. Another thread modifies the shared variable, locks the mutex, notifies, and the waiting thread wakes up, reacquires the lock, and continues.
//*/




// Best Practice: Notify before unlocking the mutex
// Why: To avoid a race condition and ensure the waiting thread sees the correct data

//{
//    std::unique_lock<std::mutex> lock(mtx);  // Lock mutex
//    shared_data = updated_value;              // Update shared data
//    cv.notify_one();                          // Notify before unlocking
//}  // Mutex is released automatically when lock goes out of scope

// Why not unlock before notify? Unlocking before notify can cause other threads
// to modify the shared data, leading to incorrect behavior.
