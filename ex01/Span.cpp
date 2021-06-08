#include "Span.hpp"

Span::Span(unsigned int capacity) : _numbers_capacity(capacity) {
	this->_numbers_stored = 0;
}

Span::Span(const Span& other) : _numbers_capacity(other._numbers_capacity) {
	*this = other;
}

Span::~Span() {}

Span&	Span::operator =(const Span& other) {

	if (_numbers_capacity < other._numbers_capacity) {
		throw OutOfCapacityException();
	}
	this->numbers = other.numbers;
	this->_numbers_stored = other._numbers_stored;
	return *this;
}

void	Span::addNumber(int number) {
	if (_numbers_stored < _numbers_capacity) {
		if (_numbers_stored == 0) {
			numbers.push_back(number);
		} else {
			std::list<int>::iterator i;
			for (i = numbers.begin(); i != numbers.end(); i++) {
				if (number <= *i) {
					break;
				}
			}
			numbers.insert(i, number);
		}
		_numbers_stored++;
	} else {
		throw OutOfCapacityException();
	}
}

long	Span::shortestSpan() const {
	if (_numbers_stored < 2) {
		throw NoSpanToFindException();
	} else {
		long shortest_span = longestSpan();
		std::list<int>::const_iterator i = numbers.begin();
		std::list<int>::const_iterator j = numbers.begin();
		j++;
		while( j != numbers.end()) {
			if (*j - *i < shortest_span) {
				shortest_span = *j - *i;
			}
			j++;
			i++;
		}

		return (shortest_span);
	}
}

long	Span::longestSpan() const {
	if (_numbers_stored < 2) {
		throw NoSpanToFindException();
	} else {
		return ((long)numbers.back() - numbers.front());
	}
}

void	Span::populate(int max_value) {

	for (unsigned int i = _numbers_stored; i < _numbers_capacity; i++) {
		addNumber(rand() % max_value);
		// addNumber(rand());
	}
}

std::ostream&	operator <<(std::ostream& out, const Span& c) {
	for (std::list<int>::const_iterator i = c.numbers.begin(); i != c.numbers.end(); i++) {
		out << *i << " ";
	}
	return (out);
}

const char* Span::OutOfCapacityException::what() const throw() {
	return "You can't add numbers anymore, out of capacity";
}

const char* Span::NoSpanToFindException::what() const throw() {
	return "Capacity is less than 2, can't find shortest/longest span";
}
