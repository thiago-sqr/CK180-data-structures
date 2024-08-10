/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 13-4: 25-jul-2024
 *
 *   Implementação alternativa de matrizes
 */
#include <iostream>

class Matriz {
    int num_lin, num_col;
    double *vetor;

public:
    Matriz(int linhas, int colunas) : num_lin{linhas}, num_col{colunas} {
        vetor = new double [linhas * colunas];
    }

    double& operator() (int i, int j) {
        return vetor[(i * num_col) + j];
    }

    int getLinhas() {
        return num_lin;
    }

    int getColunas() {
        return num_col;
    }

    ~Matriz() {
        delete[] vetor;
    }
};