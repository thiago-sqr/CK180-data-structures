/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 08-1: 17-abr-2024
*
*   Implementação de pilha retrátil ilimitada via vetor
*/

#include <iostream>
#include <new>

struct Pilha 
{
    double *vetor;
    int elementos;
    int max;
};

bool init(Pilha &p)
{
    try
    {
        double *novo_vetor = new double [1];
        p.vetor = novo_vetor;
        p.max = 1;
        p.elementos = 0;
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return false;
}

void destruir(Pilha &p)
{
    delete[] p.vetor;
}

bool formatar_vetor(Pilha &p, bool ctrl) // ctrl=1 -> aumenta vetor | ctrl=0 -> diminui vetor
{
    double *novo_vetor;
    try
    {
        novo_vetor = (ctrl) ? new double [p.max * 2] : new double [p.max / 2];
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    
    int lim = (ctrl) ? p.max : p.elementos;
    for (int i = 0; i < lim; i++)
    {
        novo_vetor[i] = p.vetor[i];
    }

    delete[] p.vetor;
    p.vetor = novo_vetor;
    p.max = (ctrl) ? p.max * 2 : p.max / 2;
    return true;
}

bool empilhar(Pilha &p, double x)
{
    if (p.elementos == p.max)
    {
        if (not formatar_vetor(p, true)) return false;
    }

    p.vetor[p.elementos++] = x;
    return true;   
}

bool desempilhar(Pilha &p)
{
    if (p.elementos == 0)
    {
        return false;
    }

    p.elementos--;

    if (p.elementos == (p.max / 2))
    {
        if (not formatar_vetor(p, false)) return false;
    }

    return true;
}

double ultimo(Pilha &p)
{
    return p.vetor[p.elementos - 1];
}

