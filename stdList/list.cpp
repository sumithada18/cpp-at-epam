//#include <iostream>
//#include <list>
//
//// understanding std::list
//
//void printList(std::list<int>&listToPrint) {
//	for (auto& it : listToPrint) {
//		std::cout << it << " ";
//	}
//	std::cout << "\n";
//}
//
//int main() {
//
//	// all the ways - to declare list
//	std::list<int>empty; // empty list
//	std::list<int>list1 = { 1,4,7,3,9 }; // list with initializer list
//	std::list<int>list2{12,7,8};  // uniform initialization
//	std::list<int>list3(5); // list with 5 default initialized elements
//	std::list<int>list4(5, 20); // list with 5 elements all initialized with 20
//	std::list<int> list5(list4); // copy constructor
//	std::list<int>list6 = list4; // copy assignment
//	std::list<int>list7(std::move(list2)); // move constructor
//	std::list<int>list8 = std::move(list5); // move assignment operator
//
//	//insertion in front and back
//	//list1.push_back(89);
//	//list1.push_front(90);
//	//
//	//std::list<int>::iterator itr;
//	//for (itr = list1.begin(); itr != list1.end(); ++itr) {
//	//	std::cout << *itr << " ";
//	//}
//	//std::cout << "\n";
//
//	//// insertion in the middle
//	//std::list<int>::iterator it = list1.begin();
//	//std::advance(it, 2); // move iterator to 2nd index
//	//list1.insert(it, 56);
//	//std::cout << "after insertion: \n";
//	//printList(list1);
//
//	// bidirectional iteration
//	/*
//	std::cout << "first to last: \n";
//	for (auto it = list1.begin(); it != list1.end();++it) {
//		std::cout << *it << " ";
//	}
//	std::cout << "\n";
//	std::cout << "last to first: \n";
//	for (auto it = list1.rbegin(); it != list1.rend(); ++it) {
//		std::cout << *it << " ";
//	}
//	*/
//	// stable iterators
//	/*auto listItr = list1.begin();
//	list1.push_front(100);
//	std::cout << *listItr << "\n";*/ // iterator is not invalidated
//
//
//
//	//std::list<int>lis={12,99,3,55};
//	//auto listItr2 = lis.begin();
//	//std::advance(listItr2, 2); // listItr2 moves to the 2nd index
//	//auto listItr3 = listItr2;
//
//	//lis.insert(listItr3, 44);
//	//std::cout << *listItr2 << std::endl; // iterator is not invalidated
//	/*listItr2--;
//	std::cout << *listItr2 << std::endl;*/
//
//	// but when iterator to an element - whom we are deleting - iterator gets invalidated
//	/*auto newItr = lis.begin();
//	lis.pop_front();
//	std::cout << *newItr << "\n";*/ // this will cause crash!!!!
//
//	// merging two lists
//
//	std::list<int>nums1 = { 12,2,90,5 };
//	std::list<int>nums2 = { 11,1,3,33 };
//	//nums1.merge(nums2); // this will crash since the lists need to be in sorted order before we merge them!
//
//	nums1.sort();
//	nums2.sort();
//	// now it'll work fine:
//	nums1.merge(nums2);
//	//printList(nums1);
//
//
//	// std::next vs std::advance
//	// std::next - creates a new iterator. syntax: std::next(it, n);
//	// std::advance - modifies the iterator itself. syntax: std::advance(it, n);
//	// possible range of n: -list.size() < n < list.size()
//
//	std::list<char>cList{'z','x','c','v'};
//	auto iter = cList.begin();
//	std::advance(iter, 2); // iter moves to second index
//	auto iter2 = std::next(iter, -2); // iter2 is new iterator to the element that is 2 steps previous to iter
//	std::cout << "iter: "<< *iter << " iter2: "<<*iter2 << std::endl;
//
//
//	return 0;
//}