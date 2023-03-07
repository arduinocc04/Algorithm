#include <cstdio>
#include <vector>

int N, s[25][25], min = 987654321;

int abs(int x) {
    if (x > 0) return x;
    return -x;
}

int calcScore(std::vector<int> picked) {
    int res = 0;
    for(int i = 0; i < picked.size(); i++) {
        for(int j = 0; j < picked.size(); j++) {
            res += s[picked[i]][picked[j]];
        }
    }
    return res;
}

std::vector<int> counterPick(std::vector<int> picked) {
    int last = 0;
    std::vector<int> res;
    for(int i = 0; i < N; i++) {
        if(picked[last] == i) {
            last++;
        }
        else {
            res.push_back(i);
        }
    }
    return res;
}

void calc(std::vector<int> &picked, int last, int cnt) {
    if(cnt == N/2) {
        /*printf("===========picked\n");
        for(int i = 0; i < picked.size(); i++) printf("%d ", picked[i]);
        printf("===========\n");
        std::vector<int> tmp = counterPick(picked);
        printf("===========Counterpicked\n");
        for(int i = 0; i < tmp.size(); i++) printf("%d ", tmp[i]);
        printf("===========\n");*/
        int res = abs(calcScore(picked) - calcScore(counterPick(picked)));
        if (res < min) min = res;
    }
    for(int i = last + 1; i < N; i++) {
        picked.push_back(i);
        calc(picked, i, cnt + 1);
        picked.pop_back();
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    std::vector<int> tmp;
    calc(tmp, -1, 0);
    printf("%d", min);
    return 0;
}