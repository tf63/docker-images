#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    // Sの部分文字列がTに変更できるかどうかをチェック
    bool canChange = true;
    for (int i = 0; i < M; ++i) {
        if (S[i] != T[i]) {
            canChange = false;
            break; // 一つでも違う文字があれば変更不可
        }
    }

    // 結果の出力
    cout << (canChange ? "Yes" : "No") << '\n';

    return 0;
}
