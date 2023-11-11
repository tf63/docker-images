#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

#define A500 500
#define B100 100
#define C50 50

int main() {
    int a, b, c, x; // abc:枚数, x:総金額
    cin >> a >> b >> c >> x;

    // 各硬貨で全パターンを列挙
    int a_money = 0;
    int b_money = 0;
    int c_money = 0;
    int match_count = 0;

    rep(i, a) {
        a_money = (i * A500);
        rep(j, b) {
            b_money = (j * B100);

            rep(k, c) {
                c_money = (k * C50);

                if ((a_money + b_money + c_money) == x) {
                    match_count++;
                }
            }
        }
    }

    cout << match_count << endl;
    
    return 0;
}