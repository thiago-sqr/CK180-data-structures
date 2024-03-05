/*
*   Engenharia de Computação, DETI~DC, UFC
*   Implementação de fila limitada via vetor
*/

#include <iostream>
#include <windows.h> 

using namespace std;

struct Queue 
{
    static constexpr int SIZE = 5;
    char vector[SIZE];
    int front, rear;
};

void init(Queue &q);
bool enqueue(Queue &q, char c);
bool dequeue(Queue &q);
bool isempty(Queue &q);
char peek(Queue &q);

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    Queue q;
    init(q);
    int opt;
    do
    {
        cout << "Digite uma opção" << endl;
        cout << "[1] ENFILEIRAR  " << endl;
        cout << "[2] DESFILEIRAR " << endl;
        cout << "[3] VAZIA       " << endl;
        cout << "[4] ESPIAR      " << endl;
        cout << "[0] SAIR        " << endl;
        cin >> opt;

        if (opt == 1) 
        {
            char c;
            cout << "Digite um caractere para enfileirar: ";
            cin >> c;

            if (enqueue(q, c)) 
                cout << "SUCESSO" << endl;
            else 
                cout << "A FILA ESTÁ CHEIA" << endl;
        }
        else if (opt == 2) 
        {
            if (dequeue(q)) 
                cout << "SUCESSO" << endl;
            else 
                cout << "FILA VAZIA" << endl;
        }
        else if (opt == 3) 
        {
            if (isempty(q)) 
                cout << "FILA VAZIA" << endl;
            else 
                cout << "FILA NÃO ESTÁ VAZIA" << endl;
        }
        else if (opt == 4) 
        {
            if (!isempty(q)) 
                cout << "PRIMEIRO: " << peek(q) << endl;
            else 
                cout << "FILA VAZIA" << endl;
        }

    } while (opt != 0);
}

void init(Queue &q) 
{
    q.front = -1;
}

bool enqueue(Queue &q, char c) 
{
    if ((q.front == 0 && q.rear == q.SIZE - 1) || (q.front == q.rear + 1))
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
        q.rear = (q.rear + 1) % q.SIZE;
    }

    q.vector[q.rear] = c;
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
        q.front = (q.front + 1) % q.SIZE;
    }
    return true;
}

bool isempty(Queue &q) 
{
    return (q.front == -1);
}

char peek(Queue &q) 
{
    return q.vector[q.rear];
}
