#ifndef MutantStack_hpp
# define MutantStack_hpp
# include <stack>
# include <list>
# include <algorithm>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>{

	public:
		MutantStack() {};
		MutantStack(const MutantStack& other) {
			*this = other;
		}
		virtual ~MutantStack() {}

		MutantStack&	operator =(const MutantStack& other) {
			std::stack<int>::operator=(other);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin() {
			return (std::stack<T>::c.begin());
		}

		iterator	end() {
			return (std::stack<T>::c.end());
		}

};

#endif
