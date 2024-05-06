#ifndef PILHA_H
#define PILHA_H

#include <iostream>

template <typename tipo>
struct Pilha 
{
    tipo *vetor;
    int elementos;
    int max;
};

template <typename tipo>
bool init(Pilha<tipo> &p)
{
    try
    {
        tipo *novo_vetor = new tipo [1];
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

template <typename tipo>
void destruir(Pilha<tipo> &p)
{
	delete[] p.vetor;
}

template <typename tipo>
bool formatar_vetor(Pilha<tipo> &p, bool ctrl) // ctrl=1 -> aumenta vetor | ctrl=0 -> diminui vetor
{
    tipo *novo_vetor;
    try
    {
        novo_vetor = (ctrl) ? new tipo [p.max * 2] : new tipo [p.max / 2];
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
    if (p.max != 0) p.max = (ctrl) ? p.max * 2 : p.max / 2;
    else p.max = 1;
    return true;
}

template <typename tipo>
bool empilhar(Pilha<tipo> &p, double x)
{
    if (p.elementos == p.max)
    {
        if (not formatar_vetor(p, true)) return false;
    }

    p.vetor[p.elementos++] = x;
    return true;   
}

template <typename tipo>
bool desempilhar(Pilha<tipo> &p)
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

template <typename tipo>
tipo ultimo(Pilha<tipo> &p)
{
    return p.vetor[p.elementos - 1];
}

#endif