#include <iostream>
#include <tuple>

//function returning multiplt values 

// 1. using struct 
//typedef struct {
//	int id;
//	float points;
//} Data;
//
//Data result() {
//	Data res = { 11, 34.34 };
//	return res;
//}
// problem: returns a copy


// 2. struct + DMA
typedef struct {
	int id;
	float points;
} Data;

Data* result() {
	Data* res = (Data*)(malloc(sizeof(Data)));
	if (res) {
		res->id = 11;
		res->points = 45.54;
	}
	return res;
}
// avoids copy, but manual memory mgmt.


// 3. using classes
class Result {
public:
	int id;
	char symbol;

	Result(int val1, char val2) {
		id = val1;
		symbol = val2;
	}
	void display() {
		std::cout << id << " " << symbol << std::endl;
	}
};

//Result func() {
//	return Result(12, 'c');
//}
// Returns a copy, which can be inefficient for large objects


// 4. class + DMA
//Result* func() {
//	return new Result(12, 'c');
//}
// Efficient for large objects, but requires manual memory mgmt.


// 5. using std::tuple
//std::tuple<int, double, char> res() {
//	return std::make_tuple(12, 34.65, 'a');
//}


std::tuple<int&, char&, double&> modify(std::tuple<int&, char&, double&>t) {
	std::get<0>(t) += 12;
	std::get<1>(t) = 'o';
	std::get<2>(t) -= 2;
	return t;
}

int main() {

	// 1.
	/*Data res = result();
	std::cout << res.id << " " << res.points << std::endl;*/


	// 2.
	/*Data* ptr = result();
	std::cout << ptr->id << " " << ptr->points << std::endl;
	delete ptr;*/

	// 3.
	/*Result obj = func();
	obj.display();*/

	// 4.
	/*Result* ptr = func();
	ptr->display();
	delete ptr;*/

	// 5. Using Tuple 
	/*std::tuple<int, double, char> t = res();
	std::cout << std::get<0>(t) << std::endl;
	std::cout << std::get<1>(t) << std::endl;
	std::cout << std::get<2>(t) << std::endl;*/

	//===================================== std::tuple ==========================================
	// ways to declare a tuple
	// 1
	std::tuple<float, char, int>t1 = { 10.45, 'z', 10};
	// 2
	auto t2 = std::make_tuple(12, "sumit", 9.0);
	// 3
	std::tuple<int, char, std::string>t3; // all values default initialized
	
	// 4
	int x = 19;
	double y = 34.67;
	char z = 'd';
	std::tuple<double&, int&, char&>t4 = std::tie(y, x, z); // std::tie is used to tie existing variables into a tuple of references.

	/*std::cout << std::get<0>(t4) << std::endl;
	std::cout << std::get<1>(t4) << std::endl;
	std::cout << std::get<2>(t4) << std::endl;*/

	// use case tuple+tie:
	// to pass multiple values of diff types to a function and returning the same from the funciton! 

	int p = 10;
	char q = 'd';
	double r = 3.14;

	std::tuple<int&, char&, double&>tup = modify(std::tie(p, q, r));
	// printing the tuple 'tup' returned by function 'modify()'
	std::cout << std::get<0>(tup) << std::endl;
	std::cout << std::get<1>(tup) << std::endl;
	std::cout << std::get<2>(tup) << std::endl;

	// we can also unpack using the tie :
	int& var1 = std::get<0>(tup);
	char& var2 = std::get<1>(tup);
	double& var3 = std::get<2>(tup);

	var1 = 45, var2 = 'k', var3 = 100.1;
	std::cout << "p: " << p << " q: " << q << " r: " << r << std::endl;

 	return 0;
}