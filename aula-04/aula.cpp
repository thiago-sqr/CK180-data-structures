/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Aula 04: 07-mar-24
 *
 *   Implementação de uma search binária.
 */

#include <iostream>

using namespace std;

struct Set
{
    char vector[10];
    int elements;
};

bool search(Set &S, char x)
{
    int min = 0;
    int max = S.elements - 1;

    while (min <= max)
    {
        int mid = (min + max) / 2;

        if (S.vector[mid] == x)
        {
            return true;
        }
        else
        {
            if (x > S.vector[mid])
            {
                min = mid + 1;
            }
            else
            {
                max = mid - 1;
            }
        }
    }
    return false;
}

void init(Set &S)
{
    S.elements = 10;
    for (int i = 0; i < S.elements; i++)
    {
        S.vector[i] = 'a' + i;
    }
}

int main()
{
    Set s;
    init(s);
    if (search(s, 'f'))
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }
}