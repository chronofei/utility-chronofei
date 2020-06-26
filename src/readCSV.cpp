#include"readCSV.h"

int main(int argc, char* argv[])
{
	std::string filename;
	std::string delimiter;

	if (argc == 3)
	{
		filename = argv[1];
		
		if (isCSV(filename))
		{
			delimiter = argv[2];

			if (delimiter.size() != 1)
			{
				std::cout << "The size of delimiter is not one, take the default value is space character! 1" << std::endl;
				delimiter = " ";
			}
		}
		else
		{
			filename = argv[2];

			if (!isCSV(filename))
			{
				std::cout << "Incorrect file name, please check!" << std::endl;
				return 1;
			}

			delimiter = argv[1];

			if (delimiter.size() != 1)
			{
				std::cout << "The size of delimiter is not one, take the default value is space character! 2" << std::endl;
				delimiter = " ";
			}
		}
	}
	else if (argc == 2)
	{
		filename = argv[1];

		if (isCSV(filename))
		{
			delimiter = " ";
		}
		else
		{
			std::cout << "Incorrect file name, please check!" << std::endl;
			return 1;
		}
	}
	else if (argc == 1)
	{
		filename = "example.csv";
		delimiter = " ";
	}
	else
	{
		std::cout << "Parameter error, please check!" << std::endl;
		return 1;
	}

	std::cout << currentWorkingDir() << std::endl;

	if (currentWorkingDir().size() != 0)
	{
		filename = currentWorkingDir() + "/" + filename;
	}
	else
	{
		std::cout << "Can't get current working path!" << std::endl;
		return 1;
	}
	std::cout << filename << std::endl;

	std::ifstream fin(filename);

	assert(fin.is_open());

	std::string line;

	while (std::getline(fin, line))
	{
		std::istringstream sin(line);
		std::vector<std::string> fields;
		std::string field;
		while (std::getline(sin, field, delimiter[0]))
		{
			processingField(field);
			fields.push_back(field);
		}

		processingData(fields);
	}

	fin.close();

	return 0;
}
