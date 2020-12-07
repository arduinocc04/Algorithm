#include <iostream>

int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int p(int n, int r, int count = 0)
{
    if(count == r)
    {
        return 1;
    }
    return n*p(n-1, r, count+1);
}

int c(int n, int r)
{
    if(n-r < r)
    {
        r = n-r;
    }
    
}

int main()
{
    int loopNum, m, n;
    std::cin >> loopNum;
    for(int i = 0; i < loopNum; i++)
    {
        std::cin >> n >> m;
        if(n != m)
        {
            std::cout << p(m, n)/factorial(n) << '\n';
        }
        else
        {
            std::cout << 1 << '\n';
        }
    }
}