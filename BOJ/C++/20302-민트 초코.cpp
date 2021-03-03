#include <cstdio>
#include <vector>

std::vector<int> multi, divi;
int n, tmp, prime[100'010], cnts[100'010];
char cmd;

int abs(int x) {
    if(x < 0) return -x;
    return x;
}

int main() {
    scanf("%d", &n);
    cmd = '*';
    for(int i = 0; i < 100'010; i++) cnts[i] = 0;
    for(unsigned long long i = 2; i < 100'010; i++) {
        if(prime[i] != 0) continue;
        prime[i] = i;
        for(unsigned long long j = i*i; j < 100'010; j += i) {
            if(prime[j] == 0) prime[j] = i;
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        tmp = abs(tmp);
        /*
        if(cmd == '*') multi.push_back(abs(tmp));
        else divi.push_back(abs(tmp));
        */
        while(tmp > 1) {
            cnts[prime[tmp]] += (cmd == '*')?1:-1;
            tmp /= prime[tmp];
        }
        if(i != n-1) scanf(" %c ", &cmd);
        // printf("cmd %c\n", cmd);
    }
    /*
    for(int i = 0; i < multi.size(); i++) {
        // printf("multi %d\n", multi[i]);
        while(multi[i] > 1) {
            cnts[prime[multi[i]]]++;
            multi[i] /= prime[multi[i]];
        }
    }
    for(int i = 0; i < divi.size(); i++) {
        // printf("divi %d\n", divi[i]);
        while(divi[i] > 1) {
            cnts[prime[divi[i]]]--;
            divi[i] /= prime[divi[i]];
        }
    }
    */
    for(int i = 0; i < 100'010; i++) {
        if(cnts[i] < 0) {
            printf("toothpaste\n");
            return 0;
        }
    }
    printf("mint chocolate\n");
    return 0;
}