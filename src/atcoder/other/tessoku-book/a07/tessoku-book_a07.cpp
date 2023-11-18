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
    int D, N;
    cin >> D >> N;

    vector<int> L(N), R(N);
    vector<int> daily_diffs(D);
    krep(i, 0, N) {
        // L日目からR日目まで参加する(1 <= L <= R <= D)
        cin >> L[i] >> R[i];

        // 前日比に加算
        daily_diffs[L[i] - 1] += 1;
        daily_diffs[R[i]] -= 1;
    }

    vector<int> daily_sums(D + 1);
    daily_sums[0] = 0;
    krep(i, 1, D + 1) {
        daily_sums[i] = daily_sums[i - 1] + daily_diffs[i - 1]; 
    }
    krep(i, 1, D + 1) cout << daily_sums[i] << endl;


    return 0;

}