/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Aula 18: 22-ago-2024
 *
 *   Implementação de conjunto a partir de árvore binária
 *   Utilizando ponteiro para ponteiro
 */
#include <iostream>

class Conjunto {
    struct No {
        double valor;
        No *esq;
        No *dir;
    };

    No *raiz;

    void limparArvore(No *n) {
        if (n == nullptr) return;
        limparArvore(n->esq);
        limparArvore(n->dir);
        delete n;
    }

    void printOrdem(No *n) {
        if (n == nullptr) return;
        printOrdem(n->esq);
        std::cout << n->valor << " ";
        printOrdem(n->dir);
    }

public:
    Conjunto() : raiz{nullptr} {}

    ~Conjunto() {
        limparArvore(raiz);
    }

    void imprimir() {
        printOrdem(raiz);
        std::cout << '\n';
    }

    bool vazio() {
        return raiz == nullptr;
    }

    void inserir(double valor) {
        //Um novo nó inserido sempre será folha
        No *novo =  new No{valor, nullptr, nullptr};
        if (raiz == nullptr) {
            raiz = novo;
            return;
        }

        No *cursor = raiz;
        while (true) {
            if (valor < cursor->valor) {
                if (cursor->esq == nullptr){
                    cursor->esq = novo;
                    return;
                }
                cursor = cursor->esq;
            } else {
                if (cursor->dir == nullptr) {
                    cursor->dir = novo;
                    return;
                }
                cursor = cursor->dir;
            }
        }
    }

    void inserirSeNovo(double valor) {
        if (not pertence(valor)) {
            inserir(valor);
        }
    }

    bool pertence(double valor) {
        No *cursor = raiz;
        while (cursor != nullptr) {
            if      (valor < cursor->valor) cursor = cursor->esq;
            else if (valor > cursor->valor) cursor = cursor->dir;
            else                            return true;
        }
        return false;
    }

    void remover(double valor) {
        No *cursor = raiz;
        No* *cima = &raiz;

        while (true) {
            if (cursor == nullptr) return; //valor não existe
            if (valor < cursor->valor) {
                cima = &(cursor->esq);
                cursor = cursor->esq;
            } else if (valor > cursor->valor) {
                cima = &(cursor->dir);
                cursor = cursor->dir;
            } else break;
        }

        if (cursor->dir == nullptr) {         // pelo menos filho esquerdo
            *cima = cursor->esq;
        } else if (cursor->esq == nullptr) {  // pelo menos filho direito
            *cima = cursor->dir;
        } else {                              // há dois filhos
            No *sucessor = cursor->dir;
            No* *cimaSucessor = &(cursor->dir);
            while (sucessor->esq != nullptr) {
                cimaSucessor = &(sucessor->esq);
                sucessor = sucessor->esq;
            }
            *cimaSucessor = sucessor->dir;
            *cima = sucessor;
            sucessor->esq = cursor->esq;
            sucessor->dir = cursor->dir;
        }

        delete cursor;
    }
};
