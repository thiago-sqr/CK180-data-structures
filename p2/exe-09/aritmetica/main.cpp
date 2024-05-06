/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 09-1: 17-abr-2024
*
*   Implementação de avaliação de expressões artiméticas
*/

#include "pilha.h"
#include <iostream>
#include <new>

double resolver(std::string expr);
void operar(Pilha<char> &o, Pilha<double> &n);
double conta(double a, double b, char op);

int main()
{
    std::string expr;
    std::cout << "Escreva uma expressao aritmetica: ";
    std::cin >> expr;
    std::cout << "Resultado: ";
    std::cout << resolver(expr) << std::endl;
}

double resolver(std::string expr)
{
    Pilha<char> operadores;
    Pilha<double> numeros;
    if (not init(operadores)) return 0;
    if (not init(numeros)) return 0;
    
    std::string token = "";

    for (unsigned int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(') continue;

        if (expr[i] == ')')
        {
            if (token != "") empilhar(numeros, stod(token))   ; 
            token = "";                                             
            operar(operadores, numeros);
        }
        else if (expr[i] == '+' or expr[i] == '-' or expr[i] == '*' or expr[i] == '/')
        {
            if (token != "") empilhar(numeros, stod(token));        
            token = "";                                             
            empilhar(operadores, expr[i]);       
        }
        else
        {
            token += expr[i];
        }
    }

    double resultado = numeros.vetor[0];

    destruir(numeros);
    destruir(operadores);

    return resultado;
}


void operar(Pilha<char> &o, Pilha<double> &n)
{
    double b = ultimo(n);
    desempilhar(n);
    double a = ultimo(n);
    desempilhar(n);

    char op = ultimo(o);
    desempilhar(o);

    empilhar(n, conta(a, b, op));
}

double conta(double a, double b, char op)
{
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': if (b != 0) return a / b;
    }
    return 0;
}