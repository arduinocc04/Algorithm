#include <cstdio>

int T, h, m, nh, nm;
int cant[6] = {3, 4, 6, 7, 9};

bool isValid(int time, int standard) {
    bool flag = true;
    for(int i = 0; i < 4; i++) if(time % 10 == cant[i]) flag = false;
    for(int i = 0; i < 4; i++) if(time / 10 == cant[i]) flag = false;
    if(!flag) return false;
    int n, k;
    n = time / 10;
    k = time % 10;
    if(n == 2) n = 5;
    else if(n == 5) n = 2;

    if(k == 2) k = 5;
    else if(k == 5) k = 2;
    time = 10*k + n;
    if(time < standard) return true;
    return false;
}

int abs(int x) {
    if(x < 0) return -x;
    return x;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &h, &m);
        scanf("%d:%d", &nh, &nm);
        if(isValid(nh, h) && isValid(nm, m)) printf("%d:%d\n", nh, nm);
        int time, time2;
        for(time = nh*h + nm; isValid(time / h, h) && isValid(time%h, m); time++);
        for(time2 = nh*h + nm; isValid(time2 / h, h) && isValid(time2%h, m); time2--);
        int tmp = nh*h + nm;
        if(abs(tmp - time) > abs(tmp - time2)) {
            printf("%02d:%02d\n", time/h, time%h);
        }
        else {
            printf("%2d:%2d\n", time2/h, time2%h);
        }
    }
    return 0;
}
