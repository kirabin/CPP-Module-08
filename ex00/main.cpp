#include "easyfind.hpp"
#include <list>
#include <algorithm>
#include <iostream>
#include <map>

int main()
{
	std::list<int> l;
	std::map<std::string, int> m;

	m["1"] = 1;
	m["2"] = 2;
	m["3"] = 3;
	m["4"] = 4;

	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(2);
	l.push_back(1);


	std::cout << "Trying to find element equal to 5: " << *easyfind(l, 5) << std::endl;
	try {
		std::cout << "Trying to find element equal to 12: " << *easyfind(l, 12) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
