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

    int divide_num = N;
    vector<int> result(10);
    int digit = 9;

    while(divide_num > 0) {
        int rem = divide_num % 2;
        result[digit] = rem;

        divide_num /= 2;
        digit--;

    }


    for (int i = 0; i < 10; i++)
    {
        cout << result[i];
    }
    
    cout << endl;
    return 0;

}