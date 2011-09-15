#include "binary_heap.hpp"
#include <cmath>
#include <ostream>
#include <iostream>
#include <istream>
#include <sstream>
#include <algorithm>
#include <vector>


inline int left(int i)																					//Done
{
	return 2*i;
}

inline int right(int i)																					//Done
{
	return (2*i)+1;
}

inline int parent(int i)																				//Done
{
	return floor(i/2);
}
	

priority_queue::priority_queue(int n) : A(new pair[n+1]) , heapsize(0), size(n+1) {}					//Done
priority_queue::priority_queue(int n, std::string* array, int variables) : A(new pair[n+1]), heapsize(variables), size(n+1)
{
	int i = 0;
	while(i <= variables-1)
	{
		A[i+1].object = array[i];
		A[i+1].key = i+1;
		++i;
		heapify(i+1);
	}
}

priority_queue::~priority_queue()																		//Done
{
	delete [] A;
	heapsize = 0;
	size = 0;
}


void priority_queue::heapify(int k)
{
	int smallest = A[k].key;
	int pos = k;
	if(left(k) <= heapsize and A[left(k)].key < A[pos].key)
	{
		smallest = A[left(k)].key;
		pos = left(k);
	}
	if(right(k) <= heapsize and A[right(k)].key < A[pos].key)
	{
		smallest = A[right(k)].key;
		pos = right(k);
	}
	if(pos != k)
	{
		std::swap(A[k],A[pos]);
		heapify(pos);
	}
}


bool priority_queue::empty()																			//Done
{
	return (heapsize == 0);																								
}

void priority_queue::insert(std::string s, double priority)
{
	if(heapsize == 0)
	{
		A[1].key = priority;
		A[1].object = s;
		++heapsize;
		return;
	}
	if(heapsize > size)
	{
		throw priority_queue_overflow();
	}
	//Special case taken care of
	++heapsize;
	A[heapsize].object = s;
	A[heapsize].key = priority;
	for(int i(heapsize); i > 0; i = parent(i))
	{
		if(A[i].key < A[parent(i)].key)
			std::swap(A[i], A[parent(i)]);
	}
}

std::string priority_queue::extract_min()
{
	if(heapsize == 0)
	{
		throw priority_queue_underflow();
	}
	std::string ans = A[1].object;
	A[1] = A[heapsize];
	--heapsize;
	heapify(1);
	return ans;
	
	
}

priority_queue::operator std::string()																	//Done
{
	int i(0);
	std::stringstream text;
	while(i <= heapsize)
	{
		text << A[i].object << std::endl;
		++i;
	}
	return text.str();
}