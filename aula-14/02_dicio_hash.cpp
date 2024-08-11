/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 14-2: 29-jul-2024
 *
 *   Dicionário com tabela hash de dimensão variável
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
    int tamanho;
    int elementos;

    int hash(int chave) {
        return chave % tamanho;
    }

    void redimensionar(int novoTamanho) {
        int tamanhoAntigo = tamanho;
        tamanho = novoTamanho;
        No **novaTabela = new No* [novoTamanho];

        for (int i = 0; i < novoTamanho; i++) {
            novaTabela[i] = nullptr;
        }

        for (int i = 0; i < tamanhoAntigo; i++) {
            while (tabela[i] != nullptr) {
                int novoIndex = hash(tabela[i]->chave);
                No *aux = tabela[i]->prox;
                tabela[i]->prox = novaTabela[novoIndex];
                novaTabela[novoIndex] = tabela[i];
                tabela[i] = aux;
            }
        }
        delete[] tabela;
        tabela = novaTabela;
    }

public:
    Dicio() : tamanho{1}, elementos{0} {
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
        ResConsulta res{false, "Chave nao encontrada"};
        for (No* cursor = tabela[hash(chave)]; cursor != nullptr; cursor = cursor->prox) {
            if (cursor->chave == chave) {
                res.achado = true;
                res.valor = cursor->valor;
                break;
            }
        }
        return res;
    }

    void inserir(int chave, string valor) {
        if (tamanho == elementos) {
            redimensionar(tamanho * 2);
        }
        int index = hash(chave);
        tabela[index] = new No{chave, valor, tabela[index]};
        elementos++;
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
            tabela[index] = cursor->prox;
            delete cursor;
            elementos--;
        } else {
            while (cursor->prox != nullptr) {
                if (cursor->prox->chave == chave) {
                    No *aux = cursor->prox;
                    cursor->prox = aux->prox;
                    delete aux;
                    elementos--;
                    break;
                }
                cursor = cursor->prox;
            }
        }
        if (tamanho == elementos * 4) {
            redimensionar(tamanho / 2);
        }
    }

    ~Dicio(){
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