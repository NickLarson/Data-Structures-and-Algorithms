#include <cmath>
#include <iostream>
#include <algorithm>

inline int parent(int i)
{
	return floor(i/2);
}

inline int left(int i)
{
	return 2*i;
}

inline int right(int i)
{
	return 2*i+1;
}

template<typename T>
void heapsort(T* array, int n) //n = heapsize
{
	//std::cout << "Array is of size: " << n << std::endl;
	buildheap(array, n);
	for(;n >= 2;)
	{
		std::swap(array[1],array[n]);
		--n;
		heapify(array, 1, n);
		//std::cout << array[1] << " ARRAY AT 1" << std::endl;
	}
}

template<typename T>
void buildheap(T* array, int n)
{
	for(int i(floor(n/2)); i >= 1; --i)
		heapify(array, i, n);
}



template<typename T>
void heapify(T* array, int k, int heapsize)
{
	int l = left(k);
	int r = right(k);
	int largest;
	if(l <= heapsize and array[l] > array[k])
		largest = l;
	else
		largest = k;
	if(r <= heapsize and array[r] > array[largest])
		largest = r;
	if(largest != k)
	{
		int tmp;
		tmp = array[k];
		array[k] = array[largest];
		array[largest] = tmp;
		heapify(array, largest, heapsize);
	}
}

