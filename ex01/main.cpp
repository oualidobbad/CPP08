#include "Span.hpp"

int main()
{
	std::cout <<"============= Test 1 ==============\n";
	Span sp = Span(5);

	try
	{
		try
		{
			sp.addNumber(6);
			sp.addNumber(7);
			sp.addNumber(63);
			sp.addNumber(71);
			sp.addNumber(71);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout <<"============= Test 2 ==============\n";
	Span span(100000);
	try
	{
		try
		{
			std::srand(time(NULL));
			for (int i = 0; i < 100000; i++)
				span.addNumber(rand() % 100000);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout <<"============= Test 3 ==============\n";
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(880);
	Span spp(4);
	try
	{
		spp.addNumbers(lst.begin(), lst.end());
		std::cout << spp.shortestSpan() << std::endl;
		std::cout << spp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}