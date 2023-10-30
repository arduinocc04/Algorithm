#include <cstdio>

int n, c[2'230], max;
long long sum;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n; i++) sum += c[i];
    max = c[0];
    for(int i = 0; i < n; i++) {
        if(c[i] > max) max = c[i];
    }
    printf("%d", sum - max);
}