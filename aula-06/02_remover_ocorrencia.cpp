/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 05-2: 11-mar-24
*
*   Remoção de ocorrencias utilizando ponteiros
*/
#include <iostream>

using namespace std;

/* item (a) forma recursiva */
int remover_ocorrencias(double *vetor, int n, double x)
{
    if (n <= 0) return 0;

    for (int i = 0; i < n; i++)
    {
        if (vetor[i] == x)
        {
            vetor[i] = vetor[n - 1];
            n = remover_ocorrencias(vetor, n - 1, x);
        }
    }
    return n;
}

/* item (b) */
int main()
{
    int n;
    do
    {
        cout << "Digite um numero de zero a dez: ";
        cin >> n;
    } while (n > 10 && n <= 0);

    double vetor[n];

    cout << "Digite " << n << " valores:" << endl;
    for (int i = 0; i < n; i++)
    {
        double valor;
        cin >> valor;
        vetor[i] = valor;
    }

    double *ptr = &vetor[0];
    double x;

    cout << "Digite o valor para remover do vetor: ";
    cin >> x;

    n = remover_ocorrencias(ptr, n, x);

    for (int i = 0; i < n; i++) {
        cout << vetor[i] << " ";
    }
}
