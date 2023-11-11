#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int num1, num2;
    string result; 

    cin >> num1 >> num2;
    result = ((num1 * num2) % 2 == 0) ? "Even" : "Odd";

    cout << result << endl;
    
    return 0;
}