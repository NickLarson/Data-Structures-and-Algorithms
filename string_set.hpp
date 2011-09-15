#include <string>
#include <list>

class string_set {
  public:
	string_set(int n);
	~string_set();
	
	// should add the given string to the string_set if it is not already present. 
	// The boolean returned should indicate whether the string_set was modified.
	bool insert(std::string s); 
	
	// should remove the given string from the string_set if it is present. 
	// The boolean returned should indicate whether the string_set was modified.
	bool remove(std::string s);
	
	//should return a boolean indicating whether the given string is present in the string_set.
	bool member(std::string s);
	
	// in no particular order concatenated together, each followed by a newline. 
	// The empty set should produce just a newline.
	operator std::string();
	
private:
	typedef std::list<std::string>* listptr;
	std::list<std::string>** table; //array of pointers to lists of strings
	int size; //the current number of lists in the table array
	int hash(std::string s); //Use the STL hash function...
	
};
