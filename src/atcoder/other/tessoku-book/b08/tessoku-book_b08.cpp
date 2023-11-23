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


int grid[1509][1509] = {0};
int sum[1509][1509] = {0};
int main() {


    int N, Q;
    cin >> N;
    prep(i, N) {
        int x, y;
        cin >> x >> y;
        grid[x][y]++;
    }


    krep(i, 1, 1509) {
        krep(j, 1, 1509) {
            sum[i][j] = sum[i][j - 1] + grid[i][j];
        }
    }

    krep(i, 1, 1509) {
        krep(j, 1, 1509) {
            sum[i][j] = sum[i - 1][j] + sum[i][j];
        }
    }


    cin >> Q;
    prep(i, Q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1] << endl;
    }
    return 0;

}