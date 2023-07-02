#include <iostream>
#include <string>

int T, start, strSize, flag;
std::string str;

int calc(int s, int length, int pp) {
    if(s == length) {
        if(pp == 0 || pp == 4) return 1;
        else return 0;
    }
    if(pp == 0) {// no pattern(start)
        if(str[s] == '0') return calc(s + 1, length, -1); // 0
        else return calc(s + 1, length, 1); // 1
    }
    else if(pp == 1) { //1
        if(str[s] == '0') return calc(s + 1, length, 2); // 10
        else return 0;
    }
    else if(pp == 2) { //10
        if(str[s] == '0') return calc(s + 1, length, 3); // 100
        else return 0;
    }
    else if(pp == 3) { // 100
        if(str[s] == '0') return calc(s + 1, length, 3); // 1000
        else return calc(s + 1, length, 4); // 1001
    }
    else if(pp == 4) { // 1001
        if(str[s] == '0') return calc(s + 1, length, -1); // 10010
        else return calc(s + 1, length, 4) + calc(s + 1, length, 0) + calc(s + 1, length, 1); //10011
    }
    else {
        if(str[s] == '1') return calc(s + 1, length, 0);
        else return 0;
    }
}

int main() {
    scanf("%d ", &T);
    while(T--) {
        std::cin >> str;
        printf(calc(0, str.size(), 0)?"YES\n":"NO\n");
    }
}