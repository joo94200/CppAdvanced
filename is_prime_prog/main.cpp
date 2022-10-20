#include <iostream>
#include <string>
#include<vector>

void is_prime(long long T)
{
    if (T == 1 || T == 0)
    {
        std::cout << T << " is a prime: False" << std::endl;
        return;
    }

    for (auto i = 2; i <= T / 2; i++)
    {
        if (T % i == 0)
        {
            std::cout << T << " is a prime: False" << std::endl;
            return;
        }
    }
    std::cout << T << " is a prime: True" << std::endl;
    return;
}

int main()
{
    std::vector<long long> arr;
    std::string line;
    std::getline(std::cin, line);
    std::string tmp = "";
    for (long unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
        {
            tmp += line[i];
        }
        if (line[i + 1] == ' ' || line[i + 1] == '\0')
        {
            arr.push_back(std::stoi(tmp));
            tmp = "";
        }
    }
    for (long unsigned int i = 0; i < arr.size(); i++)
    {
        is_prime(arr[i]);
    }
    return 0;
}
