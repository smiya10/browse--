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
		// Constructors
		node();
		~node();	

		// Accessors
		virtual bool has_children() const;
		virtual int node_type() const;
		virtual std::string get_name() const;
		virtual std::string get_value() const;
		virtual std::string get_content() const;
	
		// Mutators
		virtual void append_child(node child);
		virtual void replace_child(node replace, node child);
		virtual void remove_child(node child);

	protected:
		// TODO: Clean this up
		// Children of this node. Vector for dynamic size
		std::vector<node> children; 
		int node_type;
		std::string node_name;
		node first_child;
		node last_child;
		std::string node_value;
		std::string text_content;
}

// Element Class

// Inheritance used, per the DOM specification
class element: public node
{
	public:
		// Constructors
		element(string name, att_map attributes, vector<node> children);

		// Accessors        
		att_map get_attributes() const;

		// Mutators

	private:
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
