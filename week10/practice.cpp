#include <iostream>

using namespace std;

int main()
{
    // int password = 12345;
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int password2 = 98765;

    // cout << arr[10] << '\n';
    // cout << arr[-1] << '\n';

    // int arr[] = {
    //     0,
    //     1,
    //     2,
    //     3,
    //     4,
    //     5,
    //     6,
    //     7,
    //     8,
    //     9,
    // };
    // int *e = &arr[10]; // e가 가리키는 위치는 arr의 마지막에서 한 칸 오른쪽 위치

    // // 1번째: 포인터 b는 arr[0] 주소 가리킴
    // // 2번째: 포인터 b는 arr[1] 주소 가리킴
    // // ...
    // // 10번째: 포인터 b는 arr[9] 주소 가리킴 // 마지막
    // // b++ -> b: arr[10] == e -> 반복문 탈출
    // cout << "Using pointer arithmetic\n";
    // for (int *b = arr; b != e; b++)
    // {
    //     cout << *b << '\n';
    // }

    // cout << "Using index\n";
    // // 아래와 같은 동작
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << '\n';
    // }

    // char c1[] = {'H', 'i', '\0'};
    // // char str[] = {'C', '+', '+', '\0'};
    // char str[] = {'C', '+', '+'};

    // cout << str; // C++Hi

    char c1[] = {'H', 'i', '\0'};
    char str[4] = {'C', '+', '+', '\0'};

    cin >> str; // 3글자 이상 입력시 c1이 변경되는

    cout << str << '\n';
    cout << c1;

    // C + + \0 H i \0
    // 3글자(123) 입력시
    // 1 2 3 \0 H i \0
    // 6글자 이상(123456) 입력시
    // 1 2 3 4 5 6 \0

    // Array를 쓸 때 정신 바짝 차리고 쓰자!
    return 0;
}