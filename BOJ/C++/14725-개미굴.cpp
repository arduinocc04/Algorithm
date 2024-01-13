#include <iostream>
#include <string>

int n, k;
std::string tmp_buf[20];

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> k;
        for(int j = 0; j < k; ++j) {
            std::cin >> tmp_buf[j];
        }
    }
}
