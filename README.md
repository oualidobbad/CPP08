# CPP08

C++ Module 08: STL-compatible templates — generic container search with `easyfind`, a `Span` class with templated range insertion, and `MutantStack` exposing iterators from `std::stack`.

## Project Overview
- What it does: bridges custom classes with STL containers and algorithms through three exercises.
- Core themes: STL iterators, `std::find`, template member functions, container adapter internals.

## Architecture & Design
- **ex00 (easyfind)**: function template `easyfind(T& container, int value)` — wraps `std::find`; throws on not found.
- **ex01 (Span)**: stores up to N integers in a `std::vector<int>`.
  - `addNumber(int)`: insert one element (throws if full).
  - `addNumbers(Iterator begin, Iterator end)`: templated range insertion with capacity check.
  - `shortestSpan()` / `longestSpan()`: sort-based span computation.
- **ex02 (MutantStack)**: inherits `std::stack<T>` and exposes iterators from the underlying container (`std::deque` by default).

## Core Concepts (with code)
- Templated range insertion:
```cpp
// Span.hpp
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    unsigned int count = std::distance(begin, end);
    if (integers.size() + count > N)
        throw std::length_error("Would exceed capacity");
    while (begin != end) {
        integers.push_back(*begin);
        ++begin;
    }
}
```
- Iterator exposure from stack adapter:
```cpp
// MutantStack.hpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();  // returns this->c.begin()
    iterator end();    // returns this->c.end()
};
```

## Code Walkthrough
1) ex00: `easyfind` calls `std::find(container.begin(), container.end(), value)`; throws if iterator == end.
2) ex01: `shortestSpan()` sorts a copy, finds minimum adjacent difference. `longestSpan()` = max - min.
3) ex02: `MutantStack` accesses `std::stack::c` (protected container member) to provide `begin()`/`end()`.

## Installation & Setup
- `make` per exercise (C++98).

## Technical Deep Dive
- `std::stack` wraps a `std::deque` by default; its `c` member is `protected`, so subclasses can access it.
- `Span::shortestSpan()` is O(n log n) due to sort; could be O(n) with a different algorithm.
- `addNumbers` template works with any input iterator (vectors, lists, C arrays via pointers).

## Improvements & Future Work
- Add `const_iterator` support to MutantStack.
- Optimize `shortestSpan()` to O(n) using sorted insertion.

## Author
Oualid Obbad (@oualidobbad)