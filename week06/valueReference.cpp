#include <iostream>
#include <array>
#include <chrono>

using namespace std;

struct LargeData
{
    array<int, 100000> data{}; // 한 번에 너무 큰 array 잡으면, 그걸 다 못 잡는 경우가 있음,,
};

void incrementByValue(int x)
{
    x++;
}

void incrementByReference(int &x)
{
    x++;
}

void incrementByPointer(int *x)
{
    (*x)++;
}

void processByValue(LargeData data)
{
    data.data[0] = 1;
}

void processByReference(LargeData &data)
{
    data.data[0] = 1;
}

template <typename F>
void benchmark(const char *label, F &&f) // 입력으로 함수 받음
{
    auto start = chrono::steady_clock::now();
    f();
    auto end = chrono::steady_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << label << ": " << elapsed.count() << " ms\n";
}

int main()
{
    // int a = 5;

    // incrementByValue(a);
    // cout << "Pass by value" << endl;
    // cout << a << endl;
    // cout << "===============" << endl;

    // incrementByReference(a);
    // cout << "Pass by reference" << endl;
    // cout << a << endl;
    // cout << "===============" << endl;

    // incrementByPointer(&a);
    // cout << "Pass by reference using a pointer" << endl;
    // cout << a << endl;
    // cout << "===============" << endl;

    LargeData bigObject;
    benchmark("processByValue", [&]()
              { processByValue(bigObject); }); // lambda: 코드를 함수로 변환하는
    benchmark("processByReference", [&]()
              { processByReference(bigObject); });
    return 0;
}