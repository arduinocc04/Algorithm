#include <cstdio>

int n, r, c, cnt;

int pow(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) res *= a;
    return res;
}

int find(int r, int c, int n) {
    if(n == 0) return 0;
    int tmp = pow(2, n-1);
    bool flag1 = r >= tmp, flag2 = c >= tmp;
    if(!flag1 && !flag2) {
        return 0 + find(r, c, n - 1);
    }
    else if(!flag1 && flag2) {
        return tmp*tmp + find(r, c - tmp, n - 1);
    }
    else if(flag1 && !flag2) {
        return tmp*tmp*2 + find(r - tmp, c, n - 1);
    }
    else {
        return tmp*tmp*3 + find(r - tmp, c - tmp, n - 1);
    }
}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    printf("%d", find(r, c, n));
}