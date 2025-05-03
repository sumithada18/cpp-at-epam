#include <iostream>
#include <thread>

int var = 0;

void func() {
	for (int i = 0;i < 4;i++) {
		std::cout << "thread running" << std::endl;
	}
}

//unsynchronized thread which make conflicting accesses
void print(std::string str) {
	for (int i = 0;i < 5;i++) {
		std::cout << str[0] << str[1] << str[2] << std::endl;
	}
}
/*
The output will be scrambled up, like: 
abc
abcjpqr
klabc
a
pqr
pqr
pq
bc

what has gone wrong ?
- std::cout is not thread safe by default
- threads can be interrupted during o/p
- other threads can run and write their output
- the o/p from diff. threads is interleaved
*/

void inc() {
	for (int i = 0; i < 100000; i++) {
		var++;
	}
}
/*
what happens in above code: Race condition
-> multiple threads(thrq, thr2, thr3) are modifying global variable var - without synchornization
why this happened ?
- threads run in parallel and increment var but var++ is not atomic
- Multiple threads may read and update var at the same time, leading to data corruption or inconsistent results.
- Since var++ consists of:
  - Read var (load)
  - Increment value
  - Write back (store)
These steps can interleave between threads, causing lost updates.
*/

int main() {
	/*std::thread thr(func);
	for (int i = 0;i < 4;i++) {
		std::cout << "main running" << std::endl;
	}
	thr.join();*/


	/*std::thread thr1(print, "abc");
	std::thread thr2(print, "jkl");
	std::thread thr3(print, "pqr");

	thr1.join();
	thr2.join();
	thr3.join();*/


	std::thread thr1(inc);
	std::thread thr2(inc);
	std::thread thr3(inc);
	//std::cout << var << std::endl

	thr1.join();
	thr2.join();
	thr3.join();

	std::cout << var << std::endl;

	return 0;
}