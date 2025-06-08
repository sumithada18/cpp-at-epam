#include "common.h"

std::mutex m;
std::condition_variable cv;
std::string str;

void reader() {
	{
		std::cout << "reader thread locking mutex \n";
		std::unique_lock<std::mutex>ul(m);

		std::cout << "reader thread sleeping! \n";
		cv.wait(ul);
		std::cout << "reader thread wakes up! \n";

		std::cout << "data is : " << str << "\n";

	}
}

void writer() {
	{
		std::cout << "writer thread locking mutex \n";
		std::lock_guard < std::mutex>lg(m);
		std::cout << "writer thread locked the mutex \n";

		// trying to act busy
		std::this_thread::sleep_for(50ms);

		std::cout << "writer thread modifiying string" << std::endl;
		str = "populated";
	}
	std::cout << "writer thread send notification! \n";
	cv.notify_one();
}

/*
result of this code: reader thread keeps on sleeping, sleeping, sleeping ...!
why? 
reason: Lost wakeup
here writer thread send notification before reader thread starts waiting which means that the
wakeup call is lost

Lost wakeup happens when:
A thread sends a notification (notify_one / notify_all) before another thread has started waiting (wait).
The waiting thread misses the notification and gets stuck waiting forever — because condition_variable doesn’t store past notifications!

Solution:
Always use a flag + predicate with wait() :
cond_var.wait(lock, []{ return flag; });
This ensures the thread checks the condition even if notify happened before wait.
*/
int main() {
	str = "empty";
	std::cout << "string initially: " << str << std::endl;

	std::thread t1(writer);
	std::this_thread::sleep_for(500ms);
	std::thread t2(reader);

	t1.join();
	t2.join();
	return 0;
}