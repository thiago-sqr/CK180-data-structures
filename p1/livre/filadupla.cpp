/*
*   Engenharia de Computação, DETI~DC, UFC
*   Implementação de fila dupla limitada via vetor
*/

#include <iostream>

using namespace std;

struct Deque
{
    static constexpr int SIZE = 5;
    char vector[SIZE];
    int front, rear;
};

void init(Deque &d);
bool enqueue_front(Deque &d, char c);
bool enqueue_rear(Deque &d, char c);
bool dequeue_front(Deque &d);
bool dequeue_rear(Deque &d);
bool isempty(Deque &d);
bool isfull(Deque &d);
char peek_front(Deque &d);
char peek_rear(Deque &d);

int main(void) 
{
    // TODO
    return 0;
}

void init(Deque &d)
{
    d.front = -1;
}

bool enqueue_front(Deque &d, char c)
{
    if (isfull(d))
    {
        return false;
    }

    if (isempty(d))
    {
        d.front = 0;
        d.rear = 0;
    }
    else
    {
        if (d.front == 0)
        {
            d.front = d.SIZE - 1;
        }
        else
        {
            d.front--;
        }
    }

    d.vector[d.front] = c;
    return true;
}

bool enqueue_rear(Deque &d, char c)
{
    if (isfull(d))
    {
        return false;
    }

    if (isempty(d))
    {
        d.front = 0;
        d.rear = 0;
    }
    else
    {
        d.rear = (d.rear + 1) % d.SIZE;
    }

    d.vector[d.rear] = c;
    return true;
}

bool dequeue_front(Deque &d)
{
    if (isempty(d))
    {
        return false;
    }
    
    if (d.front == d.rear)
    {
        d.front = -1;
    }
    else
    {
        d.front = (d.front + 1) % d.SIZE;
    }

    return true;
}

bool dequeue_rear(Deque &d)
{
    if (isempty(d))
    {
        return false;
    }

    if (d.front == d.rear)
    {
        d.front = -1;
    }
    else
    {
        if (d.rear == 0)
        {
            d.rear = d.SIZE - 1;
        }
        else
        {
            d.rear--;
        }
    }
    
    return true;
}

bool isempty(Deque &d)
{
    return (d.front == -1);
}

bool isfull(Deque &d)
{
    if (d.front == 0 && d.rear == d.SIZE - 1)
    {
        return true;
    }
    else if (d.front == d.rear + 1)
    {
        return true;
    }
    return false;
}

char peek_front(Deque &d)
{
    return d.vector[d.front];
}

char peek_rear(Deque &d)
{
    return d.vector[d.rear];
}