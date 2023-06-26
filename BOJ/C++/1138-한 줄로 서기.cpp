#include <cstdio>

int N, a[15], arr[15];
bool used[15], end;

bool calc() {
    int tmp[15];
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[i]) cnt++;
        }
        tmp[arr[i]] = cnt;
    }
    for(int i = 0; i < N; i++) {
        if(tmp[i] != a[i]) {
            return false;
        }
    }
    return true;
}

void make_permu(int idx) {
    if(end) return;
    if(idx == N) {
        if(calc()) {
            for(int i = 0; i < N; i++) {
                printf("%d ", arr[i]+1);
            }
            end = true;   
        }
    }
    for(int i = 0; i < N; i++) {
        if(!used[i]) {
            arr[idx] = i;
            used[i] = true;
            make_permu(idx + 1);
            used[i] = false;
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    make_permu(0);
}