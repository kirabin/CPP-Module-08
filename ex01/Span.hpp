#ifndef Span_hpp
# define Span_hpp
# include <iostream>
# include <algorithm>
# include <list>
# include <limits>
# include <exception>

class Span {

	public:
		Span(unsigned int capacity);
		Span(const Span& other);
		virtual ~Span();

		Span&	operator =(const Span& other);
		void	addNumber(int number);
		void	showNumbers() const;
		long	shortestSpan() const;
		long	longestSpan() const;
		void	populate(int max_value);

		std::list<int>		numbers;

		class OutOfCapacityException : public std::exception {
			const char* what() const throw();
		};

		class NoSpanToFindException : public std::exception {
			const char* what() const throw();
		};

	private:
		const unsigned int	_numbers_capacity;
		unsigned int		_numbers_stored;
};

std::ostream&	operator <<(std::ostream& out, const Span& character);

#endif
