#include "MutantStack.hpp"


int main()
{
	{
		std::cout << "Test from subject" << "\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "\nchecking if the stack has the same elements as the mutant stack\n";
		while (!s.empty()){
			std::cout << s.top() << "\n";
			s.pop();
		}
	}
	{
		std::cout << "\n\nChanged the MutantStack" << "\n";
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	{
		std::cout << "\nTest for both forward and reverse iterators in an incremental and decremental fashion\n";
		MutantStack<char> ms;
		for (int i=75; i < 80; i++)
		{
			ms.push(i);
		}

		std::cout << "Forward iteration: ";
		for (MutantStack<char>::iterator it = ms.begin(); it != ms.end(); ++it){
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Reverse iteration: ";
		for(MutantStack<char>::iterator rit = --ms.end();; --rit){
			std::cout << *rit << " ";
			if (rit == ms.begin())
				break;
		}
		std::cout << std::endl;
	}
	return 0;
}
