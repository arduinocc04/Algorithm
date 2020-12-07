#include <cstdio>
#include <algorithm>
int histogram[100003], n, tree[400004], p[100003];

int find(int n) {
    if(p[n] == n) {
        return n;
    }
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 < n2) {
        p[n2] = n1;
    }
    else {
        p[n1] = n2;
    }
}

int main() {
    int tmp, max = 0;
    while(true) {
        scanf("%d", &n);
        if(n == 0) { return 0;}
        for(int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            histogram[i] = tmp;
        }
        std::sort(histogram, histogram + n);
        for(int i = 0; i < n; i++) {
            
        }
    }

}