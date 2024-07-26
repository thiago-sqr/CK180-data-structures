/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 11-1: 18-jul-2024
 *
 *   Implementação de deque usando lista duplamente encadeada
 */

#include <iostream>

class Deque {
private:
    struct No {
        No *ant;
        int valor;
        No *prox;
    };

    No *inicio;
    No *fim;

    void enfilar_unico_no(int x) {
        inicio = fim = new No {nullptr, x, nullptr};
    }

    void desenfilar_unico_no() {
        No *ultimo = fim;
        inicio = fim = nullptr;
        delete ultimo;
    }

public:
    Deque() : inicio{nullptr}, fim{nullptr} {}

    bool vazio() {
        return (inicio == nullptr and fim == nullptr);
    }

    void enfilar_inicio(int x) {
        if (vazio()) {
            enfilar_unico_no(x);
            return;
        } 
        inicio->ant = new No {nullptr, x, inicio};
        inicio = inicio->ant;
    }

    // Não considerando caso de fila vazia
    void desenfilar_inicio() {
        if (inicio == fim) {
            desenfilar_unico_no();
            return;
        }
        No *primeiro = inicio;
        inicio = inicio->prox;
        inicio->ant = nullptr;
        delete primeiro;
    }

    void enfilar_fim(int x) {
        if (vazio()) {
            enfilar_unico_no(x);
            return;
        }
        fim->prox = new No {fim, x, nullptr};
        fim = fim->prox;
    }

    // Não considerando caso de fila vazia
    void desenfilar_fim() {
        if (inicio == fim) {
            desenfilar_unico_no();
            return;
        }
        No *ultimo = fim;
        fim = fim->ant;
        fim->prox = nullptr;
        delete ultimo;
    }

    // Não considerando caso de fila vazia
    int consultar_inicio() {
        return inicio->valor;
    }

    // Não considerando caso de fila vazia
    int consultar_fim() {
        return fim->valor;
    }

    ~Deque() {
        while (inicio != nullptr) {
            desenfilar_inicio();
        }
    }
};
