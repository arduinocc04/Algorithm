#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string src, dst; // src -> dst

    std::cin >> src;
    std::cin >> dst;

    bool dst_is_reversed = false;
    int l = 0, r = dst.size();

    while(r - l != src.size()) {
        if(dst_is_reversed) {
            if(dst[l] == 'B') {
                ++l;
                dst_is_reversed = false;
            } else { // dst[l] == 'A'
                ++l;
            }
        }
        else {
            if(dst[r - 1] == 'B') {
                --r;
                dst_is_reversed = true;
            } else { // dst[r - 1] == 'A'
                --r;
            }
        }
    }

    bool flag = true;
    if(dst_is_reversed) {
        for(int i = r - 1; i >= l; --i) {
            if(dst[i] != src[r -1 - i]) {
                flag = false;
                break;
            }
        }
    } else {
        for(int i = l; i < r; ++i) {
            if(dst[i] != src[i - l]) {
                flag = false;
                break;
            }
        }
    }

    std::cout << static_cast<int>(flag) << std::endl;
}
