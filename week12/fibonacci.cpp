#include <iostream>

int fibonacci(int n)
{
    // 피보나치 수열: 1 1 2 3 5 8 13 21 ...
    // 정의: f_n = f_(n-2) + f_(n-1)
    //       f_0 = f_1 = 1

    if (n == 0 || n == 1)
        return 1;

    // n >= 2
    int prev = 1, prevprev = 1;
    int curr = 0;
    for (int i = 2; i <= n; i++)
    {
        // curr의 값 = f_i
        curr = prev + prevprev;
        // 한 칸씩 전으로 보내기
        // cur = f_i -> prev
        // prev - f_(i-1) -> prevprev
        prevprev = prev;
        prev = curr;
    }

    return curr;
}

int fibonacci_rec(int n)
{
    // base case: n == 0 || n == 1
    if (n == 0 || n == 1)
        return 1;

    // recursive case
    return fibonacci_rec(n - 2) + fibonacci_rec(n - 1);
    /*
    ex. n == 5;
    f(5)
    = f(3) + f(4)
    = [f(1) + f(2)] + [f(2) + f(3)]
    = [1 + (f(0) + f(1))] + [(f(0) + f(1)) + (f(1) + f(2))]
    = [1 + (1 + 1)] + [(1 + 1) + (1 + (f(0) + f(1)))]
    = 3 + [2 + (1 + (1 + 1))]
    = 3 + 5
    = 8
    */
}

int main()
{
    std::cout << "f3: " << fibonacci(3) << ", f7: " << fibonacci(7) << std::endl;
    return 0;
}