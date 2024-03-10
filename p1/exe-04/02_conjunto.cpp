/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 04-2: 07-mar-24
*
*   Implementação de um conjunto limitado via vetor ordenado
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
    int min = 0;
    int max = S.elements - 1;
    while (min <= max)
    {
        int mid = (min + max) / 2;

        if (S.vector[mid] == c)
        {
            return true;
        }
        else if (c < S.vector[mid])
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
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

    bool changes = false;

    for (int i = 0; i < S.elements; i++)
    {
        if (c < S.vector[i])
        {
            for (int j = S.elements - 1; j >= i; j--)
            {
                S.vector[j + 1] = S.vector[j];
            }

            S.vector[i] = c;
            changes = true;
            break;
        }
    }

    if (!changes)
    {
        S.vector[S.elements] = c;
    }

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

                for (int j = i; j < S.elements; j++)
                {
                    S.vector[j] = S.vector[j + 1];
                }

                return true;
            }
        }
    }
    return false;
}
