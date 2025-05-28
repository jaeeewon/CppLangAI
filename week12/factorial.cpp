#include <iostream>

// 알고리즘 구성의 3요소: 입력, 출력, 계산 과정
int factorial(int n)
{
    int result = 1;
    // n! = n * (n-1) * ... * 2 * 1
    for (int i = 1; i <= n; i++)
        result *= i;

    // 혹은
    // for (int i = n; i >= 1; i--)
    //     result *= i;

    return result;
}

int factorial_rec(int n)
{
    if (n == 0)
        return 1; // base case

    return n * factorial_rec(n - 1); // recursive case
}

int main()
{
    int f5 = factorial_rec(5);
    /*
    factorial_rec(5)
    = 5 * factorial_rec(4)
    = 5 * 4 * factorial_rec(3)
    = 5 * 4 * 3 * factorial_rec(2)
    = 5 * 4 * 3 * 2 * factorial_rec(1)
    = 5 * 4 * 3 * 2 * 1 * factorial_rec(0)
    = 5 * 4 * 3 * 2 * 1 * 1
    */

    std::cout << "f5: " << f5 << std::endl;
    return 0;
}