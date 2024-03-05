/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 03-1: 04-mar-2024
*
*   Implementação alternativa de Fila Limitada via Vetor, na qual o índice do  
*   último seja substituído pela quantidade "n" de elementos presentes na fila.
*/

#include <iostream>
#include <windows.h>

using namespace std;

struct Queue
{
    static constexpr int SIZE = 5;
    char vector[SIZE];
    int front, elements;
};

void init(Queue &q);
bool enqueue(Queue &q, char c);
bool dequeue(Queue &q);
bool isempty(Queue &q);
bool isfull(Queue &q);
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

void init (Queue &q)
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