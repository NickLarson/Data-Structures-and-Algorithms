#include <algorithm>
#include <sstream>
#include <iostream>
#include <ostream>
#include <cmath>
#include <istream>
#include "queue.hpp"

/*	int* A;	// array to store items on the queue
	int front;	// the index of the item at the front of the queue;
	int back;	// the index one more (modulo N) than  that of the back of the queue; the place put assigns its x
	int N;		// the size of the array that A currently points to */
	
	
bool queue::empty()
{
	return (front == back);
}	// return true or false according to whether the queue is empty
	
double queue::get() 
{
	double answer;
	if(empty())
	{
		throw queue_error();
	}
	else
	{
	answer = A[front];
	increment(front);
	}
	return answer;
}	// get (& remove) the value from the front of the queue and return it; throw a new queue_error() if empty
	
void queue::put(int x)
{
	if(front == N)
	{
		throw queue_error();
	}
	if(back == 0)
	{
		A[back] = x;
		increment(back);
		return;
	}
	else
	{
		A[back] = x;
		increment(back);
	}
}	// put an item at the back of the queue; if the array A is full, throw queue_error()

void queue::dump()
{
	int incrementer(front);
	while(incrementer < back)
	{
		std::cout << A[incrementer] << std::endl;
		++incrementer;
	}
} 	// (to help you fix bugs) write out the queue to standard output from front to back, one number per line