/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 05-1: 11-mar-24
*
*   Implementação de um dicionário limitado via vetor
*/
#include <iostream>

using namespace std;

struct Pair
{
    int key;
    string value;
};

struct Dict
{
    static constexpr int SIZE = 5;
    Pair entries[SIZE];
    int elements;
};

void init(Dict &d)
{
    d.elements = 0;
}

string query(Dict &d, int key)
{
    for (int i = 0; i < d.elements; i++)
    {
        if (d.entries[i].key == key)
        {
            return d.entries[i].value;
        }
    }
    return "\0";
}

bool insert(Dict &d, int key, string value)
{
    // Caso a chave já exista, o valor é sobrescrito
    for (int i = 0; i < d.elements; i++)
    {
        if (d.entries[i].key == key)
        {
            d.entries[i].value = value;
            return true;
        }
    }

    if (d.elements == d.SIZE)
    {
        return false;
    }

    d.entries[d.elements].key = key;
    d.entries[d.elements].value = value;
    d.elements++;
    return true;
}

bool remove(Dict &d, int key)
{
    // Se a fila estiver vazia, o FOR não ocorre e retorna false
    for (int i = 0; i < d.elements; i++)
    {
        if (d.entries[i].key == key)
        {
            d.entries[i] = d.entries[d.elements - 1];
            d.elements--;
            return true;
        }
    }
    return false;
}
