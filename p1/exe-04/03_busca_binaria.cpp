/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 04-3: 07-mar-24
*
*   Implementação de busca binária recursiva
*/
#include <iostream>

using namespace std;

struct Set
{
    static constexpr int SIZE = 15;
    char vector[SIZE];
    int elements;
};

bool search(Set &S, char c, int min, int max)
{
    int mid = (min + max) / 2;

    if (min > max)
    {
        return false;
    }

    if (S.vector[mid] == c)
    {
        return true;
    }
    
    if (c < S.vector[mid])
    {
       return search(S, c, min, mid - 1);
    }
    else
    {
        return search(S, c, mid + 1, max);
    }
}
