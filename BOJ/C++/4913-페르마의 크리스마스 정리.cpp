#include <cstdio>
#define MAX 1000010
bool prime[MAX];
int l, u, cnt1, cnt2, partial[MAX], partialSquared[MAX], tmp1, tmp2, tmp;
int main() {
    for(int i = 0; i < MAX; i++) prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    for(int i = 0; i*i < MAX; i++) {
        if(prime[i]) {
            for(int j = i*i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
    partial[0] = 0;
    partialSquared[0] = 0;
    for(int i = 1; i < MAX; i++) {
        partial[i] = partial[i-1] + prime[i];
        partialSquared[i] = partialSquared[i-1] + prime[i]*(i%4==1);
    }
    /*
    for(int i = 0; i < 100; i++) {
        if(prime[i]) printf("prime %d", i);
    }*/
    while(true) {
        scanf("%d %d", &l, &u);
        if(l == -1 && u == -1) break;
        if(u < 2) {
            printf("%d %d 0 0\n", l, u);
            continue;
        }
        tmp = l-1;
        if(tmp < 0) tmp = 0;
        cnt1 = partial[u] - partial[tmp];
        cnt2 = partialSquared[u] - partialSquared[tmp];
        printf("%d %d %d %d\n", l, u, cnt1, cnt2);
    }
    return 0;
}