/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 03-1: 04-mar-2024
 *
 *   Implementação alternativa de Fila Limitada via Vetor, na qual o índice do
 *   último seja substituído pela quantidade "n" de elementos presentes na fila.
 */

#include <iostream>

using namespace std;

struct Queue
{
    static constexpr int SIZE = 5;
    char vector[SIZE];
    int front, elements;
};

void init(Queue &q)
{
    q.front = -1;
    q.elements = 0;
}

bool isempty(Queue &q)
{
    return (q.elements == 0);
}

bool isfull(Queue &q)
{
    return (q.elements == q.SIZE);
}

bool enqueue(Queue &q, char c)
{
    if (isfull(q))
    {
        return false;
    }

    if (isempty(q))
    {
        q.front = 0;
        q.elements = 1;
    }
    else
    {
        q.elements++;
    }

    q.vector[(q.front + q.elements - 1) % q.SIZE] = c;
    return true;
}

bool dequeue(Queue &q)
{
    if (isempty(q))
    {
        return false;
    }

    if (q.elements == 1)
    {
        q.front = -1;
    }
    else
    {
        q.front = (q.front + 1) % q.SIZE;
    }

    q.elements--;
    return true;
}

char peek(Queue &q)
{
    return q.vector[q.front];
}