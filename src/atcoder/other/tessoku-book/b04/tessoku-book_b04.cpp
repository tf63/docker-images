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


    // int now = N;
    // krep(i, 0, 8) {
    //     int wari = (1 << i);
    //     cout << ((N / wari) % 2);
    // }

    int result = 0;
    int div = N;
    int digit = 0;
    while(div != 0) {
        result += ((1 << digit) * (div % 10));
        
        div /= 10;
        digit++;
    }

    cout << result << endl;
    return 0;

}