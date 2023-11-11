#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int number_of_num;
    cin >> number_of_num; // 配列のサイズを入力

    vector<int> var_numbers(number_of_num); // n要素のint型ベクトルを定義

    rep(i,number_of_num) cin >> var_numbers[i];

    bool is_contain_odd = false;

    int count = 0;
    while(1) {
        rep(i, number_of_num) {
            if (var_numbers[i] % 2 != 0) {
                is_contain_odd = true;
            }
        }

        if (is_contain_odd) {
            break;
        }

        rep(i, number_of_num) {
            var_numbers[i] /= 2;
        }
        count++;
    }

    cout << count << endl;
    
    return 0;
}