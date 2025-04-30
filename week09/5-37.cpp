#include <fstream>
#include <iostream>
#include <string>

int main()
{
    double pi;
    double tao;

    std::string name;

    std::cout << "Enter data separated by \\n"
              << std::endl;

    std::cin >> pi;

    // 3.14\njaewon choi -> pi << 3.14, name << \n (but getline은 구분자 지워줌), tao << jaewon choi (0으로 저장)
    // --> buffer에 들어가 있는 \n 지워주기
    std::getline(std::cin, name);
    std::getline(std::cin, name);

    // std::cin >> name;

    std::cin >> tao;
    std::cout << "my name is: " << name << " tao is: " << tao << " pi is: " << pi << '\n';

    return 0;
}