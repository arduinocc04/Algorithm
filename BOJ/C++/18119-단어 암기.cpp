#include <cstdio>

int cmd, n, character, m;
long long dict[10010];
long long mem;

int main() {
    scanf("%d %d", &n, &m);
    mem = (1 << 27)-1;
    for(int i = 0; i < n; i++) {
        scanf(" %c", &character);
        dict[i] |= (1 << (character - 'a'));
    }
    for(int)
}