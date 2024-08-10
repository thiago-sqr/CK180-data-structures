/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 12-2: 22-jul-2024
 *
 *   Implementação de dicionário usando lista encadeada e nó sentinela
 */

#include <iostream>

using namespace std;

class Dicio {
    struct Par {
        int chave;
        string valor;
        Par *prox;
    };
    
    Par* sentinela;

public:
    Dicio() {
        sentinela = new Par;
        sentinela->prox = sentinela;
    }

    struct ResConsulta {
        bool achado;
        string valor;
    };

    ResConsulta consultar(int chave) {
        sentinela->chave = chave;
        Par *cursor = sentinela->prox;
        ResConsulta res {false, "Chave não encontrada"};
        while (cursor->chave != chave) {
            cursor = cursor->prox;
        }
        if (cursor == sentinela) {
            return res;
        }
        res.achado = true;
        res.valor = cursor->valor;
        return res;
    } 

    // Considerando chave não repetida
    void inserir(int chave, string valor) {
        sentinela->prox = new Par {chave, valor, sentinela->prox};
    }

    void inserir_se_novo(int chave, string valor) {
        ResConsulta res = consultar(chave);
        if (not res.achado) {
            inserir(chave, valor);
        }
    }

    void remover(int chave) {
        sentinela->chave = chave;
        Par *cursor = sentinela->prox;

        if (cursor != sentinela and cursor->chave == chave) {
            Par *aux = cursor;
            sentinela->prox = cursor->prox;
            delete aux; 
            return;
        }
        while (cursor->prox->chave != chave) {
            cursor = cursor->prox;
        }
        if (cursor->prox == sentinela) {
            return;
        }
        Par *aux = cursor->prox;
        cursor->prox = aux->prox;
        delete aux;
    }

    ~Dicio() {
        Par *cursor = sentinela->prox;
        while (cursor != sentinela) {
            sentinela->prox = cursor->prox;
            delete cursor;
            cursor = sentinela->prox;
        }
        delete sentinela;
    }
};
