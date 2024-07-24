/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 10-1: 15-jul-2024
*
*   Implementação de pilha usando lista encadeada
*/

#include <iostream>

struct Pilha {
    struct No {
        int valor;
        No* prox;
    };

    No* inicio;

    Pilha() {
        inicio = nullptr;
    }

    void empilhar(int x) {
        No* novo_no = new No {x, inicio};
        inicio = novo_no;
    }

    void desempilhar() {
        No* primeiro = inicio;
        inicio = inicio->prox;
        delete primeiro;
    }

    int consultar() {
        return inicio->valor;
    }

    ~Pilha() {
        while (inicio != nullptr) {
            desempilhar();
        }
    }
};

int main() {
    Pilha* p = new Pilha;
    p->empilhar(8);
    p->empilhar(9);
    std::cout << p->consultar();
    p->desempilhar();
    std::cout << p->consultar();
    delete p;
}