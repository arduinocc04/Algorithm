#include <cstdio>
int n, a[1010], m, b[1010];
int increasing[1010], decreasing[1010];

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        increasing[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] <= a[j]) continue;
            increasing[i] = max(increasing[j] + 1, increasing[i]);
        }
    }
    for(int i= 0; i< n;i++) b[i] = a[n - 1 - i];
    for(int i = 0; i < n; i++) {
        decreasing[i] = 1;
        for(int j = 0; j < i; j++) {
            if(b[i] <= b[j]) continue;
            decreasing[i] = max(decreasing[j] + 1, decreasing[i]);
        }
    }
    m = -1;
    for(int i = 0; i < n; i++) {
        m = max(m, increasing[i] + decreasing[n -1 -i] -1);
    }
    printf("%d", m);
}