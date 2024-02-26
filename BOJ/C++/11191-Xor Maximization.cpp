#include <cstdio>
#include <bitset>

int n, t;
std::bitset<61> a[100'010];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        a[i] = std::bitset<61>(t);
    }
}
