#include <cstdio>
#include <vector>

std::vector <int> ops;
int n, a[15], cnt;


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < 4; i++) {
        scanf("%d",&cnt);
        for(int j = 0; j < cnt; j++) {
            ops.push_back(i);
        }
    }

    return 0;
}