/*
*   Engenharia de Computação, DETI~DC, UFC
*   Exercício 06-1: 14-mar-24
*
*   Implementação uma função inversora com ponteiros
*/
#include <iostream>

using namespace std;

/* item (a) */
void inverter(double *p, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        double aux = p[i];
        p[i] = p[(n - 1) - i];
        p[(n - 1) - i] = aux;
    }
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

    double *p = &vetor[0];

    inverter(p, n);

    for (int i = 0; i < n; i++) {
        cout << vetor[i] << " ";
    }
}
