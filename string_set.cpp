#include <cmath>
#include <algorithm>
#include <locale>
#include <iostream>
#include <sstream>
#include <ostream>
#include "string_set.hpp"

/*  list<std::string>* table; //array of pointers to lists of strings
	int size; //the current number of lists in the table array*/


string_set::string_set(int n) : size(n), table(new listptr[n])
{
	std::list<std::string> *test;
	for (int i = 0; i <= n; i++) {
		test = new std::list<std::string>;
		table[i] = test;
		//std::cout << table[i]->empty() << std::endl;
	}
}

string_set::~string_set()
{
	//std::cout << hash("conventional") << "\t" << hash("mental") << "\t" << hash("strangers") << "\t" << hash("walked") << std::endl;
	//std::cout << (hash("conventional") ==  hash("mental"));
	//std::cout << "destructing" << std::endl;
	for(int i =0; i <= size; i++)
	{
		delete table[i];
	}
	size = 0;
	
}
	
	
// should add the given string to the string_set if it is not already present. 
// The boolean returned should indicate whether the string_set was modified.
// void insert ( iterator position, size_type n, const T& x );
bool string_set::insert(std::string s)
{
	//std::cout << "Inserting: " << s << " hash is: " << hash(s) << std::endl;
	int new_str = hash(s);
	std::list<std::string>* curr =  table[new_str];
	std::list<std::string> ans;
	ans.push_front(s);
	if(member(s) == true)
		return false; // It was already in the table	
	if(curr == NULL) // Need to be careful with null pointers
	{
		*curr = ans;
		return true;
	}
	
	// Special cases gone
	curr->insert(curr->end(), 1, s);
	return true; // Inserted worked.
}
	
	

	
// should remove the given string from the string_set if it is present. 
// The boolean returned should indicate whether the string_set was modified.
bool string_set::remove(std::string s)
{
	//std::cout << (hash("Jameson") == hash("part")) << "\t";
	//std::cout << member("Jameson") << std::endl;
	if(member(s) == false)
	{
		return false;
	}
	// Special cases gone
	int new_str = hash(s);
	for(std::list<std::string>::iterator front(table[new_str]->begin()); front != table[new_str]->end(); ++front)
	{
		//std::cout << "Got here to delete";
		if(s == *front)
		{
			table[new_str]->erase(front);
			//std::cout << "Got here to delete";
			return true; // Just erased it from the list
		}
	}
	//std::cout << "Got here to delete";
	return false; // Went through the list, fixed.
}
	
	

	
//should return a boolean indicating whether the given string is present in the string_set.
bool string_set::member(std::string s)
{
	int new_str = hash(s);
	// That's the special case...
	for(std::list<std::string>::iterator front(table[new_str]->begin()); 
		front != table[new_str]->end(); ++front)
	{
		if(s == *front)
			//std::cout << *front << "\n";
			return true;
	}
	return false;
}
	
	

	
// in no particular order concatenated together, each followed by a newline. 
// The empty set should produce just a newline.
string_set::operator std::string()
{
	std::stringstream prnt;
	if(table == NULL)
		return "\n";
	for(int i = 0; i <= size; ++i)
	{
		if(not table[i]->empty())
			{
			for(std::list<std::string>::iterator front(table[i]->begin()); front != table[i]->end(); ++front)
				prnt << *front << " ";
			prnt << "\n";
			}
	
	}
	return prnt.str();	
}


//Use the STL hash function...
int string_set::hash(std::string s)
{
	using namespace std;
	string test = s;
	std::locale loc;                 // the "C" locale
	const collate<char>& coll = use_facet<collate<char> >(loc);
	int ans = coll.hash(test.data(),test.data()+test.length());
	ans = ans%size;
	return abs(ans);
}
	