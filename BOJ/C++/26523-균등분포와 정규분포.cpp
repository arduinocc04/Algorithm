#include <cstdio>

float data[5010];

float abs(float x) {
    return (x>0)?x:-x;
}

void calc() {
    for(int i = 0; i < 5000; i++) {
        scanf("%f", &data[i]);
    }
    int zeroCnt = 0, halfCnt = 0, oneCnt = 0;
    for(int i = 0; i < 5000; i++) {
        if(abs(data[i] - 0.5) <= 0.25) halfCnt++;
        if(data[i] < 0.25) zeroCnt++;
        if(1 - data[i] < 0.25) oneCnt++;
    }
    // printf("%d %d %d", zeroCnt, halfCnt, oneCnt);
    if(abs(halfCnt - (zeroCnt + oneCnt)) < 500) printf("A\n");
    else printf("B\n");
}

int main() {
    for(int T = 0; T < 100; T++) {
        calc();
    }
}