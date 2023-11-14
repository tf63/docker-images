#include <bits/stdc++.h>
using namespace std;
#define krep(i, k, n) for (int i = k; i <= (int)(n); i++)

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
    int A, B;
    cin >> A >> B;

    cout << (A + B) << endl;

    return 0;

}