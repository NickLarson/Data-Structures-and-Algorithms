/*This will be the class outline for a schedule
This schedule will be based on the universal standard
of military time*/
#include <string>

class schedule 
{
public:
/*Input expected will be (HHMM HourHourMinuteMinute)*/
	schedule(std::pair<int,int>* time, std::pair<int, std::string>* event, int siz); //Basic constructor for now...
	bool empty();																	  //Input size... lets index from 1
	bool organize();
	bool optimize();
	operator std::string();
private:
	std::pair<int, std::string>* events; //Int for priority, string for name... dont ever touch the strings
	std::pair<int,int>* times; //Index from pair 1
	int size;
};
		
		
		
		
		
		