#pragma once
#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T first, int second)
{
	typename T::iterator iter = find(first.begin(), first.end(), second);

	if (iter != first.end())
		return iter;
	else
		throw std::exception();
}