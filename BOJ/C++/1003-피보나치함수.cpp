#include <iostream>

void fibonacci(int n, int fibonacciList[][2])
{
    if(n == 0)
    {
        fibonacciList[n][0] = 1;
        fibonacciList[n][1] = 0;
    }
    else if(n == 1)
    {
        fibonacciList[n][0] = 0;
        fibonacciList[n][1] = 1;
    }
    else
    {
        fibonacciList[n][0] = fibonacciList[n-2][0] + fibonacciList[n-1][0];
        fibonacciList[n][1] = fibonacciList[n-2][1] + fibonacciList[n-1][1];
    }
}
int main()
{
    int fibonacciList[41][2], loopNum, b;
    for(int i = 0; i < 41; i++)
    {
        fibonacci(i, fibonacciList);
    }
    std::cin >> loopNum;
    for(int i = 0; i<loopNum; i++)
    {
        std::cin >> b;
        std::cout << fibonacciList[b][0] << ' ' << fibonacciList[b][1] << '\n';
    }
    return 0;
}