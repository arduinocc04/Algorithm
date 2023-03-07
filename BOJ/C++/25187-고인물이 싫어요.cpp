#include <cstdio>

int N, M, Q, u, v;
int p[100'010];
int w[100'010];

int find(int n1) {
    if(n1 == p[n1]) return n1;
    int a = find(p[n1]);
    w[a] += w[n1];
    w[n1] = 0;
    return p[n1] = a;
}
void merge(int n1, int n2) {
    int p1 = find(n1);
    int p2 = find(n2);
    p[p1] = p2;
    w[p2] += w[p1];
    w[p1] = 0;
}

int main() {
    scanf("%d %d %d", &N, &M, &Q);
    for(int i = 0; i < N; i++) {
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < N; i++) if (!w[i]) w[i] = -1;
    for(int i = 0; i < N; i++) p[i] = i;
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        merge(u-1, v-1);
        printf("p: ");
        for(int j = 0; j < N; j++) {
            printf("%d ", p[j]);
        }
        printf("\n");
        printf("w: ");
        for(int j = 0; j < N; j++) {
            printf("%d ", w[j]);
        }
        printf("\n");
    }
    for(int i = 0; i < Q; i++) {
        scanf("%d", &u);
        if(w[find(u-1)] > 0) printf("1\n");
        else printf("0\n");
    }
}