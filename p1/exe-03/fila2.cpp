/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 03-1: 04-mar-2024
 *
 *   Implementação alternativa de Fila Limitada via Vetor, com capacidade para até
 *   10 elementos armazenados simultaneamente, que utilize 2 vetores de 5 elementos.
 */

#include <iostream>

using namespace std;

struct Queue
{
    static constexpr int VSIZE = 5;
    int MAXSIZE = 2 * VSIZE;
    char frontVector[VSIZE], rearVector[VSIZE];
    int front, rear;
};

void init(Queue &q)
{
    q.front = -1;
}

bool isempty(Queue &q)
{
    return (q.front == -1);
}

bool isfull(Queue &q)
{
    if (q.front == 0 && q.rear == (q.MAXSIZE - 1))
    {
        return true;
    }
    else if (q.front == q.rear + 1)
    {
        return true;
    }
    return false;
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
        q.rear = 0;
    }
    else
    {
        q.rear = (q.rear + 1) % q.MAXSIZE;
    }

    if (q.rear >= q.VSIZE)
    {
        q.rearVector[q.rear - q.VSIZE] = c;
    }
    else
    {
        q.frontVector[q.rear] = c;
    }
    return true;
}

bool dequeue(Queue &q)
{
    if (isempty(q))
    {
        return false;
    }

    if (q.front == q.rear)
    {
        q.front = -1;
    }
    else
    {
        q.front = (q.front + 1) % q.MAXSIZE;
    }
    return true;
}

char peek(Queue &q)
{
    if (q.front >= q.VSIZE)
    {
        return q.rearVector[q.front - q.VSIZE];
    }
    return q.frontVector[q.front];
}