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
    int H, W, N;
    cin >> H >> W >> N;

    int a, b, c, d;
    prep(i, N) {
        cin >> a >> b >> c >> d;
        // 左上
        grid[a][b]++;
        // 右下（のひとつななめ先）
        grid[c + 1][d + 1]++;

        // 行方向の差分用
        grid[a][d + 1]--;
        // 列方向の差分用
        grid[c + 1][b]--;

    }

    // 2次元累積和の計算

    // 行方向
    prep(i, H) {
        prep(j, W) {
            sum[i][j] = sum[i][j - 1] + grid[i][j];
        }
    }    
    // 列方向
    prep(j, W) {
        prep(i, H) {
            sum[i][j] += sum[i -1][j];
        }
    }


    // 答え
    prep(i, H) {
        prep(j, W) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }  

    return 0;

}