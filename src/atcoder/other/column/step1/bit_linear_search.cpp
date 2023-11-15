#include <bits/stdc++.h>
using namespace std;
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)


char int_to_alphabet(int i) {
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
} 

int alphabet_to_int(char s) {
    return s - 'a';
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    krep(i, 0, N) cin >> A[i];

    // 合計でSになるためには、どのようなパターンがあるか

    // 例えば、3枚のカード（1, 2, 3）があるとすれば
    // 1に対して「使う/使わない」がある。
    // そのため、パターンは全部で2^N通りになる
    
    // 1.これを2進数で表現
    // 2.2進数で表現したものを元に、「どれが選ばれていて、どれが選ばれていない」かを決定

    // 2^Nでループ
    krep(bin, 0, (1 << N)) {

        int total = 0;
        // iの値を2進数で表現する
        irep(j, N) {
            int wari = (1 << j);
            int digit_num = (bin / wari) % 2;
            if (digit_num == 1) {
                total += A[j];
                
            }
        }
        if (total == S) {
            cout << "Yes" << endl;
            return 0;
        }
    }  
    
    cout << "No" << endl;
    return 0;

}