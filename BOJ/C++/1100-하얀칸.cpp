#include <iostream>

int main()
{
    char input[9];
    int count = 0;
    for(int i = 0; i <8; i++)
    {
        std::cin >> input;
        if(i%2)
        {
            for(int k = 1; k<8; k += 2)
            {
                if(input[k] == 'F')
                {
                    count += 1;
                }
            }
        }
        else
        {
            for(int k = 0; k<8; k += 2)
            {
                if(input[k] == 'F')
                {
                    count += 1;
                }
            }
        }
        
    }
    std::cout << count<<'\n';
    return 0;
}