//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <execution>
//
//struct print_v {
//    void operator() (int value) {
//        std::cout << value << " ";
//    }
//};
//
//struct compare {
//    bool operator() (int a, int b) {
//       // return a < b; //for ascending
//        return a > b;
//    }
//};
//
//int main()
//{
//    /*
//    std::vector<int>vec = { 12, 3, 11, 50 };
//    //1
//    for (auto elem : vec) {
//        std::cout << elem << " ";
//    }
//
//    std::cout << "\n";
//
//    //2
//    std::for_each(vec.begin(), vec.end(), [](int n){ std::cout << n << " "; });
//    //better becuase: code clarity and reusability
//
//    //c++ 17 feature:- 
//    // Parallel execution (`std::execution::par`) speeds up processing by utilizing multiple CPU cores instead of sequential iteration.
//    //std::for_each(std::execution::par, vec.begin(), vec.end(), [](int n) { std::cout << n << " "; });
//
//    std::cout << "\n";
//    //3 we can also do
//    auto print_func = [](int n) {
//        std::cout << n << " ";
//        };
//    std::for_each(vec.begin(), vec.end(), print_func);
//
//    std::cout << "\n";
//    //4 or we can do
//    std::for_each(vec.begin(), vec.end(), print_v());
//
//    std::cout<<"\n";
//    //5 
//    int lastResult = -1;
//    std::for_each(vec.begin(), vec.end(), [&lastResult](int n) 
//        { 
//            lastResult = n;
//            std::cout << n << " "; 
//        });
//    std::cout << "the last value is " << lastResult;
// */
//
//    std::vector<int>v2 = { 12, 13, 1, 2, 48 };
//    //std::sort(v2.begin(), v2.end(), compare());
//    std::sort(v2.begin(), v2.end(), [](int a, int b) { return a > b; });
//        for (auto& elem : v2) { std::cout << elem << " "; }
//        /*
//        For simple, one-time comparisons, lambdas are superior in C++11 due to less overhead, better readability, and inline optimizations.
//        */
//
//    return 0;
//}