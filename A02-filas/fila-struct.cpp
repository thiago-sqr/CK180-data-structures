#include <iostream>

#define SIZE 5

using namespace std;

struct Queue 
{
    char v[SIZE];
    int first, last;
};

void init(Queue &q);
void insert(Queue &q, char c);
void remove(Queue &q);
bool empty(Queue &q);
void query(Queue &q);

int main() 
{
    Queue q;
    init(q);
    int opt;
    do
    {
        cout << "Excolha uma opção" << endl;
        cout << "[1] INSERIR  " << endl;
        cout << "[2] REMOVER  " << endl;
        cout << "[3] VERIFICAR" << endl;
        cout << "[4] CONSULTAR" << endl;
        cout << "[0] SAIR     " << endl;
        cin >> opt;

        if (opt == 1)
        {
            char c;
            cout << "Digite um caractere pra inserir: ";
            cin >> c;
            insert(q, c);
        }
        else if (opt == 2)
        {
            remove(q);
        }
        else if (opt == 3)
        {
            if (empty(q))
                cout << "Fila vazia" << endl;
            else
                cout << "Fila não vazia" << endl;
        }
        else if (opt == 4)
        {
            query(q);
        }
    } while (opt != 0);
}

void init(Queue &q) 
{
    q.first = -1;
}

void insert(Queue &q, char c) 
{
    if (q.first == -1) 
    {
        q.first = 0;
        q.last = 0;
        q.v[q.first] = c;
    } 
    else if ((q.first == 0 && q.last == SIZE - 1) || (q.first == q.last + 1)) 
    {
        cout << "Fila cheia" << endl;
    } 
    else 
    {
        if (q.last == SIZE - 1) 
        {
            q.last = 0;
            q.v[q.last] = c;
        } 
        else 
        {
            q.last++;
            q.v[q.last] = c;
        }
    }
}

void remove(Queue &q) 
{
    if (empty(q))
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        if (q.first == q.last)
        {
            q.first = -1;
            q.last = -1;
        }
        else
        {
            if (q.first == SIZE - 1)
            {
                q.first = 0;
            }
            else
            {
                q.first++;
            }
        }
    }
}

bool empty(Queue &q) 
{
    if (q.first == -1)
    {
        return true;
    }
    return false;
}

void query(Queue &q) 
{
    if (!empty(q))
    {
        cout << "Primeiro da lista: " << q.v[q.first] << endl;
        return;
    }
    cout << "Fila vazia" << endl;
}