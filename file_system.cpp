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