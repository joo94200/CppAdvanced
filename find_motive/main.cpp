#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        return 1;
    }
    ifstream input_text;
    input_text.open(argv[1]);
    if (input_text.fail())
    {
        cout << "The file " << argv[1] << " could not be opened.\n";
        return 1;
    }
    string str;
    int count = 0;
    while(input_text >> str)
    {
        if (str.find(argv[2]) != string::npos)
        {
            count++;
        }
    }
    cout << "The file " << argv[1] << " contains " << count << " words containing the motive " << argv[2] <<endl;
    return 0;
}