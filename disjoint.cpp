#include <sstream>
#include <istream>
#include <iostream>
#include <ostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "disjoint.hpp"

/*
  int* p;		//parent array
  int* rank;	//rank array
  listptr* set;	//array of pointers. Each set[i] is a pointer is to a list<int> containing the integers in the i'th set
  int size;		//the size i.e. maximum int that can be in a set
*/

typedef std::list<int>* listptr;

disjoint_sets::disjoint_sets(int n) : p(new int[n+1]), rank(new int[n+1]), set(new listptr[n+1]), size(n) {}
//n is the maximum int that can be in a set, so arrays need to be of size n+1

disjoint_sets::~disjoint_sets()
{
	delete [] p;
	delete [] rank;
	for(int i(1); i <= size; ++i)
	{
		if(set[i] != NULL)
			delete set[i];
	}
	delete [] set;
	size = 0;
}

bool disjoint_sets::make_set(int n)
{
	if(p[n] != 0)
		return false;
	p[n] = n;
	std::list<int> insert;
	insert.push_front(n);
	//std::cout << insert.front() << std::endl;
	set[n] = new std::list<int>(insert);
	return true;
}


int disjoint_sets::find_set(int u)
{
	if(p[u] != u)
		p[u] = find_set(p[u]);
	return p[u];
}

bool disjoint_sets::union_set(int u, int v)
{
	u = find_set(u);
	v = find_set(v);
	if(p[u] == 0 or p[v] == 0)
		return false;
	if(rank[u] < rank[v])
	{
	//std::cout << "is the rank of u < v? " << (rank[u] < rank[v]) << " for " << u << " and " << v << std::endl;
		p[u] = v;
		set[u]->back() = set[v]->front();
		set[v]->front() = set[u]->back();
		return true;
	}
	else if(rank[u] > rank[v])
	{
		//std::cout << "is the rank of u > v? " << (rank[u] > rank[v]) << " for " << u << " and " << v << std::endl;
		(*set[v]).insert(set[v]->begin(), set[u]->begin(), set[u]->end());
		(*set[u]).clear();
		(*set[u]).insert(set[u]->begin(), set[v]->begin(), set[v]->end());
		p[v] = u;
		return true;
	}
	else if(u == v)
	{
		return true;
	}
	else if(rank[u] == rank[v])
	{
		/*std::cout << "is the rank of u == to v? " << (rank[u] == rank[v]) << " for " << u << " and " << v << std::endl;
		//void insert ( iterator position, InputIterator first, InputIterator last );
		std::cout << "The end of the list is " << (*set[u]).front() << std::endl;
		std::cout << "The end of the list V is " << (*set[v]).front() << std::endl;*/
		(*set[u]).insert(set[u]->end(), set[v]->begin(), set[v]->end());
		(*set[v]).clear();
		(*set[v]).insert(set[v]->begin(), set[u]->begin(), set[u]->end());
		//std::cout << "The end of the list is " << (*set[v]).front() << std::endl;
		//(*set[u]).front() = (*set[v]).back();
		p[v] = u;
		++rank[v];
		return true;
	}
}

void disjoint_sets::print_set(std::ostream& out, int u)
{
	std::stringstream text;
	u = find_set(u);
	std::list<int> ls = *set[u];
	text << "{";
	for(std::list<int>::const_iterator front(ls.begin()); front != ls.end(); ++front)
		text << *front << ", ";
	text << "}, ";
	out << text.str();
}//e.g. { 1, 2, 4, 8, 10, }


disjoint_sets::operator std::string()
{
	std::string text;
	std::cout << "{ ";
	for(int i(1); i < size; ++i)
	{
		if(p[i] == i)
			print_set(std::cout, i);
	}
	std::cout << " }";
	return text;
}
//e.g. "{ { 1, 2, 4, 8, 10, }, { 3, 6, }, { 5, }, { 7, }, { 9, }, }"