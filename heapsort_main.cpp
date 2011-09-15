#include "heapsort.hpp"
#include <iostream>
#include <istream>
#include <ostream>

int main()
{
	using namespace std;
	int i;
	int count(1);
	cin >> i;
	int size(i);
	int* array = new int[size+1];
	while(cin >> i)
	{
		array[count] = i;
		++count;
	}
	//void buildheap(T* array, int n)
	heapsort(array, size);
	for(int i(1); i <= size; ++i)
	{
		cout << array[i] << endl;
	}
}