#include "node.h"
#include <vector>

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