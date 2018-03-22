#include <iostream>
#include <string>

using namespace std;

// https://www.acmicpc.net/problem/2908
int main() {
    string str1, str2;

    cin >> str1;
    cin >> str2;

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    if (str1 > str2) {
        cout << str1;
    } else {
        cout << str2;
    }
}