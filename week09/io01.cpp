// 사용자로부터 임의의 개수의 숫자를 입력 받아서 평균을 내는 프로그램

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Enter integers (0 to terminate): ";

    vector<int> data;
    // 숫자 입력 -> 벡터에 저장
    for (int x; cin >> x && x != 0;)
    {
        data.push_back(x);
    }

    // 평균(합 / 개수)
    double sum = 0;
    for (auto d : data)
    {
        sum += d;
    }
    double mean = sum / data.size();

    cout << "Mean: " << mean << endl;

    return 0;
}