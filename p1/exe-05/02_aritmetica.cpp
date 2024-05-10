/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 05-2: 11-mar-24
*
*   Solucionador de expressões aritméticas
*/
#include <iostream>

using namespace std;

struct Stack
{
    static constexpr int SIZE = 20;
    string vector[SIZE];
    int front = -1, rear = -1;
};

bool isempty(Stack &s)
{
    return (s.front == -1);
}

bool push(Stack &s, string str)
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

    s.vector[s.rear] = str;
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

string peek(Stack &s)
{
    return s.vector[s.rear];
}

/*
void operate(Stack &s)
{

}
*/
void solve(string expr)
{
    Stack stack;
    string aux;
    for (unsigned int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(') continue;
        
        if (expr[i] == ')')
        {
            if (aux != "") push(stack, aux);        // push complete number
            aux = "";                               // resets auxiliar string
            //operate(stack);
            continue;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            if (aux != "") push(stack, aux);        // push complete number
            aux = expr[i];                          // get operator
            if (aux != "") push(stack, aux);        // push operator
            aux = "";                               // resets auxiliar string
        }
        else
        {
            aux += expr[i];                         // write number
        }
    }
    
    for (int i = 0; i < stack.rear; i++)
    {
        cout << stack.vector[i] << endl;
    }
}

int main()
{
    string expr;
    cin >> expr;
    solve(expr);
}