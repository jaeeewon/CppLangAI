#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// 가위바위보(묵찌빠 전 단계)에서 사용할 선택:
//  V: 찌(가위), O: 묵(바위), W: 빠(보)
// 승부 판정: V > W, O > V, W > O
int rpsResult(char a, char b)
{
    // 결과: a가 이기면 1, b가 이기면 -1, 비기면 0
    if (a == b)
        return 0;
    else if ((a == 'V' && b == 'W') ||
             (a == 'O' && b == 'V') ||
             (a == 'W' && b == 'O'))
    {
        return 1; // a가 b를 이김
    }
    return -1; // b가 a를 이김
}

// 컴퓨터가 랜덤으로 O, V, W 중 하나를 선택
char getComputerChoice()
{
    int r = rand() % 3;
    if (r == 0)
        return 'O';
    else if (r == 1)
        return 'V';
    return 'W';
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "첫 번째 라운드(가위바위보 역할) - O(묵), V(찌), W(빠) 중 하나를 입력하세요: ";

    char userChoice;
    cin >> userChoice;

    return 0;
}