#include <iostream>
#include <ostream>
#include "ordered_set.hpp"

int main()
{
	using namespace std;
	ordered_set S;
	double num;
	while(!cin.eof() and cin) {
	cin >> num;
	S.insert(num);
	}
	std::vector<double>* sorted = S.sort();
	int counter(0);
	for(std::vector<double>::iterator front(sorted->begin()); front != sorted->end(); ++front)
	{
		++counter;
		if(counter > 10)
		{
			std::cout << std::endl;
			std::cout << *front << " ";
			counter = 0;
		}
		else
			std::cout << *front << " ";
	}
			// For ease, I have sort handle printing... it also returns a vector value if that is desired
}