#include <iostream>
#include <algorithm>

bool calc(int a, int b)
{
    return a>b;
}

int main()
{
    int a[50], b[50], len, c, result = 0;
    std::cin >> len;
    for(int i = 0; i < len; i++)
    {
        std::cin >> c;
        a[i] = c;
    }
    for(int i = 0; i < len; i++)
    {
        std::cin >> c;
        b[i] = c;
    }
    std::sort(a, a+len);
    std::sort(b, b+len, calc);
    for(int i = 0; i < len; i++)
    {
        result += a[i]*b[i];
    }
    std::cout << result;
}