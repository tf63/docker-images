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
    string S;

    cin >> N;
    cin >> S;

    // 各文字のsetを用意する
    set<char> set;
    krep(i, 0, S.length()){
        set.insert(S[i]);
    }
    // 各文字の部分文字列カウントのmapを用意する
    map<char, int> chr_map;
    for (auto itr = set.begin(); itr != set.end(); ++itr) {
        chr_map[*itr] = 1;
    }


    int count = 1;
    krep(i, 1, S.length()) {
        if (S[i] == S[i - 1]) {
            count++;
            if (count > chr_map[S[i]]) {
                chr_map[S[i]]++;
            }
        } else {
            count = 1;
        }
    }

    int total = 0;
    for (auto itr = set.begin(); itr != set.end(); ++itr) {
        total += chr_map[*itr];
    }

    cout << total << endl;

    return 0;

}