#include <bits/stdc++.h>
using namespace std;

int main() {
    // 入力を受け取る
    long long D;
    cin >> D;

    // 探索範囲の設定
    long long x = static_cast<long long>(sqrt(D));
    long long y = 0;
    long long min_diff = abs(x * x + y * y - D);

    // xとyを調整して、x^2 + y^2がDに最も近い値を探す
    while (x >= 0 && y <= x) {
        long long current_sum = x * x + y * y;
        long long current_diff = abs(current_sum - D);

        // 最小差分を更新
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }

        // x^2 + y^2がDより大きければ、xを減らす
        if (current_sum > D) {
            --x;
        } else {
        // x^2 + y^2がDより小さければ、yを増やす
            ++y;
        }
    }

    // 最小差分を出力
    cout << min_diff << endl;

    return 0;
}
