#include <cstdio>
#include <memory.h>

int c;
bool p[10'000'010];

int main() {
    memset(p, 1, 10'000'010);
    for(int i = 2; i < 10'000'010; i++) {
        if(!p[i]) continue;
        for(int j = i; i + j < 10'000'010; j += i) {
            p[i + j] = false;
        }
    }
    scanf("%d", &c); 
}