#include <iostream>
#include <vector>

using namespace std;

vector<int> findPrime(int N)
{
    // 2~N 다 검사,, but sqrt(N)보다 작거나 같은 자연수에 대해서만 검사해도 됨,,
    // 반복 횟수 줄이기: iterator 초기 상태가 꼭 begin이어야 할까영,,
    vector<int> numbers; // 가운데에 추가, 삭제 어려움 -> valid bool vector
    vector<bool> valid;
    for (int i = 2; i <= N; ++i)
    {
        numbers.push_back(i);
        valid.push_back(true);
    }

    vector<int> primes{2};
    int selectedPrime = 2;
    int num_iters = 2;
    while (true)
    {
        auto it2 = valid.begin();
        for (auto it = numbers.begin(); it != numbers.end(); ++it, ++it2)
        {
            if ((*it) <= selectedPrime)
                continue;
            if ((*it2) == false)
                continue;

            const auto number = *it;
            if (number % selectedPrime == 0)
                *it2 = false;
        }

        it2 = valid.begin();
        for (auto it = numbers.begin(); it != numbers.end(); ++it, ++it2)
        {
            if ((*it) <= selectedPrime)
                continue;
            if ((*it2) == true)
            {
                selectedPrime = *it;
                primes.push_back(selectedPrime);
                break;
            }
        }

        ++num_iters;
        if (num_iters >= N)
            break;
    }

    return primes;
}

int main()
{
    // 에라토스테네스의 체: 2~N의 수 중 소수를 찾는 알고리즘
    // 입력: N
    // 동작: 반복: 나누어 떨어지는 숫자들 지우고, 안 지워진 다음 숫자를 선택

    vector<int> primesto20 = findPrime(20);
    for (const auto &elem : primesto20)
        cout << elem << ' ';

    return 0;
}