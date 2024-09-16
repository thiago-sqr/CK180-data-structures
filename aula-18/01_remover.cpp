/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 18-1: 22-ago-2024
 *
 *   Remoção em lista encadeada usando ponteiro para ponteiro
 */
#include <iostream>

struct Lista {
    struct No {
        int valor;
        No *prox;
    };

    No *inicio;
};

void remover(Lista &l, double valor) {
    Lista::No *cursor = l.inicio;
    Lista::No* *anterior = &(l.inicio);
    while (cursor != nullptr) {
        if (cursor->valor == valor) {
            *anterior = cursor->prox;
            delete cursor;
            return;
        }
        anterior = &(cursor->prox);
        cursor = cursor->prox;
    }
}
 
