/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 13-1: 25-jul-2024
 *
 *   Soma de matrizes
 */
#include "matriz.cpp"
#include <iostream>

Matriz soma(Matriz &m1, Matriz &m2) {
    Matriz resultado(m1.getColunas(), m1.getColunas());
    for (int i = 0; i < m1.getLinhas(); i++) {
        for (int j = 0; j < m1.getColunas(); j++) {
            resultado(i,j) = m1(i,j) + m2(i,j);
        }
    }
    return resultado;
}

int main() {

    std::cout << "Informe as dimensoes da matriz 1\n";
    int l1, c1; std::cin >> l1; std::cin >> c1;

    std::cout << "Informe as dimensoes da matriz 2\n";
    int l2, c2; std::cin >> l2; std::cin >> c2;

    if (l1 != l2 or c1 != c2) {
        std::cout << "Dimensoes invalidas\n";
        return 1;
    }

    Matriz m1(l1, c1);
    Matriz m2(l2, c2);

    std::cout << "Preencha a matriz 1\n";
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c1; j++) {
            std::cin >> m1(i,j);
        }
    }

    std::cout << "Preencha a matriz 2\n";
    for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            std::cin >> m2(i,j);
        }
    }

    Matriz resultado = soma(m1, m2);

    std::cout << "Resultado:\n";
    for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            std::cout << resultado(i,j) << " ";
        }
        std::cout << std::endl;
    }
}