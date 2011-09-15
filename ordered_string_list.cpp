#include <sstream>
#include <iostream>
#include <ostream>
#include <istream>
#include "ordered_string_list.hpp"

ordered_string_list::~ordered_string_list()
{
	delete first;
	delete last;
	count = 0;
}

int ordered_string_list::size()
{
	return count;
}

ordered_string_list::operator std::string()
{
	node* curr(first);
		std::stringstream text;
		while (curr != 0)
		{
			text << curr->val << std::endl;
			curr = curr->next;
		}
	return text.str();
}



ordered_string_list::node* ordered_string_list::find(std::string s) const
{
	node* curr(first);
	while (curr != 0 and curr->val < s)
	{
		curr = curr->next;
	}
	return curr;
}

bool ordered_string_list::member(std::string s) const 
{
	node* curr(first);
	while (curr != 0 and curr->val != s)
		curr = curr->next;
	if(curr != 0)
		return curr->val == s;
	else
		return false;
	
}

//(std::string s, node* p, node* n)
//ordered_string_list() : count(0), first(0), last(0)
void ordered_string_list::insert(std::string s)
{
	ordered_string_list::node* curr(first);
	if (curr == NULL) // List is empty, check
	{
		node* inserter = new node(s, 0, 0);
		first = inserter;
		last = inserter;
		++count;
		return;
	}
	if (first == last) // Only 1 node, 
	{
		node* inserter = new node(s, curr, 0);
		first->next = inserter;
		last = inserter;
		++count;
		return;
	}
	while (curr->val < s and curr != last)
		curr = curr->next;
	if (curr == last)
	{
		if(curr->val > s)
		{
		node* inserter = new node(s, curr->prev, curr);
		curr->prev->next = inserter;
		curr->prev = inserter;
		++count;
		return;
		}
		else
		{
		node* inserter = new node(s, curr, 0);
		curr->next = inserter;
		last = inserter;
		++count;
		return;
		}
	}
	if (curr == first)
	{
		node* inserter = new node(s, 0, curr);
		curr->prev = inserter;
		first = inserter;
		++count;
		return;
	}
	node* inserter = new node(s, curr->prev, curr);
	curr->prev->next = inserter;
	curr->prev = inserter;
	++count;
}

bool ordered_string_list::remove(std::string s)
{
	ordered_string_list::node* current(first);
	if(current == 0) //No Nodes
	{
		return false;
	}
	if(first == last) //Only 1 Node
	{
		if(first->val == s)
			{
			first = 0;
			last = 0;
			count = 0;
			return true;
			}
		else
			return false;
	}
	while(current != last and current->val != s)
		current = current->next;
	if(current == last)
	{
		if(current->val == s)
			{
			current->prev->next = 0;
			--count;
			last = current->prev;
			return true;
			}
		else
			return false;
	}
	//Special cases taken care of
	else
	{
	if(current == first) //this can happen!
		{
		first = current->next;
		current->next->prev = 0;
		--count;
		return true;
		}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	--count;
	return true;
	}
}
	