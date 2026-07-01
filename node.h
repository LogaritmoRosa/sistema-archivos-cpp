#pragma once

#include <string>
#include <vector>

using namespace std;

class Node
{
public:
	Node() : m_name(""), m_type(false), m_previous(nullptr) {};
	Node(const string& name, bool type, Node* previous) :
		m_name(name), m_type(type), m_previous(previous) {};

	~Node();

	string getName() { return m_name; }
	void setName(const string& name) { m_name = name; }

	bool getType() { return m_type; }
	void setType(bool type) { m_type = type; }

	Node* getPrevious() { return m_previous; }
	void setPrevious(Node* previous) { m_previous = previous; }

	void addInside(Node* child);
	Node* getChild(int index);

	void printChildren();
private:
	string m_name;
	bool m_type;
	vector<Node*> m_inside;
	Node* m_previous;
};