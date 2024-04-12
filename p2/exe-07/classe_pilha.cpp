/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 07-1 (variação): 04-abr-2024
*
*   Implementação de classe de pilha ilimitada via vetor
*/

#include <iostream>
#include <new>

class Pilha
{
private:
    double *vetor;
    int elementos;
    int max;

public:
    Pilha() : vetor(nullptr), elementos(0), max(0)
    {
        init();
    }

    ~Pilha()
    {
        destruir();
    }

    void init()
    {
        try
        {
            double *vetor_novo = new double[1];
            vetor = vetor_novo;
            max = 1;
            elementos = 0;
        }
        catch (const std::bad_alloc &e)
        {
            std::cout << "bad alloc: " << e.what() << std::endl;
        }
    }

    void destruir()
    {
        delete[] vetor;
    }

    bool empilhar(double x)
    {
        if (elementos == max)
        {
            double *novo_vetor;
            try
            {
                novo_vetor = new double[max * 2];
            }
            catch (const std::bad_alloc &e)
            {
                std::cout << "bad alloc: " << e.what() << std::endl;
                return false;
            }

            for (int i = 0; i < max; i++)
            {
                novo_vetor[i] = vetor[i];
            }

            delete[] vetor;
            vetor = novo_vetor;
            max = max * 2;
            vetor[elementos++] = x;
        }
        else
        {
            vetor[elementos++] = x;
        }

        return true;
    }

    bool desempilhar()
    {
        if (elementos == 0)
        {
            return false;
        }

        elementos--;
        return true;
    }

    double ultimo()
    {
        if (elementos == 0)
        {
            throw std::out_of_range("A pilha está vazia");
        }
        return vetor[elementos - 1];
    }
};


int main() {
    Pilha p;
    p.empilhar(5);
    p.empilhar(10);
    p.empilhar(15);

    for (int i = 0; i < 20; i++)
	{
		p.empilhar(i);
	}

    std::cout << "Último elemento: " << p.ultimo() << std::endl;

    p.desempilhar();
    std::cout << "Novo último elemento: " << p.ultimo() << std::endl;

    return 0;
}