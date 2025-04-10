#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1("Hello World!");

    for (auto c : str1) // for (auto &c : str1)
    {
        c = toupper(c);
        cout << c << endl;
    }

    cout << str1 << endl;

    return 0;
}