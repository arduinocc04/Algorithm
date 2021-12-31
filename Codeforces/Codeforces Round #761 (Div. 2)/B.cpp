#include <cstdio>
int n, cnt, T, tmp, m, j;
int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0)
		return b;
	else
		return gcd(b, r);

}
int main() {
    scanf("%d", &T);    
    while(T--) {
        scanf("%d", &n);
        m = n-1;
        if(m % 2) {
            printf("%d %d 1\n", (m-1)/2, (m-1)/2+1);
        }
        else {
            j = 0;
            while(gcd(n/2-j, n/2+j) != 1) j++;
            printf("%d %d 1\n", n/2-j, n/2+j);
        }
    }
}