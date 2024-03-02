/*
*   Engenharia de Computação, DETI~DC, UFC
*   Implementação de fila limitada via vetor
*/

#include <iostream>

#define SIZE 5

using namespace std;

struct Queue 
{
    char vector[SIZE];
    int front, rear;
};

void init(Queue &q);
void enqueue(Queue &q, char c);
void dequeue(Queue &q);
bool isempty(Queue &q);
void peek(Queue &q);

int main() 
{
    Queue q;
    init(q);
    int opt;
    do
    {
        cout << "Enter an option" << endl;
        cout << "[1] ENQUEUE" << endl;
        cout << "[2] DEQUEUE" << endl;
        cout << "[3] EMPTY  " << endl;
        cout << "[4] PEEK   " << endl;
        cout << "[0] EXIT   " << endl;
        cin >> opt;

        if (opt == 1)
        {
            char c;
            cout << "Enter a character to enqueue: ";
            cin >> c;
            enqueue(q, c);
        }
        else if (opt == 2)
        {
            dequeue(q);
        }
        else if (opt == 3)
        {
            if (isempty(q))
                cout << "EMPTY QUEUE" << endl;
            else
                cout << "FILLED QUEUE" << endl;
        }
        else if (opt == 4)
        {
            peek(q);
        }
    } while (opt != 0);
}

void init(Queue &q) 
{
    q.front = -1;
}

void enqueue(Queue &q, char c) 
{
    if (isempty(q)) 
    {
        q.front = 0;
        q.rear = 0;
        q.vector[q.front] = c;
    } 
    else if ((q.front == 0 && q.rear == SIZE - 1) || (q.front == q.rear + 1)) 
    {
        cout << "QUEUE IS FULL" << endl;
    } 
    else 
    {
        if (q.rear == SIZE - 1) 
        {
            q.rear = 0;
            q.vector[q.rear] = c;
        } 
        else 
        {
            q.rear++;
            q.vector[q.rear] = c;
        }
    }
}

void dequeue(Queue &q) 
{
    if (isempty(q))
    {
        cout << "EMPTY QUEUE" << endl;
    }
    else
    {
        if (q.front == q.rear)
        {
            q.front = -1;
            q.rear = -1;
        }
        else
        {
            if (q.front == SIZE - 1)
            {
                q.front = 0;
            }
            else
            {
                q.front++;
            }
        }
    }
}

bool isempty(Queue &q) 
{
    if (q.front == -1)
    {
        return true;
    }
    return false;
}

void peek(Queue &q) 
{
    if (!isempty(q))
    {
        cout << "FIRST: " << q.vector[q.front] << endl;
        return;
    }
    cout << "EMPTY QUEUE" << endl;
}
