/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 12-1: 22-jul-2024
 *
 *   Implementação de dicionário usando lista duplamente encadeada
 */
#include <iostream>

using namespace std;

class Dicio {
    struct Par {
        Par *ant;
        int chave;
        string valor;
        Par *prox;
    };

    Par *init;

public:
    Dicio() : init{nullptr} {}

    struct ResConsulta {
        bool achado;
        string valor;
    };

    ResConsulta consultar(int chave) {
        Par *cursor = init;
        ResConsulta res {false, "Chave não encontrada"};
        while (cursor != nullptr) {
            if (cursor->chave == chave) {
                res.achado = true;
                res.valor = cursor->valor;
                break;
            }
            cursor = cursor->prox;
        }
        return res;
    }


    void inserir(int chave, string valor) {
        Par *novo = new Par{nullptr, chave, valor, init};
        if (init != nullptr) {
            init->ant = novo;
        }
        init = novo;
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
            init->ant = nullptr;
            delete cursor;
            return;
        }
        while (cursor != nullptr) { 
            if (cursor->chave == chave) {
                cursor->ant->prox = cursor->prox;
                if (cursor->prox != nullptr) {
                    cursor->prox->ant = cursor->ant;
                }
                delete cursor;
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

int main() {

    Dicio d;

    d.inserir(10, "Ana");
    d.inserir_se_novo(10, "oi");
    d.inserir_se_novo(20, "Bob");
    d.inserir(30, "Clara");

    Dicio::ResConsulta res = d.consultar(10);
    cout << "chave 10 : " << res.valor << endl;
    res = d.consultar(20);
    cout << "chave 20 : " << res.valor << endl;
    res = d.consultar(40);
    if (not res.achado) {
        cout << "Achei nada \n";
    }
    d.remover(20);

}