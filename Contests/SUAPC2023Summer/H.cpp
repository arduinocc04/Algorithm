#include <cstdio>
#include <utility>

int n, q, l[100'010], L, sel, p[100'010];
std::pair<int, int> left, right, halfL;

std::pair<int, int> calcLeft(int i) {
    return std::make_pair(2*p[i] - l[i], 2);
}
std::pair<int, int> calcRight(int i) {
    return std::make_pair(2*p[n - 1] - 2*p[i] + l[i], 2);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &l[i]);
    scanf("%d", &L);
    scanf("%d", &q);
    p[0] = l[0];
    for(int i = 1; i < n; i++) {
        p[i] = p[i - 1] + l[i];
    }
    if(p[n - 1] <= L) {
        for(int i = 0; i < q; i++) {
            scanf("%d", &sel);
            printf("0.00\n");
        }
    }
    else {
        while(q--) {
            scanf("%d", &sel);
            sel--;
            left = calcLeft(sel);
            right = calcRight(sel);
            // printf("lr: %.2f, %.2f\n", left, right);
            if(L > left.first) printf("0.00\n");
            else if(L > right.first) printf("%d.00\n", p[n - 1] - L);
            else {
                int tmp = left.first - L;
                if(tmp % 2) {
                    printf("%d.50\n", tmp/2);
                }
                else {
                    printf("%d.00\n", tmp/2);
                }
            }
        }
    }
}