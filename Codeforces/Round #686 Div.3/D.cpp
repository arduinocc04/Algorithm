#include <cstdio>
#define MAX 100010
int T, n, table[MAX];
int main() {
    scanf("%d", &T);
    for(int i = 0; i < MAX; i++) table[i] = i;
    for(int i = 2; i < MAX; i++) {
        if(table[i] == i) {
            for(int j = i*i; j <= MAX; j+= i) {
                table[j] = i;
            }
        }
    }
    while(T--) {
        scanf("%d", &n);
    }
}