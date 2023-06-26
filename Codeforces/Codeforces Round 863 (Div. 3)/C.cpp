#include <cstdio>
#include <vector>
int T, n, b[200'010], t, tmp;
bool prevZero;
std::vector<int> res;

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        res.clear();
        for(int i = 0; i < n-1; i++) scanf("%d", &b[i]);
        t = -1;
        for(int i = 1; i < n-1; i++) {
            if(b[i -1] < b[i]) {
                t = i;
                break;
            }
        }
        if(t == -1) {
            for(int i = 0; i < n-1; i++) res.push_back(b[i]);
            res.push_back(0);
        }
        else {
            for(int i = 0; i < t; i++) res.push_back(b[i]);
            res.push_back(0);
            for(int i = t; i < n-1; i++) res.push_back(b[i]);
            for(int i = 1; i < res.size(); i++) {
                tmp = max(res[i-1], res[i]);
                if(tmp != b[i-1]) {
                    res[i] = b[i-1];
                    res[i-1] = b[i-1];
                }
            }
        }
        for(int i = 0; i < res.size(); i++) printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}
