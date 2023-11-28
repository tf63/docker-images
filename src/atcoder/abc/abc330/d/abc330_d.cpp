#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> grid(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> grid[i];
    }

    int count = 0;
    // すべての 'o' を含むセルについて、それが隅の一部となる "L" 字型を探す
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'o') {
                // 同じ行にある 'o' を探す
                for (int k = 0; k < N; ++k) {
                    if (grid[i][k] == 'o' && j != k) {
                        // 同じ列にある 'o' を探す
                        for (int l = 0; l < N; ++l) {
                            if (grid[l][j] == 'o' && i != l) {
                                // 異なる行と列にある 'o' が、すでに見つかった2つの 'o' と異なる場合
                                if (grid[l][k] == 'o') {
                                    count++; // 条件を満たす三つ組をカウント
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // 各 "L" 字型について、3つの 'o' がカウントされるため、結果を3で割る
    std::cout << count / 3 << std::endl;

    return 0;
}
