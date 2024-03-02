/*
*   Engenharia de Computação, DETI~DC, UFC
*   Implementação de fila dupla limitada via vetor
*/

#include <iostream>

#define SIZE 5

using namespace std;

struct Deque
{
    char vector[SIZE];
    int front, rear;
};

void init(Deque &d);
void enqueue_front(Deque &d, char c);
void enqueue_rear(Deque &d, char c);
void dequeue_front(Deque &d);
void dequeue_rear(Deque &d);
bool isempty(Deque &d);
bool isfull(Deque &d);
void peek_front(Deque &d);
void peek_rear(Deque &d);

int main(void) {}

void init(Deque &d)
{
    d.front = -1;
}

void enqueue_front(Deque &d, char c)
{
    if (isempty(d))
    {
        d.front = 0;
        d.rear = 0;
        d.vector[d.front] = c;
    }
    else if (isfull(d))
    {
        cout << "OVERFLOW" << endl;
    }
    else
    {
        if (d.front == 0)
        {
            d.front = SIZE - 1;
            d.vector[d.front] = c;
        }
        else
        {
            d.front--;
            d.vector[d.front] = c;
        }
    }
}

void enqueue_rear(Deque &d, char c)
{
    if (isempty(d))
    {
        d.front = 0;
        d.rear = 0;
        d.vector[d.rear] = c;
    }
    else if (isfull(d))
    {
        cout << "OVERFLOW" << endl;
    }
    else
    {
        if (d.rear == SIZE - 1)
        {
            d.rear = 0;
            d.vector[d.rear] = c;
        }
        else
        {
            d.rear++;
            d.vector[d.rear] = c;
        }
    }
}

void dequeue_front(Deque &d)
{
    if (isempty(d))
    {
        cout << "EMPTY DEQUE" << endl;
    }
    else
    {
        if (d.front == d.rear)
        {
            d.front = -1;
        }
        else
        {
            if (d.front == SIZE - 1)
            {
                d.front = 0;
            }
            else
            {
                d.front++;
            }
        }
    }
}

void dequeue_rear(Deque &d)
{
    if (isempty(d))
    {
        cout << "EMPTY DEQUE" << endl;
    }
    else
    {
        if (d.front == d.rear)
        {
            d.front = -1;
        }
        else
        {
            if (d.rear == 0)
            {
                d.rear = SIZE - 1;
            }
            else
            {
                d.rear--;
            }
        }
    }
}

bool isempty(Deque &d)
{
    if (d.front == -1)
    {
        return true;
    }
    return false;
}

bool isfull(Deque &d)
{
    if (d.front == 0 && d.rear == SIZE - 1)
    {
        return true;
    }
    else if (d.front == d.rear + 1)
    {
        return true;
    }
    return false;
}

void peek_front(Deque &d)
{
    if (!isempty(d))
    {
        cout << "FIRST: " << d.vector[d.front] << endl;
        return;
    }
    cout << "EMPTY DEQUE" << endl;
}

void peek_rear(Deque &d)
{
    if (!isempty(d))
    {
        cout << "LAST: " << d.vector[d.rear] << endl;
        return;
    }
    cout << "EMPTY DEQUE" << endl;
}