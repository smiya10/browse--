#ifndef DOM_H
#define DOM_H

#include <vector>
#include <string>
#include <unordered_map>

// Type definitions
// Represents the attributes of an element as a hash map between name and value
typedef std::unordered_map<std::string, std::string> att_map;


// Node abstract base class

class node
{	
	public:
		// Constructors
		node();
		~node();	

		// Accessors
		virtual int get_node_type() const = 0;
		virtual bool has_children() const;
		virtual std::string get_name() const;
		virtual std::string get_value() const;
		virtual std::string get_content() const;
	
		// Mutators
		virtual void append_child(node& child);
		virtual void replace_child(node& replace, node& child);
		virtual void remove_child(node& child);

	protected: 
		int node_type;
		std::vector<node> children;
		std::string node_name;
		std::string node_value;
		std::string text_content;
		node* first_child;
		node* last_child;
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
