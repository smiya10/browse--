#ifndef DOM_H
#define DOM_H

#include <vector>
#include <string>
#include <unordered_map>

// Type definitions
// Represents the attributes of an element as a hash map between name and value
typedef std::unordered_map<std::string, std::string> att_map;


// Represents the DOM data structure
class node
{	
	public:
		// Constructors
		node();
		~node();	

		// Accessors
		virtual bool has_children() const;
		virtual int get_node_type() const;
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
};

// Element Class

class element: public node
{
	public:
		// Constructors
		element(std::string name, att_map attributes, 
		            std::vector<node> children);
        element(std::string name, att_map attributes);
        element(std::string name);
        
		// Accessors
		bool has_attributes() const;
		bool has_attribute(std::string name) const;        
		att_map get_attributes() const;
		std::vector<std::string> get_attribute_names() const;

		// Mutators
        void set_attribute(std::string name);
        void remove_attribute(std::string name);
        
	private:
		att_map attributes;
		
};

// Text class 

class text: public node
{
	public:
	    // Constructors
		text(std::string value);
		
		// Accessor methods
		std::string get_text();
		
	protected:
		std::string value;
};


#endif
