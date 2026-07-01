#include <iostream>
#include <vector>

#include "node.h"

Node::~Node()
{
	vector<Node*>::iterator it = m_inside.begin();

	while (it != m_inside.end())
	{
		delete *it;
		it++;
	}
}

void Node::addInside(Node* child)
{
	m_inside.push_back(child);
}

Node* Node::getChild(int index)
{
	return m_inside[index];
}

void Node::printChildren()
{
	vector<Node*>::iterator it = m_inside.begin();

	while (it != m_inside.end())
	{
		std::cout << (*it)->getName() << std::endl;

		it++;
	}
}