#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	std::cout << "pushing 1..." << std::endl;
	mstack.push(1);
	std::cout << "pushing 2..." << std::endl;
	mstack.push(2);
	std::cout << "pushing 3..." << std::endl;
	mstack.push(3);

	std::cout << "top of the stack: " << mstack.top() << std::endl;

	std::cout << "popping..." << std::endl;
	mstack.pop();

	std::cout << "size: " <<  mstack.size() << std::endl;

	std::cout << "pushing 11..." << std::endl;
	mstack.push(11);
	std::cout << "pushing 12..." << std::endl;
	mstack.push(12);
	std::cout << "pushing 13..." << std::endl;
	mstack.push(13);
	std::cout << "pushing 14..." << std::endl;
	mstack.push(14);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "stack: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl << std::endl;

	std::cout << "copying stack..." << std::endl;
	std::stack<int> s(mstack);

	std::cout << "our stack size: " << mstack.size() << "\nnew stack size: " << s.size() << std::endl;
	return 0;
}
