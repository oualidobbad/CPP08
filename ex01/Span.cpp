#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::~Span() {}

Span::Span(const Span& other) : integers(other.integers), N(other.N) {}

Span& Span::operator=(const Span& other)
{
    if (&other != this)
    {
        N = other.N;
        integers = other.integers;
    }
    return *this;
}

void Span::addNumber(int nb)
{
    if (integers.size() >= N)
        throw std::out_of_range("Span is full:  cannot add more elements");
	else
   		integers.push_back(nb);
}

size_t Span::shortestSpan()
{
	size_t shortSpan = SIZE_MAX;
	if (integers.size() <= 1)
		throw std::runtime_error("Not enough elements to calculate span");
	std::vector<int> copy = integers;
	sort(copy.begin(), copy.end());

	std::vector<int>::iterator it = copy.begin();
	std::vector<int>::iterator it2;

	it2 = it++;
	while (it != copy.end())
	{
		size_t span = *it - *it2;
		if (span < shortSpan)
			shortSpan = span;
		it2 = it++;
	}
	return shortSpan;
}

size_t Span::longestSpan()
{
	if (integers.size() <= 1)
		throw std::runtime_error("Not enough elements to calculate span");
	std::vector<int> copy = integers;
	sort(copy.begin(), copy.end());
	return (*(copy.end() - 1) - *copy.begin());
}

