#include <bits/stdc++.h>
using namespace std;
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)

#define all(v) v.begin(), v.end()

char int_to_alphabet(int i) {
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
}

int alphabet_to_int(char s) {
    return s - 'a';
}


int main() {
    int n;
    cin >> n;

    vector<int> cards(n); // n要素のint型ベクトルを定義

    krep(i, 0, n) cin >> cards[i];

    int alice = 0;
    int bob = 0;
    int is_alice = true;
    while(cards.size() != 0) {
        auto max_iterator = max_element(cards.begin(), cards.end());
        int max = *max_iterator;

        alice += is_alice ? max : 0;
        bob += is_alice ? 0 : max;
        is_alice = !is_alice;

        cards.erase(max_iterator);
    }

    cout << abs(alice - bob) << endl;

    return 0;
}