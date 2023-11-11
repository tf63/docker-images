#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

#define DEF_MAX (10 * 10 * 10 * 10)
#define MULTIPLE 10


int sumDigits(int number) {
    int result = 0;
    while(number != 0) {
        int digit_num = number % MULTIPLE;        
        result += digit_num;
        number /= MULTIPLE;
    } 

    return result;
}
int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int result = 0;
    int div = MULTIPLE;
    
    rep(i, n) {
        int sumNumDigit = sumDigits(i);
        if (a <= sumNumDigit && sumNumDigit <= b) {
            result += i;
        }
    }

    cout << result << endl;
    return 0;
}