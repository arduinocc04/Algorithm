#include <cstdio>

unsigned long long min, max, tmp, cnt;
bool things[1000010];

int main() {
    scanf("%lld %lld", &min, &max);
    for(int i = 0; i < 1000010; i++) things[i] = true;
    for(unsigned long long i = 2; i*i <= max; i++) {
        tmp = (min/(i*i) + (min%(i*i) > 0))*i*i;
        for(unsigned long long j = tmp; j <= max; j += i*i) {
            things[j - min] = false;
        }
    }
    for(int i = 0; i < max - min+1; i++) {
        if(things[i]) cnt++;
    }
    printf("%lld\n", cnt);
}