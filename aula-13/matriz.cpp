/*Classe base*/

class Matriz {
    int num_lin, num_col;
    double **matriz;

public:
    Matriz(int linhas, int colunas) : num_lin{linhas}, num_col{colunas} {
        matriz = new double* [linhas];
        for (int i = 0; i < linhas; i++) {
            matriz[i] = new double [colunas];
        }
    }

    double& operator() (int i, int j) {
        return matriz[i][j];
    }

    int getLinhas() {
        return num_lin;
    }

    int getColunas() {
        return num_col;
    }

    ~Matriz() {
        for (int i = 0; i < num_lin; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
};