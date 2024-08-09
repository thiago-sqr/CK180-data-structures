/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 13-3: 25-jul-2024
 *
 *   Transposta de matrizes
 */
#include "matriz.cpp"
#include <iostream>

Matriz transpor(Matriz &A) { 
    Matriz transposta(A.getColunas(), A.getLinhas());
    for (int i = 0; i < A.getLinhas(); i++) {
        for (int j = 0; j < A.getColunas(); j++) {
            transposta(j,i) = A(i,j);
        }
    }
    return transposta;
}

int main() {
    Matriz B(4,2);
    B(0,0) = 1; B(0,1) = 2;
    B(1,0) = 3; B(1,1) = 4;
    B(2,0) = 5; B(2,1) = 6;
    B(3,0) = 7; B(3,1) = 8;

    Matriz trans = transpor(B);

    for (int i = 0; i < trans.getLinhas(); i++) {
        for (int j = 0; j < trans.getColunas(); j++) {
            std::cout << trans(i,j) << " ";
        }
        std::cout << std::endl;
    }
}