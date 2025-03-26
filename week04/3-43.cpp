#include <iostream>

int main()
{
    int value = 0;
    std::cin >> value;

    if (value % 2 == 0)
        std::cout << "even" << std::endl;
    else
        std::cout << "Odd" << std::endl;
    return 0;
}