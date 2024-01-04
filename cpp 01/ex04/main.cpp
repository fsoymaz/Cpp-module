#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Please give 4 argument!!" << std::endl;
		return 0;
	}
    std::string filename = argv[1];
    std::string oldWord = argv[2];
    std::string newWord = argv[3];

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(filename + ".replace");
    std::string fileContents;

    if (inputFile.is_open())
	{
        std::string line;
        while (std::getline(inputFile, line))
            fileContents += line + '\n';
        inputFile.close();
        size_t pos = 0;
        while ((pos = fileContents.find(oldWord, pos)) != std::string::npos)
		{
            fileContents.erase(pos, oldWord.length());
			fileContents.insert(pos, newWord);
            pos += newWord.length();
        }
        if (outputFile.is_open())
		{
            outputFile << fileContents;
            outputFile.close();
            std::cout << "Changed succesfully!!." << std::endl;
        }
		else
            std::cout << "The file can't open!!." << std::endl;
    }
	else
        std::cout << "The file can't open!!." << std::endl;
    return 0;
}
