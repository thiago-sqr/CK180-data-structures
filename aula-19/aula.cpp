/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Aula 19: 28-ago-2024
 *
 *   Percursos recursivos em Árvores Binárias;
 *   a) Em Ordem
 *      1. subárvore à esquerda
 *      2. nó atual
 *      3. subárvore à direita
 *   b) Pós Ordem
 *      1. subárvore à esquerda
 *      2. subárvore à direita
 *      3. nó atual
 *   c) Pré Ordem
 *      1. nó atual
 *      2. subárvore à esquerda
 *      3. subárvore à direita   
 */
#include <iostream>

struct No {
    double valor;
    No *esq;
    No *dir;
};

int altura(No *n);                            // Pós Ordem
int imprimirAlturas(No *n);                   // Pós Ordem
No* vetorParaArvore(int *vetor, int tamanho); // Pré Ordem
void imprimirOrdem(No *n);                    // Em Ordem
void limparArvore(No *n);                     // Pós ordem

int main() {
    int v[] = {1,2,3,4,5,6,7,8,9};
    No* n = vetorParaArvore(v, sizeof(v)/sizeof(int));
    imprimirOrdem(n);
    std::cout << '\n';
    imprimirAlturas(n);
    limparArvore(n);
}

int altura(No *n) {
    if (n == nullptr) return 0;
    int altDir = altura(n->dir);
    int altEsq = altura(n->esq);
    return altEsq > altDir ? altEsq + 1 : altDir + 1;
}

int imprimirAlturas(No *n) {
    if (n == nullptr) return 0;
    int altEsq = imprimirAlturas(n->esq);
    int altDir = imprimirAlturas(n->dir);
    int altNo = (altEsq > altDir) ? altEsq + 1 : altDir + 1;
    std::cout << "Alt(" << n->valor << "):" << altNo << "\n";
    return altNo;
}

No* vetorParaArvore(int *vetor, int tamanho) {
    if (tamanho == 0) return nullptr;
    int metade = tamanho / 2;
    No *pai = new No;
    pai->valor = vetor[metade];
    pai->esq = vetorParaArvore(vetor, metade);
    pai->dir = vetorParaArvore(&vetor[metade+1], tamanho - metade - 1);
    return pai;
}

void imprimirOrdem(No *n) {
    if (n == nullptr) return;
    imprimirOrdem(n->esq);
    std::cout << n->valor << " ";
    imprimirOrdem(n->dir);
}

void limparArvore(No *n) {
    if (n == nullptr) return;
    limparArvore(n->esq);
    limparArvore(n->dir);
    delete n;
}
