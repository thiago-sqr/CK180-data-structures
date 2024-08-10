/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 14-1: 29-jul-2024
 *
 *   Dicionário com tabela hash de dimensão fixa
 */
#include <iostream>

using namespace std;

class Dicio {
    struct No {
        int chave;
        string valor;
        No *prox;
    };

    int tamanho;
    No **tabela;

    int hash(int chave) {
        return chave % tamanho;
    }

public:
    Dicio(int tamanho) : tamanho{tamanho} {
        tabela = new No* [tamanho];
        for (int i = 0; i < tamanho; i++) {
            tabela[i] = nullptr;
        }
    }

    struct ResConsulta {
        bool achado;
        string valor;
    };

    ResConsulta consultar(int chave) {
        ResConsulta res{false, "Chave invalida"};
        int index = hash(chave);
        No *cursor = tabela[index];
        while (cursor != nullptr) {
            if (cursor->chave == chave) {
                res.achado = true;
                res.valor = cursor->valor;
                return res;
            }
            cursor = cursor->prox;
        }
        return res;
    }

    void inserir(int chave, string valor) {
        int index = hash(chave);
        tabela[index] = new No{chave, valor, tabela[index]};
    }

    void inserirSeNovo(int chave, string valor) {
        if (not consultar(chave).achado) {
            inserir(chave, valor);
        }
    }

    void remover(int chave) {
        int index = hash(chave);
        if (tabela[index] == nullptr) return;
        No *cursor = tabela[index];
        if (cursor->chave == chave) {
            cursor = cursor->prox;
            delete cursor;
            return;
        }
        while (cursor->prox != nullptr) {
            if (cursor->prox->chave == chave) {
                No *aux = cursor->prox;
                cursor->prox = aux->prox;
                delete aux;
                return;
            }
            cursor = cursor->prox;
        }
    }

    ~Dicio() {
        for (int i = 0; i < tamanho; i++) {
            while (tabela[i] != nullptr) {
                int chave = tabela[i]->chave;
                remover(chave);
            }
        }
        delete[] tabela;
    }

};