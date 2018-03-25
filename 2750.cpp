#include <iostream>
#include <unordered_map>

// https://www.acmicpc.net/problem/1003
using namespace std;

struct fivo_value
{
    int cnt0 = 0;
    int cnt1 = 0;
};

unordered_map<int, int> fivo_map;
unordered_map<int, fivo_value> fivo_cnt;

int fivo(const int n)
{
    if(n == 0)
    {
        fivo_value fv0;
        fv0.cnt0 = 1;
        fv0.cnt1 = 0;
        fivo_cnt.insert(unordered_map<int, fivo_value>::value_type(0, fv0));

        return 0;
    }
    else if(n == 1)
    {
        fivo_value fv1;
        fv1.cnt0 = 0;
        fv1.cnt1 = 1;
        fivo_cnt.insert(unordered_map<int, fivo_value>::value_type(1, fv1));
        return 1;
    }
    else
    {
        if(fivo_map.count(n) != 0)
        {
            return fivo_map.find(n)->second;
        }
        else
        {
            auto fivo_result = fivo(n - 1) + fivo(n - 2);
            fivo_map.insert(unordered_map<int, int>::value_type(n, fivo_result));

            if(fivo_cnt.count(n) == 0)
            {
                fivo_value fv;

                const fivo_value prev1 = fivo_cnt.find(n - 1)->second;
                const fivo_value prev2 = fivo_cnt.find(n - 2)->second;

                fv.cnt0 += prev1.cnt0 + prev2.cnt0;
                fv.cnt1 += prev1.cnt1 + prev2.cnt1;

                fivo_cnt.insert(unordered_map<int, fivo_value>::value_type(n, fv));
            } 

            return fivo_result;
        }
    }
}

int main(int argc, char* argv[]) 
{
    int num;
    cin >> num;
    
    for (auto i = 0; i < num; ++i)
    {
        int input_num;
        cin >> input_num;
                   
        int result = fivo(input_num);

        const fivo_value ff = fivo_cnt.find(input_num)->second;
        cout << ff.cnt0 << " "
            << ff.cnt1 << endl;
    }
}
