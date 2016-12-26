#include "dom.h"

// Element Class

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
	
int text::node_type()
{
	return 3;
}

