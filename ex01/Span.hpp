#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <stdint.h>
#include <ctime> 

class Span
{
	private:
		std::vector<int> integers;
		unsigned int N;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int nb);
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);
		size_t shortestSpan();
		size_t longestSpan();
};

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	unsigned int count = std::distance(begin, end);
    if (integers.size() + count > N)
        throw std::length_error("Cannot add range:  would exceed Span capacity");
    while (begin != end)
    {
        integers.push_back(*begin);
        ++begin;
    }
}

