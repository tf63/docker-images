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
    int N, M;
    cin >> N >> M;
    int A[M + 1];
    prep(i, M) cin >> A[i];

    
    int now = 0;
    vector<int> votes(N + 1);
    votes[0] = 0;
    prep(i, M) {
        votes[A[i]]++;
        if (votes[A[i]] > votes[now]) {
            now = A[i];
        } else if (votes[A[i]] == votes[now]) {
            if (A[i] < now) {
                now = A[i];
            }
        }
        cout << now << endl;
    }


    return 0;

}