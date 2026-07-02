#include <iostream>
#include <string>
#include <vector>

#include "file_system.h"

int main()
{
	FileSystem fs;

	string command;

	while (true)
	{
		std::cout << "> ";
		std::cin >> command;

		if (command == "ls")
		{
			fs.ls();
		}
		else if (command == "pwd")
		{
			fs.pwd();
		}
		else if (command == "mkdir")
		{
			string name;

			std::cin >> name;

			fs.mkdir(name);

		}
		else if (command == "touch")
		{
			string name;

			std::cin >> name;

			fs.touch(name);

		}
		else if (command == "cd")
		{
			string name;

			std::cin >> name;

			fs.cd(name);

		}
		else if (command == "rm")
		{
			string name;

			std::cin >> name;

			fs.rm(name);
		}
		else if (command == "exit")
		{
			break;
		}
		else
		{
			std::cout << "command not found" << std::endl;
		}
	}

	return 0;
}