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
    int N, Q;
    cin >> N >> Q;

    // 各日の来場者数を入力しながら、累積和を算出
    vector<int> A(N);
    vector<int> cumulative_sum(N + 1);
    cumulative_sum[0] = 0;
    krep(i, 0, N) {
        cin >> A[i];
        cumulative_sum[i + 1] = cumulative_sum[i] + A[i];
    }



    vector<int> L(Q), R(Q);
    krep(i, 0, Q) {
        cin >> L[i] >> R[i];
        cout << (cumulative_sum[R[i]] - cumulative_sum[L[i] - 1]) << endl;
    };


    return 0;

}