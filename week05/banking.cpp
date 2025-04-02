/**
 * 사용자 계좌 잔액: $1000
 * 입금(잔액+) 또는 출금(잔액-)
 * 잔액보다 많은 출금 요청, 음수의 입금 또는 출금 시도
 *
 * 메뉴 출력 -> 사용자 선택(입력) -> case에 따라서 입금 코드/출금 코드
 * 입금 코드: 입금할 액수(입력) -> 무결성 검사 -> 잔액+
 * 출금 코드: 출금할 액수(입력) -> 무결성 검사 -> 잔액-
 */

#include <iostream>

using namespace std;

int main()
{
    int choice, money, balance = 1000;

    while (true)
    {
        // 메뉴 출력
        cout << "Please select an option: " << endl;
        cout << "[1] Deposit" << endl;
        cout << "[2] Withdraw" << endl;
        cout << "[3] Exit" << endl;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the amount of mony (Deposit)" << endl;
            cin >> money;
            if (money > 0)
            {
                cout << "Deposit success" << endl;
                balance += money;
                cout << "Current balance: " << balance << endl;
            }
            else
            {
                cout << "Invalid Money!" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Enter the amount of mony (Withdraw)" << endl;
            cin >> money;
            if (money > 0 && money <= balance)
            {
                cout << "Withdraw success" << endl;
                balance -= money;
                cout << "Current balance: " << balance << endl;
            }
            else
            {
                cout << "Invalid Money!" << endl;
            }
        }
        else if (choice == 3)
        {

            break; // 가장 가까운 반복문을 탈출
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}