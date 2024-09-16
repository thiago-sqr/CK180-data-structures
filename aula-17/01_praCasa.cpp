/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 17-1: 19-ago-2024
 *
 *   Implementação de conjunto a partir de árvore binária
 *   Sem utilizar ponteiro para ponteiro
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
        No *pai = nullptr;
        while (true) {
            if (cursor == nullptr) return; //valor não existe
            if (valor < cursor->valor) {
                pai = cursor;
                cursor = cursor->esq;
            } else if (valor > cursor->valor) {
                pai = cursor;
                cursor = cursor->dir;
            } else break;
        }

        // também contemplado o caso de nenhum filho
        if (cursor->dir == nullptr or cursor->esq == nullptr) { // 1 filho
            if (cursor->dir == nullptr) { // so tem filho esquerdo
                if      (cursor == raiz)     raiz     = cursor->esq;
                else if (cursor == pai->esq) pai->esq = cursor->esq;
                else                         pai->dir = cursor->esq;
            } else { // so tem filho direito
                if      (cursor == raiz)     raiz     = cursor->dir;
                else if (cursor == pai->esq) pai->esq = cursor->dir;
                else                         pai->dir = cursor->dir;
            }
            delete cursor;
            return;
        }

        No *sucessor = cursor->dir;
        while (sucessor->esq != nullptr) {
            sucessor = sucessor->esq;
        }
        cursor->valor = sucessor->valor;
        No *paiSucessor = cursor->dir;
        while (pai->esq != sucessor) {
            pai = pai->esq;
        }
        paiSucessor->esq = sucessor->dir;
        delete sucessor;
    }
};
