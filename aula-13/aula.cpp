/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Aula 13: 25-jul-2024
 *
 *   Implementação de matriz
 */

#include <iostream>

class Matriz {
    int num_lin, num_col;
    double **matriz;

public:
    Matriz(int linhas, int colunas) : num_lin{linhas}, num_col{colunas} {
        matriz = new double* [linhas];
        for (int i = 0; i < linhas; i++) {
            matriz[i] = new double [colunas];
            // *(matriz + i) == matriz[i]
        }
    }

    void atribuir(int i, int j, double valor) {
        matriz[i][j] = valor;
    }

    double acessar(int i, int j) {
        return matriz[i][j];
    }

    double* acessar_pont(int i, int j) {
        return & matriz[i][j];
    } 

   double& acessar_ref(int i, int j) {
       return matriz[i][j];
   }

   double& operator() (int i, int j) {
       return matriz[i][j];
   }

    ~Matriz() {
        for (int i = 0; i < num_lin; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
};

int main() {
    try {
        int linhas = 2;
        int colunas = 2;
        Matriz m(linhas, colunas);

        // formas de atribuir;
        m(0,0) = 1.1;
        m.atribuir(0, 1, 2.2);
        *(m.acessar_pont(1,0)) = 3.3;
        m.acessar_ref(1,1) = 4.4;

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                std::cout << m(i,j) << " ";
            }
            std::cout << std::endl;
        }
    } catch (std::exception& e) {

    }
}