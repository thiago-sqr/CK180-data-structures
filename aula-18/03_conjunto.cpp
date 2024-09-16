/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 18-3: 22-ago-2024
 *
 *   Implementação de conjunto via árvore binária de busca
 */
#include <iostream>

struct No {
    No *pai;
    double valor;
    No *esq;
    No *dir;
};

class Conjunto {
    No *raiz;

    void deletar(No *n) {
        if (n == nullptr) return;
        deletar(n->esq);
        deletar(n->dir);
        delete n;
    }

public:
    Conjunto() : raiz{nullptr} {}
    
    ~Conjunto() {
        deletar(raiz);
    }

    bool vazio() {
        return raiz == nullptr;
    }

    bool pertence(double valor) {
        No *cursor = raiz;
        while (cursor != nullptr) {
            if      (valor > cursor->valor) cursor = cursor->dir;
            else if (valor < cursor->valor) cursor = cursor->esq;
            else                            return true;
        }
        return false;
    }

    No* inserir(double valor) {
        No *novo = new No{nullptr, valor, nullptr, nullptr};
        if (vazio()) {
            raiz = novo;
            return;
        }

        No *cursor = raiz;
        while (true) {
            if (valor > cursor->valor) {
                if (cursor->dir == nullptr) {
                    cursor->dir = novo;
                    break;
                }
                cursor = cursor->dir;
            } else {
                if (cursor->esq == nullptr) {
                    cursor->esq = novo;
                    break;
                }
                cursor = cursor->esq;
            }
        }
        novo->pai = cursor;
        return novo;
    }

    void remover(No *x) {
        No *noPai = x->pai;
        No **ptrPai = &raiz;
        if (noPai != nullptr) {
            ptrPai = (x->valor > noPai->valor) ? &noPai->dir : &noPai->esq;
        }
        //caso 0 ou 1 filhos
        if (x->dir == nullptr or x->esq == nullptr) {
            *ptrPai = (x->dir != nullptr) ? x->dir : x->esq;
            if (*ptrPai != nullptr) (*ptrPai)->pai = noPai;
            delete x;
            return;
        }
        //caso dois filhos
        No *sucessor = x->dir;
        No **cimaSucessor = &x->dir;
        while (sucessor->esq != nullptr) {
            cimaSucessor = &x->esq;
            sucessor = x->esq;
        }
        *cimaSucessor = sucessor->dir;
        if (sucessor->dir != nullptr) sucessor->dir->pai = sucessor->pai;
        sucessor->dir = x->dir;
        sucessor->esq = x->esq;
        sucessor->pai = x->pai;
        *ptrPai = sucessor;
        delete x;
    }
};