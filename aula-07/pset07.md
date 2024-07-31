## EXERCÍCIOS AULA 07

### (Q1)

Escreva uma implementação de pilha ilimitada, no sentido de que ela não deve possuir um limite conhecido a priori para o número de elementos passíveis de nela serem armazenados. Ao invés de um vetor de tamanho fixo, a "struct" deve possuir um ponteiro que, durante a execução da função de inicialização, deve receber um pequeno vetor alocado dinamicamente. Sempre que a função "empilhar" encontrar o vetor cheio, ela deve (1) alocar um vetor maior, (2) copiar para ele os elementos da pilha, (3) desalocar o vetor atual e (4) passar a utilizar o vetor maior como o vetor da pilha.

### (Opcional) 

Com base na sintaxe ilustrada no programa abaixo para templates, reescreva a sua implementação de pilha do programa da questão anterior de forma que ela seja genérica quanto ao tipo. Em seguida, teste a sua implementação, criando e utilizando pilhas de diferentes tipos.

```
#include <iostream>
using namespace std;

template <typename TX, typename TY>
struct Par
{
   TX x;
   TY y;
};

template <typename TX, typename TY>
TX primeiro (Par<TX,TY> p)
{
   return p.x;
}


template <typename A, typename B>
B segundo (Par<A,B> p)
{
   return p.y;
}

int main ()
{
   Par<double,char> p {3.14, '!'};

   cout << "{ " << primeiro (p) << ", " << segundo (p) << " }\n";

   Par <int, Par<double,char> > q { 10, p };

   cout << primeiro(segundo(q)) << '\n';
}
```