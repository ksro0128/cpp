#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		outfile;
	std::string		str;

	if (argc != 4)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		exit(1);
	}
	ifs.open(argv[1]);
	if (ifs.fail())
	{
		std::cout << "Infile open error" << std::endl;
		exit(1);
	}
	outfile = argv[1];
	outfile.append(".replace");
	ofs.open(outfile);
	if (ofs.fail())
	{
		std::cout << "Outfile open error" << std::endl;
		exit(1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty() == 1)
	{
		std::cout << "Do not enter empty s1" << std::endl;
		exit(1);
	}
	int s1_len = s1.length();
	int s2_len = s2.length();
	while (1)
	{
		std::getline(ifs, str);
		size_t	i = 0;
		while (1)
		{
			if (s1 == "")
				break ;
			i = str.find(argv[2], i);
			if (i == std::string::npos)
				break ;
			else
			{
				str.erase(i, s1_len);
				str.insert(i, s2);
				i += s2_len;
			}
		}
		ofs << str;
		if (ifs.eof())
			break ;
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
}
