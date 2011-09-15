#include <vector>

class ordered_set
{
public:

ordered_set() : root(0), size(0) {} //empty set
~ordered_set(){}
void insert(double x); //add x to the ordered_set
std::vector<double>* sort(); //make a sorted vector from the ordered_set
private:
public:
class node 
{
  public:
    double val;
    node* left;
    node* right;
    node(double v, node* l, node* r): val(v), left(l), right(r) {}
};
private:
node* root;
int size;

};


	
