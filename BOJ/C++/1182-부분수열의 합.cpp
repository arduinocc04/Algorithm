#include <cstdio>

int n, s, a[30], cnt, tmp;
bool b[30];

int plusOne(int pos, bool carry) {
    if(pos > n) return 0;
    bool tmp2 = b[pos];
    b[pos] ^= true;
    if(tmp2&true) plusOne(pos+1, b[pos]&true);
    return 0;
}

bool check() {
    for(int i = 0; i < n; i++) {
        if(!b[i]) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    plusOne(0, false);
    while(!check()) {
        tmp = 0;
        for(int i = 0; i < n; i++) tmp += b[i]*a[i];
        if(tmp == s) cnt++;
        plusOne(0, false);
    }
    for(int i = 0; i < n; i++) tmp += b[i]*a[i];
    if(tmp == s) cnt++;
    printf("%d\n", cnt);
}