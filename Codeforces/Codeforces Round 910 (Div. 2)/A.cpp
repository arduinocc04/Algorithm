#include <iostream>
#include <string>
int T, n, k, bCnt, aCnt;
std::string s;
int main() {
    std::cin >> T;
    while(T--) {
        std::cin >> n >> k;
        bCnt = 0;
        std::cin >> s;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B') bCnt++;
        }
        if(bCnt < k) {
            aCnt = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == 'A') aCnt++;
                if(aCnt == k - bCnt) {
                    std::cout << "1\n" << i + 1 << " B\n";
                    break;
                }
            }
        }
        else if(bCnt == k) {
            std::cout << "0\n";
        }
        else {
            int t = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == 'B') t++;
                if(t == bCnt - k) {
                    std::cout << "1\n" << i + 1 << " A\n";
                    break;
                }
            }
        }
    }
    return 0;
}
