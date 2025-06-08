//#include"common.h";

// example where 5 threads compete for a single mutex.Whichever thread grabs it first will print first 
//std::mutex m;

//void worker(int id) {
//	std::lock_guard<std::mutex>lg(m);
//	std::cout << "thread with id: " << id << " is running" << std::endl;
//}
// every time we run the code - we may see different ordering of execution 
// which thread will lock is decied by the OS


// we can also try to order the excution by applying some extra logic
// let's use CV

//std::condition_variable cv;
//int turn = 1;

//void worker(int id) {
//	std::unique_lock<std::mutex>ul(m);
//	cv.wait(ul, [id]() {return (turn == id);});
//	std::cout << "thread with id: " << id << " is running" << std::endl;
//
//	turn++;
//	// cv.notify_one(); do not use this since it'll wake up any random thread which may or may not be the intended thread
//	// which we wish to invoke and that will cause deadlock!
//	cv.notify_all();
//}

//int main() {
//
//	std::vector<std::thread>vec;
//	for (int i = 0;i <= 5;i++) {
//		vec.push_back(std::thread(worker, i));
//	}
//
//	for (auto& it : vec) it.join();
//
//	return 0;
//}