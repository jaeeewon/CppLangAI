#include <iostream>
#include <vector>

// 원본 벡터 미변경 -> const
// 복사 불필요 -> ref
int vector_sum(const std::vector<int> &v)
{
    int result = 0;

    for (int i : v)
        result += i;

    return result;
}

// 굳이 recursive하게 할 필요 없는

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    std::cout << vector_sum(v) << std::endl;

    return 0;
}