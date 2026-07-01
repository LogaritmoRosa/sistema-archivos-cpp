#include "file_system.h"

FileSystem::FileSystem()
{
	m_root = new Node("/", true, nullptr);
	m_current = m_root;
}

FileSystem::~FileSystem()
{
	delete m_root;
}