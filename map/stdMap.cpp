#include<iostream>
#include <string>
#include<map>

//struct Student {
//	std::string _name;
//	int _id;
//	Student(int id, std::string name) : _id(id), _name(name) {
//		std::cout << "student created with name: " << _name << "\n";
//	}
//	Student(const Student& obj) {
//		std::cout << "copy called!" << "\n";
//	}
//	Student() = default; // default constructor added
//	Student& operator=(const Student& obj) {
//		std::cout << "copy assignment \n";
//		return *this;
//	}
//};




int main() {
	
	std::map<int, int>mpp; // empty map
	std::map<int, char> mpp2= { {1,'a'},{2,'b'},{3,'c'}}; // initializer list
	// printing map:
	/*for (auto& i : mpp2) {
		std::cout << "key: " << i.first << " val: " << i.second << "\n";
	}*/

	std::map<int, std::string>mpp3{{2, "sf"}, { 1,"a" }, { 4,"aegf" }, { 5,"egefq" }}; // uniform initialization(c++11)
	// printing map:
	/*for (auto& i : mpp3) {
		std::cout << "key: " << i.first << " val: " << i.second << "\n";
	}*/

	std::map<int, char>mpp4(mpp2); // copy cons..

	std::map<int, std::string>mpp5(std::move(mpp3)); // move cons...

	std::map<int, char>mpp6 = mpp4; // copy assignment

	std::map<int, std::string>mpp7 = std::move(mpp5); // move assignment 

	// insertion in map
	std::map<char, int>mci= {{'c',4}, {'a',1}, {'f',8}};
	mci.insert({'t',9});
	// or
	mci['a'] = 23; // if key does not exist - it'll create the new entry
	mci['c'] = 12; // if key alredy exists - it updates it
	//for (auto& i : mci) {
	//	std::cout << "key: " << i.first << " val: " << i.second << "\n";
	//}

	// emplace - constructs in-place
	//mci.emplace('w',18);  // emplace constrcuts the key-value pair directly
	////mci.insert('r',45)  // gives error!!! - insert requires that the pair must be already constructed
	//mci.insert({'r',45}); 
	//// or
	//mci.insert(std::make_pair('r', 45));


	/*
	std::map<int, Student>studMap;
	studMap.insert({1, Student(123, "sumit")});
	studMap.insert({2, Student(301, "sparsh")});

	// inserting using emplace
	studMap.emplace(3, Student(239, "priyanshu")); // this works but - temporary copy is created
	// studMap.emplace(4, 420, "kratik"); - incorrect syntax

	// better approach:
	studMap.emplace(
		std::piecewise_construct,
		std::forward_as_tuple(4),
		std::forward_as_tuple(420, "kratik")
	);
	*/
	/*
	when using insert: copy constructor is called - very expensive!
	1. Student(123, "sumit") is created as a temporary object.
	2. 1st copy: {1, Student(123, "sumit")} creates a std::pair<in, Student>, means Student obj. is copied into the pair
	3. 2nd copy: map needs to store this pair inside its internal structure, so it copies the Student object again.

	with emplace():
	Student(239, "priyanshu") -> is constructed then copied in map so 1 copy!

	with std::piecewise_construct
	- constructs the student object directly inside map's memory
	*/
	/*
//	studMap[6] = Student(10, "aman"); // this doesnt work - because operator[] requires a default-constructible value type

	// making default constructor inside Student, then trying again
	studMap[6] = Student(10, "aman");
	/ in the above case(using [] operator) : first temporary object is created then copy assignment is called

	*/

	//std::map<int, int>mii;
	//mii.insert(std::pair<int,int>(12, 3)); // type is deduced automatically
	//mii.insert(std::make_pair(14,8)); // explicitly defined types
	//for (const auto& it : mii) {
	//	std::cout << it.first << " " << it.second << std::endl;
	//}

	// reference binding - C++ 17 concept
	// Structured Binding (introduced in C++17) allows unpacking objects into multiple named variables in a single statement.
	
	/*for (const auto& [key, value] : mii) {
		std::cout << key << " -> " << value << "\n";
	}*/
	// or
	std::map<int, std::map<int, int>>mimii = { {2,{{4,5}, {5,6}}},{3,{{1,2},{6,7}}},{1,{{3,4},{5,9}}},{5,{{5,8},{1,1}}} };
	for (const auto& [outerKey, innerMap] : mimii) {
		std::cout << "for key: " << outerKey << "\n";
		for (const auto& [innerKey, innerVal] : innerMap) {
			std::cout << innerKey << " -> " << innerVal << std::endl;
		}
	}

	// imp: insert_or_assign() - C++17 feature
	std::map<int, std::string>mis;
	mis[5] = "crazy"; // default-constructs empty string first, then assigns - 2 steps!
	mis.insert_or_assign(6, "batman"); // directly constructs the pair - no default creation - better performance!

	/*
	emplace vs try_emplace
		emplace:
	- Constructs the value immediately (memory is allocated).
	- Then checks if key exists.
	- If key exists → value is discarded, memory is freed.

		try_emplace:
	- First checks if key exists.
	- If not, then value is constructed in-place and inserted.
	- Avoids unnecessary construction + allocation.
	*/

	mis.try_emplace(6, "batman");
	mis.try_emplace(7, "dolphin");

	for (auto& [key, val] : mis) {
		std::cout << key << " " << val << "\n";
	}

	return 0;
}
