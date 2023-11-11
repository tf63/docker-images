#include <bits/stdc++.h>
using namespace std;
#define krep(i, k, n) for (int i = k; i <= (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)

#define all(v) v.begin(), v.end()

#define SEN 1000
#define GOSEN 5000
#define MAN 10000


char int_to_alphabet(int i) {
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
}

int alphabet_to_int(char s) {
    return s - 'a';
}



bool check(int num_man, int num_gosen, int num_sen, int answer) {
    int total = (num_man * MAN) + (num_gosen * GOSEN) + (num_sen * SEN);
    if (total == answer) {
        return true;
    }
    return false;
}

int main() {
    int n, y;
    cin >> n >> y; // n枚, 合計y円
    
    // 1万円札
    for(int i = 0; i <= n; i++ ) {

        // 五千円札の枚数（1万円札と五千円札の合計枚数がmax枚数を超えないように）
        for(int j = 0; i+j <= n; j++) {

            // 千円札の枚数
            int k = (n - (i + j));

            bool result = check(i, j, k, y);
            if (result) {
                cout << i << ' ' << j << ' ' << k << endl;
                return 0;
            }
        }
    }

    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    return 0;

}