#include <iostream>

int main()
{
    char inputs[51][51], pattern[51], character;
    int loopNum;
    int j = 0;
    std::cin >> loopNum;
    for(int i = 0; i < loopNum; i++)
    {
        std::cin >> inputs[i];
    }
    for(j = 0; j < 50; j++)
    {
        character = inputs[0][j];
        for(int k = 0; k < loopNum; k++)
        {
            if(inputs[0][j] != inputs[k][j])
            {
                character = '?';
                break;
            }  
        }
        pattern[j] = character;
    }
    pattern[j+1] = '\0';
    std::cout << pattern;
    return 0;
}