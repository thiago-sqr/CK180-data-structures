/*
*   Engenharia de Computação, DETI~DC, UFC
*   Implementação de pilha limitada via vetor
*/

#include <iostream>

#define SIZE 5

using namespace std;

struct Stack
{
    char vector[SIZE];
    int front, rear;
};

void init(Stack &s);
void push(Stack &s, char c);
void pop(Stack &s);
bool isempty(Stack &s);
void peek(Stack &s);

int main(void)
{
    Stack s;
    init(s);
    int opt;
    do
    {
        cout << "Enter an option" << endl;
        cout << "[1] PUSH " << endl;
        cout << "[2] POP  " << endl;
        cout << "[3] EMPTY" << endl;
        cout << "[4] PEEK " << endl;
        cout << "[0] EXIT " << endl;
        cin >> opt;

        if (opt == 1)
        {
            char c;
            cout << "Enter a character to push: ";
            cin >> c;
            push(s, c);
        }
        else if (opt == 2)
        {
            pop(s);
        }
        else if (opt == 3)
        {
            if (isempty(s))
                cout << "EMPTY STACK" << endl;
            else
                cout << "FILLED STACK" << endl;
        }
        else if (opt == 4)
        {
            peek(s);
        }
    } while (opt != 0);
}

void init(Stack &s)
{
    s.front = -1;
}

void push(Stack &s, char c)
{
    if (isempty(s))
    {
        s.front = 0;
        s.rear = 0;
        s.vector[s.front] = c;
    }
    else if (s.rear == SIZE - 1)
    {
        cout << "STACK IS FULL" << endl;
    }
    else
    {
        s.rear++;
        s.vector[s.rear] = c;
    }
}

void pop(Stack &s)
{
    if (isempty(s))
    {
        cout << "EMPTY STACK" << endl;
    }
    else
    {
        if (s.front == 0)
        {
            s.front = -1;
        }
        else
        {
            s.rear--;
        } 
    }
}

bool isempty(Stack &s)
{
    if (s.front == -1)
    {
        return true;
    }
    return false;
}

void peek(Stack &s)
{
    if (!isempty(s))
    {
        cout << "LAST: " << s.vector[s.rear] << endl;
        return;
    }
    cout << "EMPTY STACK" << endl;
}