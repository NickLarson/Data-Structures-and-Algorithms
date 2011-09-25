#include "schedule.hpp"
#include <algorithm>
#include <string>
#include <iostream>
#include <ostream>
typedef std::pair<int,int> tpair;
typedef std::pair<int, std::string> epair;
schedule::schedule(std::pair<int,int>* time, std::pair<int, std::string>* event, int siz) : size(siz), times(new tpair[siz+1]),
events(new epair[siz+1])
{
	if(size == 0)
	{
		return;
	}
	
	for(int pos(0); pos <= size; ++pos)
	{
		times[pos] = time[pos];
		events[pos] = event[pos];
	}
	this->organize();
}
		
bool schedule::empty()
{
	if(events == NULL)
		return 1;
	else
		return 0;
}

bool schedule::organize()
{
	std::string* newEvents; //Building new arrays up
	std::pair<int, int>* newTimes; //Start from index of N = 1
	int pos = 1;
	if(times == NULL or events == NULL)
		return 0;
	//Special case met
	//Now we need to iterate through each of the arrays
	for(int k(pos); k != size; ++k)
		if(times[k].first > times[k+1].first)
		{
			std::swap(times[k], times[k+1]); //Swap the position of the times
			std::swap(events[k], events[k+1]); //Swap the positions of the events
			std::swap(events[k].first, events[k+1].first); // Swap the priority
		}
	std::cout << '\n' << events[0].second;
	std::cout << '\n';
	std::cout << events[1].second;
	return 1;
}

int main()
{
		//schedule(std::pair<int,int>* time, std::pair<int, std::string>* event, int siz);
	int size(2);
	std::pair<int, int>* times = new std::pair<int, int>[size+1];
	std::pair<int, std::string>* events = new std::pair<int, std::string>[size+1];
	std::pair<int, int> first(130, 240);
	std::pair<int, int> second(330, 350);
	std::pair<int, std::string> first1(2, "First");
	std::pair<int, std::string> second1(1, "Second");
	times[0] = first;
	times[1] = second;
	events[0] = first1;
	events[1] = second1;
	schedule::schedule(times, events, size);
	
}