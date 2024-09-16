/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 16-1: 12-ago-2024
 *
 *   Tranformada de vetor para árvore binária
 */
#include <iostream>

struct No {
    int valor;
    No *esq;
    No *dir;
};

No* vetorParaArvore(int *vetor, int tamanho) {
    if (tamanho == 0) return nullptr;
    int metade = tamanho / 2;
    No *pai = new No;
    pai->valor = vetor[metade];
    pai->esq = vetorParaArvore(vetor, metade);
    pai->dir = vetorParaArvore(&vetor[metade+1], tamanho - metade - 1);
    return pai;
}
