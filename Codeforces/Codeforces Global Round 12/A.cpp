#include <cstdio>

int T, n;
char a[210];
char target[] = {'t', 'r', 'y', 'g', 'u', 'b'};
int cnt[27];
int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < 27; i++) cnt[i] = 0;
        scanf("%d", &n);
        scanf("%s", a);
       // printf("a: ");
        for(int i = 0; i < n; i++) {
            cnt[a[i] - 'a']++;
            //printf("%c", a[i]);
        }
        //printf("\n");
        for(int i = 0; i < 27; i++) {
            for(int j = 0; j < cnt[i]; j++) {
                printf("%c", i + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}
