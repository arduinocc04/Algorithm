#include <cstdio>

int T, n, s[10];
bool flag;

int max(int a, int b) {
    return (a>b)?a:b;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        flag = false;
        for(int i = 0; i < 4; i++) scanf("%d", &s[i]);
        if(s[0] > s[2] && s[0] > s[3] && s[1] > s[2] && s[1] > s[3]) flag = true;
        if(s[2] > s[0] && s[2] > s[1] && s[3] > s[0] && s[3] > s[1]) flag = true;
        (flag)?printf("NO\n"):printf("YES\n");
    }
    return 0;
}
