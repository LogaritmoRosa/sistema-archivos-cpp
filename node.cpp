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

Node* Node::findChild(const string& name)
{
	vector<Node*>::iterator it = m_inside.begin();
	bool found = false;

	while (it != m_inside.end() && !found)
	{
		if (name == (*it)->getName())
		{
			found = true;
		}
		else
			it++;

	}

	if (found)
		return *it;
	else
		return nullptr;
}

bool Node::removeChild(const string& name)
{
	vector<Node*>::iterator it = m_inside.begin();
	bool found = false;

	while (it != m_inside.end() && !found)
	{
		if ((*it)->getName() == name)
		{
			Node* target = *it;
			m_inside.erase(it);
			delete target;
			found = true;
		}
		else
			it++;
	}

	return found;
}

void Node::printTree(int level)
{
	for (int i = 0; i < level; i++)
		std::cout << "--";

	std::cout << m_name << std::endl;

	vector<Node*>::iterator it = m_inside.begin();

	while (it != m_inside.end())
	{
		(*it)->printTree(level + 1);
		it++;
	}
}