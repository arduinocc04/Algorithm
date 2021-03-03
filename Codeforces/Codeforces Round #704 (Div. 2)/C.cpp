#include <cstdio>
#include <vector>
int n, m, l, r, ans, left[200010], right[200010];
char s[200010], t[200010];

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", &s);
    scanf("%s", &t);

    for(int i = 0; i < n; i++) {
        if(s[i] == t[l]) {
            left[l] = i;
            l++;
        }
        if(l == m) break;
    }

    r = m - 1;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == t[r]) {
            right[r] = i;
            r--;
        }
        //printf("r %d i %d s[i] %d t[r] %d\n", r, i, s[i], t[r]);
        if(r == -1) break;
    }

    for(int i = 0; i < m-1; i++) ans = max(ans, right[i+1] - left[i]);
    printf("%d\n", ans);
    return 0;
}
