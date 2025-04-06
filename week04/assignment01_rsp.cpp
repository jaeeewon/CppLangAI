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

void getUserInputWithValidation(string message, char *userChoice)
{
    do
    {
        cout << message << "O(묵), V(찌), W(빠) 중 하나를 입력하세요: " << endl;
        cin >> *userChoice;
        *userChoice = toupper(*userChoice);
    } while (*userChoice != 'O' && *userChoice != 'V' && *userChoice != 'W');
}

string toString(char choice)
{
    switch (choice)
    {
    case 'O':
        return "묵";
    case 'V':
        return "찌";
    case 'W':
        return "빠";
    default:
        return "*";
    }
}

void printStatus(char userChoice, char compChoice)
{
    cout << "사용자: " << toString(userChoice) << ", 컴퓨터: " << toString(compChoice) << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    char userChoice, compChoice;
    int prevStatus = 0;

    do
    {
        getUserInputWithValidation("첫 번째 라운드(가위바위보 역할) - ", &userChoice);

        compChoice = getComputerChoice();
        prevStatus = rpsResult(userChoice, compChoice);

        printStatus(userChoice, compChoice);

        if (prevStatus == 1)
            cout << "사용자가 첫 공격" << endl;
        else if (prevStatus == -1)
            cout << "컴퓨터가 첫 공격" << endl;
        else
            cout << "사용자와 컴퓨터가 비겼으니 다시" << endl;

    } while (prevStatus == 0);

    bool isUserTurn = prevStatus == 1;
    int rsp = -1;

    while (rsp != 0)
    {
        string msg = "사용자의";
        msg.append((isUserTurn ? "공격" : "수비"));
        msg.append(" - ");

        getUserInputWithValidation(msg, &userChoice);

        compChoice = getComputerChoice();
        printStatus(userChoice, compChoice);

        if ((rsp = rpsResult(userChoice, compChoice)) == 0)
            cout << (isUserTurn ? "사용자" : "컴퓨터") << "승리!" << endl;
        else if (isUserTurn != (isUserTurn = rsp == 1))
            cout << "** 공격권이 변경됐어요 **" << endl;
    }

    return 0;
}