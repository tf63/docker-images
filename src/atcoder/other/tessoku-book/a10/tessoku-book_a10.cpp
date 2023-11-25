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
    int N, D;
    cin >> N;
    int A[100009] = {0};
    prep(i, N) cin >> A[i];


    // | 1 | 2 | 3 | 4 | 5 | 6 |
    // で、3, 4号室が使えない場合、
    // 1, 2号室（先頭側）と5, 6号室（後ろ側）、それぞれのmaxがわかればいい

    // 先頭側の累積マックスを求める
    int forward_point_max[100009] = {0};
    forward_point_max[1] = A[1];
    krep(i, 2, N + 1) {
        forward_point_max[i] = max(forward_point_max[i - 1], A[i]);
    }

    // 後ろ側の累積マックスを求める
    int backward_point_max[100009] = {0};
    backward_point_max[N] = A[N];
    irep(i, N) {
        backward_point_max[i] = max(backward_point_max[i + 1], A[i]);
    }

    cin >> D;
    int l, r;
    prep(i, D) {
        cin >> l >> r;
        cout << max(forward_point_max[l - 1], backward_point_max[r + 1]) << endl;
    }    


    return 0;

}