/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 02-1: 01-mar-2024
*
*   Implementação de pilha limitada via vetor
*/

#include <iostream>
#include <windows.h> 

using namespace std;

struct Stack
{
    static constexpr int SIZE = 5;
    char vector[SIZE];
    int front, rear;
};

void init(Stack &s);
bool push(Stack &s, char c);
bool pop(Stack &s);
bool isempty(Stack &s);
char peek(Stack &s);

int main(void) 
{
    SetConsoleOutputCP(CP_UTF8);

    Stack s;
    init(s);
    int opt;
    do 
    {
        cout << "Digite uma opção" << endl;
        cout << "[1] EMPILHAR    " << endl;
        cout << "[2] DESEMPILHAR " << endl;
        cout << "[3] VAZIA       " << endl;
        cout << "[4] ESPIAR      " << endl;
        cout << "[0] SAIR        " << endl;
        cin >> opt;

        if (opt == 1)
        {
            char c;
            cout << "Digite um caractere para empilhar: ";
            cin >> c;

            if (push(s, c)) 
                cout << "SUCESSO" << endl;
            else 
                cout << "PILHA CHEIA" << endl;
        }
        else if (opt == 2) 
        {
            if (pop(s)) 
                cout << "SUCESSO" << endl;
            else 
                cout << "FILA VAZIA" << endl;
        }
        else if (opt == 3) 
        {
            if (isempty(s)) 
                cout << "PILHA VAZIA" << endl;
            else 
                cout << "PILHA NÃO VAZIA" << endl;
        }
        else if (opt == 4) 
        {
            if (!isempty(s)) 
                cout << "ÚLTIMO: " << peek(s) << endl;
            else   
                cout << "PILHA VAZIA" << endl;
        }

    } while (opt != 0);
}

void init(Stack &s)
{
    s.front = -1;
}

bool push(Stack &s, char c)
{
    if (s.rear == s.SIZE - 1)
    {
        return false;
    }

    if (isempty(s))
    {
        s.front = 0;
        s.rear = 0;
    }
    else
    {
        s.rear++;
    }

    s.vector[s.rear] = c;
    return true;
}

bool pop(Stack &s)
{
    if (isempty(s))
    {
        return false;
    }
   
    if (s.front == s.rear)
    {
        s.front = -1;
    }
    else
    {
        s.rear--;
    }

    return true;
}

bool isempty(Stack &s)
{
    return (s.front == -1);
}

char peek(Stack &s)
{
    return s.vector[s.rear];
}