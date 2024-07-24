/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 04-1: 07-mar-24
*
*   Implementação de um conjunto limitado via vetor não ordenado
*/

#include <iostream>

using namespace std;

struct Set
{
    static constexpr int SIZE = 10;
    char vector[SIZE];
    int elements;
};

void init(Set &S)
{
    S.elements = 0;
}

bool isempty(Set &S)
{
    return (S.elements == 0);
}

bool isfull(Set &S)
{
    return (S.elements == S.SIZE);
}

bool search(Set &S, char c)
{
    for (int i = 0; i < S.elements; i++)
    {
        if (S.vector[i] == c)
        {
            return true;
        }
    }
    return false;
}

bool insert_new(Set &S, char c)
{
    if (isfull(S))
    {
        return false;
    }

    S.vector[S.elements] = c;
    S.elements++;
    return true;
}

bool insert_if_new(Set &S, char c)
{
    if (!search(S, c))
    {
        if (insert_new(S, c))
        {
            return true;
        }
    }
    return false;
}

bool remove(Set &S, char c)
{
    if (search(S, c))
    {
        for (int i = 0; i < S.elements; i++)
        {
            if (S.vector[i] == c)
            {
                S.elements--;
                S.vector[i] = S.vector[S.elements];
                return true;
            }
        }
    }
    return false;
}
