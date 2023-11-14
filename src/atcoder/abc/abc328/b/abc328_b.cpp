#include <iostream>
#include <vector>
#include <set>

int main() {
    int N;
    std::cin >> N; // Nを入力

    int count = 0; // ゾロ目の日数をカウントする変数

    for (int i = 1; i <= N; ++i) {
        int Di;
        std::cin >> Di; // 各月の日数を入力

        for (int j = 1; j <= Di; ++j) {
            // iとjを十進法で表すために、各桁の数字を取得
            std::set<int> digits;
            int temp_i = i;
            int temp_j = j;

            while (temp_i > 0) {
                digits.insert(temp_i % 10);
                temp_i /= 10;
            }

            while (temp_j > 0) {
                digits.insert(temp_j % 10);
                temp_j /= 10;
            }

            // digitsのサイズが1の場合（1種類の数字だけを使用して表せる場合）、ゾロ目の日としてカウント
            if (digits.size() == 1) {
                count++;
            }
        }
    }

    std::cout << count << std::endl; // ゾロ目の日数を出力

    return 0;
}