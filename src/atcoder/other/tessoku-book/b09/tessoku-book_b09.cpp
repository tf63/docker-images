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


int sum[1509][1509] = {0};
int grid[1509][1509] = {0};
int main() {
    int N;
    cin >> N;

    int a, b, c, d;
    prep(i, N) {
        cin >> a >> b >> c >> d;
        sum[a][b]++;
        sum[c][d]++;

        // 行調整
        sum[c][b]--;
        // 列調整
        sum[a][d]--;
    }

    // 2次元累積和の計算

    // 行方向
    krep(i, 0, 1509) {
        krep(j, 1, 1509) {
            sum[i][j] += sum[i][j - 1];
        }
    }

    // 列方向
    krep(j, 0, 1509) {
        krep(i, 1, 1509) {
            sum[i][j] += sum[i - 1][j];
        }
    }

    int result = 0;
    krep(i, 0, 1509) {
        krep(j, 0, 1509) {
            if (sum[i][j] >= 1) {
                result++;
            }
            
        }
    }
    cout << result << endl;

    return 0;

}