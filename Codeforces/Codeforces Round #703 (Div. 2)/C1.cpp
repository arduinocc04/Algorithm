#include <cstdio>

int T, n, l, r, mid, ans, prev, left, right;
int main() {
    scanf("%d", &n);
    l = 1, r = n;
    printf("? %d %d\n", l, r);
    scanf("%d", &prev);
    if(n == 2) {
        printf("! %d\n", (prev == 1)?2:1);
        return 0;
    }
    while(l+1 < r) {
        mid = (l + r)/2;
        printf("? %d %d\n", l, mid);
        scanf("%d", &left);
        printf("%d %d %d\n", l, r, mid);
        fflush(stdout);
        /*
        if(l +1 == r) {
            printf("! %d\n", (left == l)?r:l);
            break;
        }*/
        if(left == prev) {
            r = mid;
        }
        else l = mid+1;
    }
    printf("! %d\n", l);
    return 0;
}
