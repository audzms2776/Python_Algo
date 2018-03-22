#include <iostream>
#include <string>


// https://www.acmicpc.net/problem/1316

int check_group() {
    std::string str;
    int before_check_arr[26] = { 0 };

    std::cin >> str;
    auto before_char = str[0];
    before_check_arr[before_char - 'a'] = 1;

    for (auto c : str) {
        if (before_char != c) {
            before_char = c;
            before_check_arr[c - 'a'] += 1;

            if (before_check_arr[c - 'a'] >= 2) {
                //                cout << "not" << endl;
                return 0;
            }
        }
    }

    return  1;
}

int main(int argc, char* argv[]) {
    auto num = 0;
    auto groups = 0;
    std::cin >> num;

    for (auto i = 0; i < num; ++i) {
        groups += check_group();
    }

    std::cout << groups << std::endl;
}
