/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 10-1: 15-jul-2024
 *
 *   Implementação de fila usando lista encadeada
 */

#include <iostream>

class Fila {
    struct No {
        int valor;
        No *prox;
    };

    No *inicio, *fim;

public:
    Fila() : inicio{nullptr}, fim{nullptr} {}

    void enfilar(int x) {
        No *novo_no = new No {x, nullptr};
        (fim == nullptr ? inicio : fim->prox) = novo_no;
        fim = novo_no;
    }

    void desenfilar() {
        No *primeiro = inicio;
        inicio = inicio->prox;
        delete primeiro;
    }

    int consultar() {
        return inicio->valor;
    }

    ~Fila() {
        while (inicio != nullptr) {
            desenfilar();
        }
    }
};
