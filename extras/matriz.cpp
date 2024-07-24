/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício Extra 01: 03-mai-2024
*
*   Implementação de soma e matrizes
*/
#include <iostream>

struct Matriz
{
    double* *matriz;
    int linhas, colunas;
};

bool criar_matriz(Matriz &m, int linhas, int colunas)
{
    m.linhas = linhas;
    m.colunas = colunas;
    m.matriz = nullptr;
    try
    {
        m.matriz = new double* [linhas] {};
        for (int i = 0; i < linhas; i++)
        {
            m.matriz[i] = new double [colunas];
        }
    }
    catch (const std::exception& e)
    {
        if (m.matriz != nullptr) 
        {
            for (int i = 0; i < m.linhas; i++) 
            {
                delete[] m.matriz[i];
            }
            delete[] m.matriz;
            m.matriz = nullptr;
        }
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

void destruir_matriz(Matriz &m)
{
    if (m.matriz == nullptr) return;

    for (int i = 0; i < m.linhas; i++)
    {
        delete[] m.matriz[i];
    }
    delete[] m.matriz;
    m.matriz = nullptr;
}

Matriz somar_matrizes(Matriz &m1, Matriz &m2)
{
    Matriz resultado;
    if (m1.linhas != m2.linhas or m1.colunas != m2.colunas)
    {
        std::cerr << "Entradas não possuem mesmo tamanho\n";
        resultado.matriz = nullptr;
        return resultado;
    }

    if (not criar_matriz(resultado, m1.linhas, m1.colunas))
    {
        std::cerr << "Erro ao criar matriz resultado\n";
        return resultado;
    }

    for (int i = 0; i < m1.linhas; i++)
    {
        for (int j = 0; j < m1.colunas; j++)
        {
            resultado.matriz[i][j] = m1.matriz[i][j] + m2.matriz[i][j];
        }
    }
    return resultado;
}

void preencher_matriz(Matriz &m)
{
    for (int i = 0; i < m.linhas; i++)
    {
        for (int j = 0; j < m.colunas; j++)
        {
            std::cin >> m.matriz[i][j];
        }
    }
}

int main()
{
    Matriz m1, m2;
    int linhas, colunas;

    std::cout << "Indique as dimensoes de M1 e M2\n";
    std::cin >> linhas >> colunas;

    if (not criar_matriz(m1, linhas, colunas)) 
    {
        std::cerr << "Erro ao criar matrizes\n";
        return 1;
    }

    if (not criar_matriz(m2, linhas, colunas)) 
    {
        destruir_matriz(m1);
        std::cerr << "Erro ao criar matrizes\n";
        return 1;
    }

    std::cout << "Preencher M1\n";
    preencher_matriz(m1);

    std::cout << "Preencher M2\n";
    preencher_matriz(m2);
    
    std::cout << "\nResultado M1 + M2\n";

    Matriz resultado = somar_matrizes(m1, m2);

    if (resultado.matriz == nullptr)
    {
        destruir_matriz(m1); destruir_matriz(m2);
        std::cerr << "Erro ao somar matriz\n";
        return 2;
    }

    for (int i = 0; i < resultado.linhas; i++)
    {
        for (int j = 0; j < resultado.colunas; j++)
        {
            std::cout << resultado.matriz[i][j] << ' ';
        }
        std::cout << '\n';
    }

    destruir_matriz(m1); destruir_matriz(m2); destruir_matriz(resultado);
}
