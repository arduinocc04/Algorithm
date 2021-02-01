#include <cstdio>

int n, m, targets[110], points[110], tmp, wrong;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d", &targets[i]);
    for(int i = 0; i < m; i++) {
        wrong = 0;
        for(int j = 0; j < n; j++) {
            scanf("%d", &tmp);
            if(tmp == targets[i]) {
                points[j]++;
            }
            else wrong++;
        }
        points[targets[i]-1] += wrong;
    }
    for(int i = 0; i < n; i++) printf("%d\n", points[i]);
    return 0;
}