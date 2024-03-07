## EXERCÍCIOS AULA 04

### (Q01)

Implemente em C++ um conjunto limitado via vetor desordenado, conforme explicado em sala, com particular atenção ao procedimento de remoção (não realizando deslocamento dos elementos à direita do elemento removido). Inclua uma função vazio, que informe se o conjunto está ou não vazio. Inclua também uma função cheio, que informe se o conjunto está ou não cheio.

### (Q02)

Implemente em C++ um conjunto limitado via vetor ordenado, utilizando na função "pertence" o algoritmo de busca binária discutido em sala. Inclua as funções vazio e cheio.

### (Q03)

Escreva uma versão recursiva do algoritmo de busca binária.

### (Q04)

Escreva uma variação do algoritmo de busca binária que, ao invés de informar se o elemento "x" está ou não presente, informe a posição em que o elemento deveria ser inserido; essa posição é aquela imediatamente após o último dos elementos menores que "x" (caso haja; se não houver nenhum menor, a posição é zero). Naturalmente, essa versão alternativa do algoritmo não tem como propósito ser usada na função "pertence" de uma implementação de conjunto; no caso, o intuito seria aproveitá-la para realizar uma versão um pouco mais eficiente da função de inserção, que usaria busca binária no lugar de busca linear para descobrir o local onde o elemento deve ser inserido.