#include "Span.hpp"

int main()
{
	srand(time(NULL));
	Span span(5);

	try {
		span.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		span.shortestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "[0] span:  " << span << std::endl;
	span.populate(100);
	try {
		span.addNumber(2);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "[ ] span:  " << span << std::endl;
	std::cout << "rspan span2: " << span.shortestSpan() << std::endl;
	std::cout << "lspan span2: " << span.longestSpan() << std::endl << std::endl;

	Span megaspan(10000);
	megaspan.populate(std::numeric_limits<int>::max());
	std::cout << "megaspan: " << megaspan << std::endl;
	std::cout << "shortest span: " << megaspan.shortestSpan() << std::endl;
	std::cout << "longest  span: " << megaspan.longestSpan() << std::endl;


	return 0;
}
