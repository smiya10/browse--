#include "dom.h"

// Node classe

node::node()
{

}

node::~node()
{
    delete first_child;
    delete last_child;
}

bool node::has_children() const
{
    return children.size() != 0; // if no children, return false
}

std::string node::get_name() const
{
    return this->node_name;
}

std::string node::get_value() const
{
    return this->node_value;
}

std::string node::get_content() const
{
    return this->text_content;
}

// Element Class

/*
element::element(string name, att_map attributes, vector<node> children)
{
	this->name = name;
	this->attributes = attributes;
	this->children = children;
}

int element::node_type()
{
	return 1; // Do a proper enum?
}

// Text Class

text::text(string value)
{
	this->value = value;
}
	
int text::get_node_type()
{
	return 3;
}
*/


// TODO: if the classes become too large, consider separate implementation files
