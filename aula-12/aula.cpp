/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Aula 12: 22-jul-2024
 *
 *   Implementação de dicionário usando lista encadeada
 */

#include <iostream>

using namespace std;

class Dicio {
    struct Par {
        int chave;
        string valor;
        Par *prox;
    };

    struct ResConsulta {
        bool achado;
        string valor;
    };

    Par* init;

public:
    Dicio() : init{nullptr} {}

    ResConsulta consultar(int chave) {
        Par *cursor = init;
        ResConsulta res {false,"Chave não encontrada"};
        while (cursor != nullptr) {
            if (cursor->chave = chave) {
                res.achado = true;
                res.valor = cursor->valor;
                break;
            }
            cursor = cursor->prox;
        }
        return res;
    } 

    // Considerando chave não repetida
    void inserir(int chave, string valor) {
        init = new Par {chave, valor, init};
    }

    void inserir_se_novo(int chave, string valor) {
        ResConsulta res = consultar(chave);
        if (not res.achado) {
            inserir(chave, valor);
        }
    }

    void remover(int chave) {
        Par *cursor = init;
        if (init == nullptr) {
            return;
        }
        if (init->chave == chave) {
            init = init->prox;
            delete cursor;
            return;
        } 
        while (cursor->prox != nullptr) {
            if (cursor->prox->chave == chave) {
                Par *aux = cursor->prox;
                cursor->prox = aux->prox;
                delete aux;
                return;
            }
            cursor = cursor->prox;
        }
    }

    ~Dicio() {
        Par *cursor = init;
        while (init != nullptr) {
            init = init->prox;
            delete cursor;
            cursor = init;
        }
    }
};