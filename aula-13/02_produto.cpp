/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 13-2: 25-jul-2024
 *
 *   Produto de matrizes
 */
#include "matriz.cpp"
#include <iostream>

// Assumindo A.num_col = B.num_lin
Matriz produto(Matriz &A, Matriz &B) {
    int dimensaoFixa = A.getColunas();
    int estaticoA = 0, estaticoB = 0, dinamico;

    Matriz resultado(A.getLinhas(), B.getColunas());

    for (int i = 0; i < resultado.getLinhas(); i++) {
        for (int j = 0; j < resultado.getColunas(); j++) {
            resultado(i,j) = 0;
            for (dinamico = 0; dinamico < dimensaoFixa; dinamico++) {
                resultado(i,j) += A(estaticoA, dinamico) * B(dinamico, estaticoB);
            }
            estaticoB++;
        }
        estaticoA++;
        estaticoB = 0;
    }
    return resultado;
}

int main() {
    Matriz A(2,4);
    Matriz B(4,2);

    A(0,0) = 1; A(0,1) = 2; A(0,2) = 3; A(0,3) = 7;
    A(1,0) = 4; A(1,1) = 5; A(1,2) = 6; A(1,3) = 8;

    B(0,0) = 1; B(0,1) = 2;
    B(1,0) = 3; B(1,1) = 4;
    B(2,0) = 5; B(2,1) = 6;
    B(3,0) = 7; B(3,1) = 8;

    Matriz res = produto(A,B);

    std::cout << "Resultado:\n";
    for (int i = 0; i < res.getLinhas(); i++) {
        for (int j = 0; j < res.getColunas(); j++) {
            std::cout << res(i,j) << " ";
        }
        std::cout << std::endl;
    }
}