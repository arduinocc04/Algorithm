#include <iostream>
#include <string>
int T, n, l;
char start;
std::string str;


int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    std::cin >> T;
    while(T--) {
        std::cin >> n;
        std::cin >> str;
        start = str[0];
        l = str.size();
        bool flag = false;
        for(int i = 1; i < l; i++) {
            if(str[i] > start) {
                printf("Yes\n");
                flag = true;
                break;
            }
            else if(str[i] == start) {
                if(i != l -1) {
                    bool flag2 = true;
                    int j;
                    for(j = 1; j < min(l - i - 1, i); j++) {
                        if(str[i + j] < str[0 + j]) {
                            flag2 = false;
                            break;
                        }
                        else if(str[i + j] > str[0 + j]) {
                            break;
                        }
                    }
                    if(str[i + j] == str[0 + j]) flag2 = false;
                    if(flag2) {
                        flag = true;
                        printf("Yes\n");
                    }
                    break;
                }
            }
        }
        if(!flag) {
            printf("No\n");
        }

    }
}