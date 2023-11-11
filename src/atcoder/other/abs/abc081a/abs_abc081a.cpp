#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string input;
    int result = 0;

    cin >> input;

    for (int i = 0; i < 3; i++) {
        result += input[i] - '0';
    }

    cout << result << endl;
    
    return 0;
}