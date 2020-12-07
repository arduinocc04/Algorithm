#include <iostream>
int func(int a, int b)
{
    if(a == 0)
    {
       return b; 
    }
    int m = 0;
    for(int i = 0; i<b; i++)
    {
        m += func(a-1,b-i);
    }
    return m;
}
    
int main()
{
    int a, b, c;
    std::cin >> a;
    for(int i = 0; i <a; i++)
    {
        std::cin >> b;
        std::cin >> c;
        std::cout << func(b,c) << '\n';
    }
    return 0;
}