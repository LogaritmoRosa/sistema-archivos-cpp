#include <iostream>
#include <string>
#include <vector>

#include "node.h"

int main()
{
	Node* root = new Node("/", true, nullptr);
	Node* folder = new Node("my_folder", true, root);
	Node* file = new Node("file.txt", false, root);

	root->addInside(folder);
	root->addInside(file);

	std::cout << root->getChild(0)->getName() << std::endl;

	delete root;
	root = nullptr;

	return 0;
}