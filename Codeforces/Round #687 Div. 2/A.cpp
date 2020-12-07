#include <cstdio>
int T, n, m, r, c;
int max(int a, int b) {
    if(a > b) return a;
    return b;
}
int abs(int a) {
    if(a < 0) return -a;
    return a;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &n, &m, &r, &c);
        //int res = (r*(r-1) + (n-r)*(n-r+1) + c*(c-1) + (m-c)*(m-c+1))/2;
        int res = max(abs(r-1) + abs(c-1), abs(n-r) + abs(c-1));
        res = max(res, abs(r-1) + abs(m-c));
        res = max(res, abs(n-r) + abs(m-c));
        printf("%d\n", res);
    }
    return 0;
}