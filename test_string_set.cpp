#include <iostream>
#include "string_set.hpp"
#include <fstream>
int main()
{
	using namespace std;
	string_set S(1000);
	ifstream in("second.txt");
	while(in) {
	string word;
	in >> word;
	S.insert(word);
	}
	in.close();
	ifstream in2("first.txt");
	while(in2) {
	string word;
	in2 >> word;
	S.insert(word);
	}
	in2.close();
	
	std::cout << std::string(S);
}