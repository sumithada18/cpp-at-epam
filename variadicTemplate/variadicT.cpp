//************************ variadic template ***************************
#include <iostream>

//Variadic templates allow functions to accept a variable number of arguments at compile time.
//template<typename... Args>
// void print(Args... args) {
//     (std::cout << ... << args);
//     //(std::cout << arg1) << arg2) << arg3) << ... << argN;
// }

/*
how function above works:
    Args... -> represent pack of types
    args... -> pack of vslues passed to function

    (std::cout<<...<<args) -> fold expression
    The fold expression expands like this:
    (((std::cout << 1) << 2) << "sumit") << 1.2;
    The expressions are evaluated from left to right.

    using parenthesis in fold expression - best practice when using fold with I/O operations
*/

// void print(Args... args) {
//     ((std::cout << args << " "), ...) << std::endl;
// }
/*
how above function expands:
    ((std::cout<<1<<" "), (), (),)

difference between two:
- Binary Left Fold (expr op ... op expr) -> Nested Left Associative Expansion
(((A op B) op C) op D)

- Unary Left Fold ((expr, ...)) -> Sequential Execution
(expr1, expr2, expr3, ...) executes one by one.
*/


template<typename T>
T Sum(T arg){
    return arg;
}

template<typename T, typename... Args>
T Sum(T start, Args... args){
    return start + Sum(args...);
}

/*
if the 'start' is a double:-

double sum<double, int, int, int, int>(double first, int __arg1, int __arg2, int __arg3, int __arg4)
{
  return first + static_cast<double>(sum(__arg1, __arg2, __arg3, __arg4));
}
*/


// class DataHolder{
//     public:
//     DataHolder(){std::cout << "Cons.. called";}
//     void print(Args... args) {
//     (std::cout << ... << args);
// }
// };
//the code gives error - why? reason: class template parameters (Args...) don't carry over to function parameters.

/*
//solution: Use a Separate Variadic Template for print()
class DataHolder {
public:
	DataHolder() {
		std::cout << "Cons.. called \n";
	}
	template<typename... T>
	void print(T... args
	{
		((std::cout << args <<" "), ...);
	}
};
*/

int main()
{
//    std::cout<<sum(10);
    std::cout << Sum(1,2,3,4) << std::endl;
//    print(1, 2, "sumit", 1.2);

//	DataHolder<int, double, std::string> obj;
//	obj.print(1, "sumit", 12.32, true);
	return 0;
}

/*
sum(1,2,3,4) -> 1+sum(2,3,4) -> 1+(2+sum(3,4)) -> 1+(2+(3+sum(4)))
sum(4) matches the base case so it returns 4

*/