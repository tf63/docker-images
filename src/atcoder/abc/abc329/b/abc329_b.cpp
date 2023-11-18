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
    int N;
    cin >> N;

    int A[N];
    int max = 0;
    std::set<int> set;
    krep(i, 0, N) {
        cin >> A[i];
        set.insert(A[i]);
        if (A[i] > max) {
            max = A[i];
        }
    }

    int max_answer = 0;
    set.erase(max);
    for (auto x : set) {
        if (x > max_answer) {
            max_answer = x;
        }
    }

    cout << max_answer << endl;


    return 0;

}