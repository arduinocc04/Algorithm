#include <cstdio>
#define MAX 1000010
char cmd;
int n, a, b, p[MAX];

int find(int n) {
    if(p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1), n2 = find(n2);
    if(n1 == n2) return;
    if(p[n1] < p[n2]) {
        p[n1] += p[n2];
        p[n2] = n1;
    }
    else {
        p[n2] += p[n1];
        p[n1] = n2;
    }
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < MAX; i++) p[i] = -1;
    while(n--) {
        scanf(" %c ", &cmd);
        if(cmd == 'I') {
            scanf("%d %d", &a, &b);
            merge(a, b);
        }
        else {
            scanf("%d", &a);
            printf("%d\n", -p[find(a)]);
        }
    }
}