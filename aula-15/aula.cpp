/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Aula 15: 5-ago-2024
 *
 *   Implementação de dicionário com tabelas de dispersão
 *   - mantemos tamanho>=elementos; 
 *   - podemos começar com tamanho = 1; 
 *   - utilizemos hash(chave) = chave % tamanho;
 */
#include <iostream>

using namespace std;

class Dicio {
    struct No {
        int chave;
        string valor;
        No *prox;
    };

    No **tabela; 
    No sentinela;
    int tamanho;
    int elementos;

    void redimensionar(int novoTamanho) {
        No **novaTabela = new No* [novoTamanho];
        int tamanhoAntigo = tamanho;
        tamanho = novoTamanho; //atualiza a função hash

        for (int i = 0; i < novoTamanho; i++) {
            novaTabela[i] = &sentinela;
        }

        for (int i = 0; i < tamanhoAntigo; i++) {
            No *cursor = tabela[i];
            while (cursor != &sentinela) {
                int novoIndex = hash(cursor->chave);
                No *aux = cursor->prox;
                cursor->prox = novaTabela[novoIndex];
                novaTabela[novoIndex] = cursor;
                cursor = aux;
            }
        }
        delete[] tabela;
        tabela = novaTabela;
    }

    int hash(int chave) {
        return chave % tamanho;
    }

public:
    Dicio() : tamanho{1}, elementos{0} {
        tabela = new No* [tamanho];
        for (int i = 0; i < tamanho; i++) {
            tabela[i] = &sentinela;
        }
    }

    void inserir(int chave, string valor) {
        if (tamanho == elementos) {
            redimensionar(tamanho * 2);
        }
        int index = hash(chave);
        tabela[index] = new No{chave, valor, tabela[index]};
        ++elementos;
    }

    struct ResConsulta {
        bool achado;
        string valor;
    };

    ResConsulta consultar(int chave) {
        // TODO
    }

    void inserirSeNovo(int chave, string valor) {
        // TODO
    }

    void remover(int chave) {
        // TODO
    }

    ~Dicio() {
        // TODO
    }
};
