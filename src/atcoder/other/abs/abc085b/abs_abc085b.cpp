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

    vector<int> mochi(n); // n要素のint型ベクトルを定義
    vector<int> used_mochi;

    krep(i, 0, n) cin >> mochi[i];


    while(mochi.size() != 0) {
        auto max_iterator = max_element(mochi.begin(), mochi.end());
        int max = *max_iterator;

        auto has_it = std::find(used_mochi.begin(), used_mochi.end(), max);

        if (has_it == used_mochi.end()) {
            used_mochi.push_back(max);
        }

        mochi.erase(max_iterator);
    }

    cout << used_mochi.size() << endl;

    return 0;
}