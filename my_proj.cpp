
//#include "test_my_list.hpp"
#include "my_list.hpp"
#include <iostream>

int main()
{
	my_list<int> list_1 {7,4,5,3,9,8};
	list_1.display();
	my_list<int>::Iterator it = list_1.begin();
	//my_list<int>::Iterator it = list_1.end();
	//std::cout << 18888 << std::endl;
	std::cout << *(it) << std::endl;
	//++it;
	//std::cout << *(it) << std::endl;
	//test_list(); // from "test_my_list.hpp"
}
