#include "easyfind.hpp"

int main ()
{
	try{
		std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(2);
        v.push_back(22);
        v.push_back(3);
        v.push_back(44);
        v.push_back(9);
		std::cout << *easyfind(v, 3) << std::endl;
		std::cout << *easyfind(v, 30) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "value not found!" << std::endl;
	}
}