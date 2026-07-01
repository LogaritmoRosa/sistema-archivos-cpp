#include <iostream>
#include <string>
#include <vector>

#include "file_system.h"

int main()
{
	FileSystem fs;

	fs.mkdir("new_dir");
	fs.touch("new_file");

	fs.pwd();
	fs.ls();

	fs.cd("new_dir");
	fs.pwd();

	fs.cd("..");
	fs.pwd();

	return 0;
}