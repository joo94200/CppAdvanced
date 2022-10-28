#include <iostream>
#include <string>
#include<vector>

void is_prime(long long T)
{
    if (T < 2)
    {
        std::cout << T << " is a prime: False" << std::endl;
        return;
    }
    else if (T <= 3)
    {
    	std::cout << T << " is a prime: True" << std::endl;
	return;
    }
    if (T % 2 == 0 || T % 3 == 0)
    {
        std::cout << T << " is a prime: False" << std::endl;
        return;
    }
    long long n = 5;
    while (n * n <= T)
    {
        if (T % n == 0)
        {
            std::cout << T << " is a prime: False" << std::endl;
            return;
        }
        n++;
    }
    std::cout << T << " is a prime: True" << std::endl;
    return;
}

int main()
{
    long long prime;
    while (std::cin >> prime)
    {
        is_prime(prime);
    }
    return 0;
}
