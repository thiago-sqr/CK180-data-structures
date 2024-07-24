/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 04-4: 07-mar-24
*
*   Implementação de busca binária que retorna a posição de inserção
*/
#include <iostream>

using namespace std;

struct Set
{
    static constexpr int SIZE = 10;
    char vector[SIZE];
    int elements;
};

int search_position(Set &S, char c)
{
    int min = 0; 
    int max = S.elements - 1;
    int mid;
    
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (S.vector[mid] == c)
        {
            return -1;
        }
        else
        {
            if (c < S.vector[mid])
            {
                max = mid - 1;
            }
            else
            {
                min = mid + 1;
            }
        }
    }

    if (c > S.vector[S.elements - 1])
    {
        return (mid + 1);
    }
    
    return mid;
}


