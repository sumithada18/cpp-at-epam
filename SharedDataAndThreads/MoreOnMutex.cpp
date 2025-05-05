//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <vector>
//using namespace std::literals;
//
//
//std::timed_mutex the_mut;
//
///*
//void task1() {
//	std::cout<< "Task1 tyring to lock the mutex" << "\n";
//	the_mut.lock();
//	std::cout << "Task1 locks the mutex" << "\n";
//	std::this_thread::sleep_for(5s);
//	std::cout <<"Task1 unlocks the mutex"<<"\n";
//	the_mut.unlock();
//}
//
//void task2() {
//	std::this_thread::sleep_for(500ms);
//	std::cout << "Task2 trying to lock the mutex" << "\n";
//
//	// try for 1 sec to lock the utex
//	while (!the_mut.try_lock_for(1s)) {
//		// returned false
//		std::cout << "Task2 could not lock the mutex" << "\n";
//	}
//
//	// returned true - the mutex is now locked
//	
//	// start of critical section
//	std::cout << "Task2 locking the mutex" << "\n";
//	// end od critical section
//
//	the_mut.unlock();
//}
//*/
//
//void task1() {
//	std::cout << "Task1 tyring to lock the mutex" << "\n";
//	std::lock_guard<std::timed_mutex>lock_grd(the_mut);
//	std::cout << "Task1 locks the mutex" << "\n";
//	std::this_thread::sleep_for(5s);
//	std::cout << "Task1 unlocks the mutex" << "\n";
//}
//
//void task2() {
//	std::this_thread::sleep_for(500ms);
//	std::cout << "Task2 trying to lock the mutex" << "\n";
//	
//	std::unique_lock<std::timed_mutex>uniq_lck(the_mut, std::defer_lock);
//
//	// try for 1 sec to lock the utex
//	while (!uniq_lck.try_lock_for(1s)) {
//		// returned false
//		std::cout << "Task2 could not lock the mutex" << "\n";
//	}
//
//	// returned true - the mutex is now locked
//
//	// start of critical section
//	std::cout << "Task2 locking the mutex" << "\n";
//	// end od critical section
//}
//
//// shared variable
//int x = 0;
//std::mutex mutx;
//
//void write() {
//	std::lock_guard<std::mutex>lck_grd(mutx);
//
//	// start of critical section
//	++x;
//	// end of critical section
//}
//
//void read() {
//	std::lock_guard<std::mutex>lck_grd(mutx);
//
//	// start of critical section
//	std::this_thread::sleep_for(100ms);
//	// end of critical section
//}
//
//int main() {
//	/*std::thread thr1(task1);
//	std::thread thr2(task2);
//
//	thr1.join();
//	thr2.join();*/
//
//	std::vector<std::thread>threads;
//	for (int i = 0;i < 20;i++) {
//		threads.push_back(std::thread(read));
//	}
//
//	threads.push_back(std::thread(write));
//	threads.push_back(std::thread(write));
//
//	for (int i = 0;i < 20;i++) {
//		threads.push_back(std::thread(read));
//	}
//
//	for (auto& it : threads) {
//		it.join();
//	}
//
//	return 0;
//}