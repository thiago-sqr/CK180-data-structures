/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 18-2: 22-ago-2024
 *
 *   Busca em lista encadeada usando ponteiro para ponteiro
 */
#include <iostream>

struct Arvore {
    struct No {
        int valor;
        No *esq;
        No *dir;
    };
    
    No *raiz;
};

Arvore::No** buscarNo(Arvore &arv, int valor) {
    Arvore::No *cursor = arv.raiz;
    Arvore::No **cima = &(arv.raiz);
    while (cursor != nullptr) {
        if (cursor->valor < valor) {
            cima = &cursor->dir;
            cursor = cursor->dir;
        } else if (cursor->valor > valor) {
            cima = &cursor->esq;
            cursor = cursor->esq;
        } else break;
    }
    return cima;
}

