/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 14-3: 29-jul-2024
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
        tamanho = novoTamanho;

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

    struct ResConsulta {
        bool achado;
        string valor;
    };

    ResConsulta consultar(int chave) {
        ResConsulta res {false, "Chave nao encontrada"};
        sentinela.chave = chave;
        No *cursor = tabela[hash(chave)];
        while (cursor->chave != chave) {
            cursor = cursor->prox;
        }
        if (cursor != &sentinela) {
            res.achado = true;
            res.valor = cursor->valor;
        }
        return res;
    }

    void inserir(int chave, string valor) {
        if (tamanho == elementos) {
            redimensionar(tamanho * 2);
        }
        int index = hash(chave);
        tabela[index] = new No{chave, valor, tabela[index]};
        ++elementos;
    }

    void inserirSeNovo(int chave, string valor) {
        if (not consultar(chave).achado) {
            inserir(chave, valor);
        }
    }

    void remover(int chave) {
        int index = hash(chave);
        if (tabela[index] == &sentinela) return;

        No *cursor = tabela[index];

        if (cursor->chave == chave) {
            tabela[index] = cursor->prox;
            delete cursor;
        } else {
            sentinela.chave = chave;
            while (cursor->prox->chave != chave) {
                cursor = cursor->prox;
            }
            if (cursor->prox == &sentinela) return;
            No *aux = cursor->prox;
            cursor->prox = aux->prox;
            delete aux;           
        }

        elementos--;
        if (tamanho == elementos * 4) {
            redimensionar(tamanho / 2);
        }
    }

    ~Dicio() {
        for (int i = 0; i < tamanho; i++) {
            while (tabela[i] != nullptr) {
                No *aux = tabela[i];
                tabela[i] = tabela[i]->prox;
                delete aux;
            }
        }
        delete[] tabela;
    }
};
