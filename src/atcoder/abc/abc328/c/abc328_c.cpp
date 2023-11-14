#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;

    // 隣り合う同じ文字のペアの個数の累積和を計算する
    vector<int> prefixSum(N, 0);
    for (int i = 1; i < N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + (S[i] == S[i - 1] ? 1 : 0);
    }

    // クエリに答える
    while (Q--) {
        int l, r;
        cin >> l >> r;
        // 累積和を使って答えを計算する
        cout << prefixSum[r - 1] - prefixSum[l - 1] << endl;
    }

    return 0;
}
