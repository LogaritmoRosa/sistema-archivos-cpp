#include <iostream>
#include <vector>

#include "file_system.h"
#include "node.h"

FileSystem::FileSystem()
{
	m_root = new Node("/", true, nullptr);
	m_current = m_root;
}

FileSystem::~FileSystem()
{
	delete m_root;
}

void FileSystem::pwd()
{
	std::cout << m_current->getName() << std::endl;
}

void FileSystem::ls()
{
	m_current->printChildren();
}

void FileSystem::mkdir(const string& name)
{
	Node* newDir = new Node(name, true, m_current);

	m_current->addInside(newDir);
}

void FileSystem::touch(const string& name)
{
	Node* newFile = new Node(name, false, m_current);

	m_current->addInside(newFile);
}

void FileSystem::cd(const string& name)
{
	if (name == "..")
	{
		if (m_current->getPrevious() != nullptr)
		{
			m_current = m_current->getPrevious();
		}
	}
	else
	{
		Node* target = m_current->findChild(name);

		if (target != nullptr && target->getType())
		{
			m_current = target;
		}
		else
			std::cout << "directory not found" << std::endl;
	}

}

void FileSystem::rm(const string& name)
{
	bool succes = m_current->removeChild(name);

	if (!succes)
		std::cout << "no such file or directory" << std::endl;
}

void FileSystem::tree()
{
	m_current->printTree(0);
}

void FileSystem::find(const string& name)
{
	bool success = m_current->findNode(name);

	if (success)
		std::cout << "element found" << std::endl;
	else
		std::cout << "element not found" << std::endl;
}
