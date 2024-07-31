/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 07-3: 04-abr-2024
*
*   Implementação de pilha ilimitada via vetor
*/

#include <iostream>
#include <new>

using namespace std;

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
    catch (const exception& e)
    {
        cerr << e.what() << '\n';
    }
    return false;
}

template <typename tipo>
void destruir(Pilha<tipo> &p)
{
    delete[] p.vetor;
}

template <typename tipo>
bool empilhar(Pilha<tipo> &p, tipo x)
{
    if (p.elementos == p.max) 
    {
        tipo *novo_vetor;
        try
        {
            novo_vetor = new tipo [p.max * 2];
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
            return false;
        }

        for (int i = 0; i < p.max; i++)
        {
            novo_vetor[i] = p.vetor[i];
        }
        
        delete[] p.vetor;
        p.vetor = novo_vetor;
        p.max *= 2;
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
    return true;
}

template <typename tipo>
tipo ultimo(Pilha<tipo> &p)
{
    return p.vetor[p.elementos - 1];
}

int main()
{
    Pilha<double> p;
    init(p);

    for (int i = 0; i < 40; i++)
	{
		empilhar(p, (double)i);
	}
	
	for (int i = 0; i < p.elementos; i++)
	{
		cout << p.vetor[i] << " ";
	}

    cout << "\n" << p.max << endl;
	
	destruir(p);
	return 0;
}