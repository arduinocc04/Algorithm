#include <cstdio>
#include <tuple>
int n, s, y, v, tmp1, tmp2;
char cmd;
std::tuple<char, int, int> querys[200010];
bool need[200010];
int main() {
    int x = 0;
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++) {
        scanf("%c.+", cmd);
        if(cmd == 's') {
            scanf("%d %d", &tmp1, &tmp2);
            querys[i] = std::make_tuple(cmd, tmp1, tmp2);
        }
        else if(cmd == 'i') {
            scanf("%d", &tmp1);
            querys[i] = std::make_tuple(cmd, tmp1, -1);
        }
        else {
            querys[i] = std::make_tuple(cmd, -1, -1);
        }
    }
    int needForIf = -1;
    for(int i = n-1; i >= 0; i--) {
        if(std::get<0>(querys[i]) == 'i') needForIf = std::get<1>(querys[i]);
        else if(std::get<0>(querys[i]) == 's') {
            if(std::get<1>(querys[i]) != s && std::get<1>(querys[i]) != needForIf) {
                querys[i] = std::make_tuple('n', -1, -1);
            }
            else need[std::get<1>(querys[i])] = true;
        }
    }
    int prev;
    for(int i = 0; i < n; i++) {
        if(std::get<0>(querys[i]) == 'i') {
            if(need[std::get<1>(querys[i])]) {
                prev = i;
            }
            else querys[i] = std::make_tuple('n', -1, -1);
        }
        while(i < n && std::get<0>(querys[i]) == 'n') i++;
        if(std::get<0>(querys[i]) == 'e') querys[prev] = std::make_tuple('n', -1, -1);
    }
}