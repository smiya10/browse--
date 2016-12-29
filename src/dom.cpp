#include "dom.h"
#include <algorithm>
// TODO: Add proper commenting

// Node class

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

void node::append_child(node& child)
{
    children.push_back(&child);    
}

void node::replace_child(node& child, node& replacement)
{
    std::vector<node*>::iterator pos;
    pos = std::find(children.begin(), children.end(), &child);
    *pos = &replacement;
    // TODO: Iron out this method
}

void node::remove_child(node& child)
{
    std::vector<node*>::iterator pos;
    pos = std::find(children.begin(), children.end(), &child);
    children.erase(pos);    
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
