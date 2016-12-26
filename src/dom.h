#include <vector>
#include <string>
#include <unordered_map>

// Type definitions
// Represents the attributes of an element as a hash map between name and value
typedef att_map unordered_map<string, string>;


// Represents the DOM data structure

class node
{	
	public:
		node();
		~node();	
		int node_type()=0;
		string node_name()=0;

	protected:
		// Children of this node. Vector for dynamic size
		std::vector<node> children; 
}

// Element Class

// Inheritance used, per the DOM specification
class element: public node
{
	public:
		element(string name, att_map attributes, vector<node> children);
		// Accessor methods
		
	protected:
		string name;
		att_map attributes;
}

// Text class 

class text: public node
{
	public:
		text(string value);
		// Accessor methods
		
	protected:
		string value;
}
