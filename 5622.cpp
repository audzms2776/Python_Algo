#include <iostream>
#include <string>

using namespace std;

//https://www.acmicpc.net/problem/5622
int main(int argc, char* argv[]) {
    int number_table[26] = {
        3,3,3,
        4,4,4,
        5,5,5,
        6,6,6,
        7,7,7,
        8,8,8,8,
        9,9,9,
        10,10,10,10
    };

    string input_str;
    cin >> input_str;

    auto result = 0;

    for(auto c : input_str) {
        result += number_table[c - 'A'];
    }

    cout << result << endl;
}
