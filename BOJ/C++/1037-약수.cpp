#include <cstdio>
#include <algorithm>
int main()
{
    int a,b[50];
    scanf("%d", &a);
    for(int i = 0;i <a; i++)
    {
        scanf("%d", &b[i]);
    }
    std::sort(b, b+a);
    printf("%d\n", b[0]*b[a-1]);
}