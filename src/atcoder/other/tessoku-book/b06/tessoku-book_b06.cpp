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
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> cumulative_sum_true(N + 1);
    vector<int> cumulative_sum_false(N + 1);
    cumulative_sum_true[0] = 0;
    cumulative_sum_false[0] = 0;
    krep(i, 0, N) {
        cin >> A[i];
        // 当たりのとき
        if (A[i] == 1) {
            cumulative_sum_true[i + 1] = cumulative_sum_true[i] + 1;
            cumulative_sum_false[i + 1] = cumulative_sum_false[i];
        } else {
            // はずれのとき
            cumulative_sum_true[i + 1] = cumulative_sum_true[i];
            cumulative_sum_false[i + 1] = cumulative_sum_false[i] + 1;
        }
    };

    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q); 
    krep(i, 0, Q) {
        cin >> L[i] >> R[i];

        int total_true = (cumulative_sum_true[R[i]] - cumulative_sum_true[L[i] - 1]);
        int total_false = (cumulative_sum_false[R[i]] - cumulative_sum_false[L[i] - 1]);

        string result = "draw";
        if (total_true > total_false) {
            result = "win";
        } else if (total_false > total_true) {
            result = "lose";
        }
        cout << result << endl;
    }

    return 0;

}