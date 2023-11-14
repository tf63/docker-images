#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    stack<char> st;

    for (char c : S) {
        if (c == 'C' && st.size() >= 2) {
            // スタックの上から2つの文字が 'A' と 'B' であるか確認
            char second = st.top(); st.pop();
            char first = st.top(); st.pop();
            if (first == 'A' && second == 'B') {
                // 'ABC' パターンを見つけたらスキップ
                continue;
            } else {
                // 'ABC' パターンではなかった場合、取り出した文字を戻す
                st.push(first);
                st.push(second);
                st.push(c);
            }
        } else {
            // それ以外の文字はスタックに積む
            st.push(c);
        }
    }

    // スタックに残った文字を結果の文字列に戻す
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // 結果の文字列を逆順にして出力
    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}
