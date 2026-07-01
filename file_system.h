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
private:
	Node* m_root;
	Node* m_current;
};
