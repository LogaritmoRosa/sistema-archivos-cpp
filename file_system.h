#pragma once

#include "node.h"

class FileSystem
{
public:
	FileSystem();
	~FileSystem();

	Node* getRoot() { return m_root; }
	void setRoot(Node* root) { m_root = root; }

	Node* getCurrent() { return m_current; }
	void setCurrent(Node* current) { m_current = current; }

	void pwd();
	void ls();

	void mkdir(const string& name);
	void touch(const string& name);
	void cd(const string& name);

	void rm(const string& name);

	void tree();
private:
	Node* m_root;
	Node* m_current;
};
