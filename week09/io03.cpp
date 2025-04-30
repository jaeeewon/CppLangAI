// 파싱

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Record
{
    int id;
    double value;
    string label;
};

int main()
{
    string line = "42,3.14,hi";
    stringstream ss(line);

    Record rec;

    char comma;

    // 0: ss -< "42,3.14,hi"
    // rec.id 후 ss <- ",3.14,hi"
    // comma 후 ss <- "3.14,hi"
    // rec.value 후 ss <- ",hi"
    // comma 후 ss <- "hi"
    ss >> rec.id >> comma >> rec.value >> comma >> rec.label;
    // 구분자 없이 이렇게도 파싱할 수 있음

    // 혹은 반복문을 이용해서
    // comma 검사해서 ','이면 계속, 다르면 에러

    cout << "id: " << rec.id << '\n'
         << "value: " << rec.value << '\n'
         << "label: " << rec.label;

    return 0;
}