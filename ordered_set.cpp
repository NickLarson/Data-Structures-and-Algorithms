#include <algorithm>
#include <iostream>
#include <sstream>
#include "ordered_set.hpp"


void ordered_set::insert(double x)
{
	ordered_set::node* new_root = new ordered_set::node(x, 0, 0);
	ordered_set::node* null_node = new ordered_set::node(0, 0, 0);
	ordered_set::node* curr(root);
	if(size == 0)
	{
		root = new_root;
		++size;
		return;
	}
	while(curr != NULL)
	{
		null_node = curr;
		if(x < curr->val)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if(x < null_node->val)
	{
		null_node->left = new ordered_set::node(x, 0, 0);
		++size;
	}
	else
	{
		null_node -> right = new ordered_set::node(x, 0, 0);
		++size;
	}
}

std::vector<double> answer;
void sorter(ordered_set::node*& n)
{	
	if(n != NULL)
	{
		sorter(n->left);
		answer.push_back(n->val);
		sorter(n->right);
	}
}
//void sort ( RandomAccessIterator first, RandomAccessIterator last )
	/*OutputIterator merge ( InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result )*/
						 
std::vector<double>* ordered_set::sort()
{	//Yeah, I did it ghetto... so what!
	//std::cout << "test" << std::endl;
	ordered_set::node* curr(root);
	std::vector<double> child;
	sorter(curr);
	child = answer;
	std::vector<double>* ans = new std::vector<double>(child);
	std::sort(ans->begin(),ans->end());
	return ans;
	
}
	