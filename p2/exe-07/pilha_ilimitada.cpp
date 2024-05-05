/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 07-1: 04-abr-2024
*
*   Implementação de pilha ilimitada via vetor
*/

#include <iostream>
#include <new>

using namespace std;

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
		double *vetor_novo = new double [1];
		p.vetor = vetor_novo;
		p.max = 1;
		p.elementos = 0;
		return true;
	}
	catch (const bad_alloc &e)
	{
		cout << "bad alloc: " << e.what() << endl;
	}
	return false;
}

void destruir(Pilha &p)
{
	delete[] p.vetor;
}

bool empilhar(Pilha &p, double x)
{
	if (p.elementos == p.max)
	{
		double *novo_vetor;
		try
		{
			novo_vetor = new double [p.max * 2];
		}
		catch (const bad_alloc &e)
		{
			cout << "bad alloc: " << e.what() << endl;
			return false;
		}
		
		for (int i = 0; i < p.max; i++)
		{
			novo_vetor[i] = p.vetor[i];
		}
		
		delete[] p.vetor;
		p.vetor = novo_vetor;
		p.max = p.max * 2;
		
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
	return true;
}

double ultimo(Pilha &p)
{
	return p.vetor[p.elementos - 1];
}

int main()
{
	Pilha p;
	init(p);
	
	for (int i = 0; i < 20; i++)
	{
		empilhar(p, i);
	}
	
	for (int i = 0; i < p.elementos; i++)
	{
		cout << p.vetor[i] << " ";
	}

    cout << "\n" << p.max << endl;
	
	destruir(p);
	return 0;
}
