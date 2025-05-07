#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>
using namespace std::literals;

std::shared_mutex smut;
int x = 0;

// exclusive lock
void write() {
	std::lock_guard<std::shared_mutex>lock_grd(smut);

	// start of critical section
	++x;
	// end of critical section
}

// shared lock
void read() {
	std::shared_lock<std::shared_mutex>shrd_lck(smut);

	// start of critical section
	std::this_thread::sleep_for(100ms);
	// end of critical section
}

int main() {
	std::vector<std::thread>threads;

	for (int i = 0;i < 20;i++) {
		threads.push_back(std::thread(read));
	}

	threads.push_back(std::thread(write));
	threads.push_back(std::thread(write));

	for (int i = 0; i < 20; i++) {
		threads.push_back(std::thread(read));
	}

	for (auto& it : threads) {
		it.join();
	}

	return 0;
}
/*
shared_mutex is for read - heavy scenarios to improve performance by letting multiple threads read simultaneously —
mutex doesn’t allow that.

When is shared_mutex useful ?
   When :
	Reads are frequent(80 - 90 %)
	Writes are rare.
For example :
	Cache access
	Config file reading
	Look - up tables.
*/