#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        return 1;
    }
    std::ifstream input_text;
    input_text.open(argv[1]);
    if (input_text.fail())
    {
        std::cout << "The file " << argv[1] << " could not be opened.\n";
        return 1;
    }
    std::string str;
    int count = 0;
    while(input_text >> str)
    {
        if (str.find(argv[2]) != std::string::npos)
        {
            count++;
        }
    }
    std::cout << "The file " << argv[1] << " contains " << count << " words containing the motive " << argv[2] << "\n";
    return 0;
}
