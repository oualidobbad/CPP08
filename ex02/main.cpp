#include "MutantStack.hpp"

int main()
{
	std::cout << "========== test mutantStack ============\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "========== test-2 copy on stack ============\n";
	std::stack<int> s;
	s = mstack;
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	std::cout << "========== test-3 test with list ============\n";
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << *(--list.end())<< std::endl;
	list.remove(*(--list.end()));
	std::cout << "size: " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator itl = list.begin();
	std::list<int>::iterator itel = list.end();
	++itl;
	--itl;
	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	return 0;
}