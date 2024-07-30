/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 12-3: 22-jul-2024
 *
 *   Implementação de conjunto usando lista duplamente encadeada e nó sentinela
 */
#include <iostream> 

class Conjunto {
    struct No {
        No *ant;
        double valor;
        No *prox;
    };

    No sentinela;

public:
    Conjunto() {
        sentinela.ant = &sentinela;
        sentinela.prox = &sentinela;
    }

    bool consultar(double valor) {
        sentinela.valor = valor;
        No *cursor = sentinela.prox;
        while (cursor->valor != valor) {
            cursor = cursor->prox;
        }
        if (cursor == &sentinela) {
            return false;
        }
        return true;
    }

    void inserir(double valor) {
        No *novo = new No{&sentinela, valor, sentinela.prox};
        sentinela.prox = novo;
        novo->prox->ant = novo;
    }

    void inserir_se_novo(double valor) {
        if (not consultar(valor)) {
            inserir(valor);
        }
    }

    void remover(double valor) {
        sentinela.valor = valor;
        No *cursor = sentinela.prox;
        while (cursor->valor != valor) {
            cursor = cursor->prox;
        }
        if (cursor == &sentinela) {
            return;
        }
        cursor->ant->prox = cursor->prox;
        cursor->prox->ant = cursor->ant;
        delete cursor;
    }

    ~Conjunto() {
        while (sentinela.prox != &sentinela) {
            double valor = sentinela.prox->valor;
            remover(valor);
        }
    }
};

int main() {
    Conjunto conj;
    conj.inserir(10);
    conj.inserir_se_novo(10);
    conj.inserir_se_novo(20);
    conj.inserir(30);
    conj.inserir_se_novo(20);
    conj.inserir(40);

    if (conj.consultar(10)) std::cout << "achado 10" << std::endl;
    else std::cout << "achado nada" << std::endl;

    if (conj.consultar(20)) std::cout << "achado 20" << std::endl;
    else std::cout << "achado nada" << std::endl;

    if (conj.consultar(40)) std::cout << "achado 40" << std::endl;
    else std::cout << "achado nada" << std::endl;
    
    conj.remover(20);
}