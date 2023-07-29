#include <iostream>
#include <string>
int n;
bool flag, flag1, flag2;
std::string s;
int main() {
    std::cin >> n;
    std::cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'A') flag = true;
        else if(s[i] == 'B') flag1 = true;
        else flag2 = true;
        if(flag == flag1 &&flag1 == flag2 && flag == true) {
            std::cout << i  + 1;
            return 0;
        }
    }
    return 0;
}
