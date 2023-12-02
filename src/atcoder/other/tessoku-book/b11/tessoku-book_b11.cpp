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
    int N, Q;
    cin >> N;

    int A[100009] = {0};
    prep(i, N) cin >> A[i];

    sort(A+1, A+N+1);

    cin >> Q;
    int X;
    while(Q--) {
        cin >> X;
        int pos = lower_bound(A+1, A+N+1, X) - A;
        cout << pos - 1 << endl;
    }

    return 0;

}