// C++ head file
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

// C head file
#include<assert.h>
#include<unistd.h>

std::string currentWorkingDir()
{
	char * buffer;

	if ((buffer = getcwd(NULL, 0)) == NULL)
	{
		std::cout << "Obtain the current working dir wrong!" << std::endl; 
		std::string str;
		return str;
	}
	
	std::string str(buffer);
	return str;
}

bool isCSV(std::string str)
{
	if (str.size() >= 4)
	{
		return str.substr(str.size()-4, str.size()-1) == ".csv";
	}
	else
		return false;
}

void printVector(std::vector<std::string> container)
{
	for (auto iter = container.begin(); iter != container.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	return;
}

std::string processingField(std::string& str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ')+1);

	str.erase(0, str.find_first_not_of('\t'));
	str.erase(str.find_last_not_of('\t')+1);

	str.erase(0, str.find_first_not_of('\r'));
	str.erase(str.find_last_not_of('\r')+1);

	str.erase(0, str.find_first_not_of('\n'));
	str.erase(str.find_last_not_of('\n')+1);
	return str;
}

void processingData(std::vector<std::string> data)
{
	return;
}
