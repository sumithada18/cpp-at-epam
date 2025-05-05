#include <iostream>
#include <thread>
#include <mutex>

// shared data 
long long balance = 0;

//void addMoney(int val) {
//    for (int i = 0;i < 10000;i++) {
//        balance += val;
//    }
//}
//
//void subtractMoney(int val) {
//    for (int i = 0;i < 10000;i++) {
//        balance -= val;
//    }
//}
// Above code MAY NOT always give correct output due to data race 
// solution: **synchronization**

std::mutex m;

void addMoney(int val) {
    for (int i = 0;i < 10000;i++) {
        std::lock_guard<std::mutex>lg(m);
        balance += val;
    }
}

void subtractMoney(int val) {
    for (int i = 0;i < 10000;i++) {
        std::lock_guard<std::mutex>lg(m);
        balance -= val;
    }
}
// now it is guaranteed to give correct output i.e 20k

int main()
{
    std::thread t1(addMoney, 1);
    std::thread t2(addMoney, 1);
    std::thread t3(subtractMoney, 1);
    std::thread t4(addMoney, 1);
   // std::thread t3(addMoney, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "final balance: " << balance << "\n";
    return 0;
}