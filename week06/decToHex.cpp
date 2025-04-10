#include <iostream>
#include <string>

using namespace std;

int main()
{

    const string hexdigits = "0123456789ABCDEF";
    // hexdigits[0] == "0"
    // hexdigits[1] == "1"
    // ...
    // hexdigits[9] = "9"
    // hexdigits[10] = "A"
    // hexdigits[15] = "F" // 15를 16진수로

    cout << "Enter  a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;
    string result;
    string::size_type n;

    while (cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];

    cout << "Your hex number is: " << result << endl;
    return 0;
}