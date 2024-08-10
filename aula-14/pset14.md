## Exercícios Aula 14

### (Q1)
Escreva uma primeira implementação, ainda incompleta, de dicionário para chave "int" e valor "string" via tabela de dispersão. Essa primeira versão não deve redimensionar a tabela, que deverá ter sempre o mesmo tamanho (>= 1), recebido como argumento no construtor. Utilize "h(c) = c % m" como função de dispersão, sendo "m" o tamanho da tabela (vetor), e resolva colisões através de encadeamento externo, usando lista encadeada.

### (Q2)
Refine a implementação do item anterior, transformando-a numa verdadeira tabela de dispersão dinâmica, mantendo "m >= n", sendo "n" o número de elementos correntemente armazenados na tabela. A cada expansão, você deve percorrer todos os elementos da tabela original e levá-los para a nova tabela, lembrando de usar a função de dispersão de forma a levar o elemento para a lista correta (ou seja, se um elemento estava na lista "i" da tabela original, é possível que, na nova tabela, ele passe a uma lista j != i).
Refine ainda mais a implementação anterior, implementando também a contração da tabela, de forma a manter "n >= m/4" (ou "m <= 4*n").

### (Q3)
Para concluir os refinamentos da implementação, implemente uma variação da resposta anterior utilizando um nó sentinela, a ser compartilhado por todas as listas encadeadas da tabela (dica: esse nó não precisa ser alocado dinamicamente, podendo ser um dos campos da estrutura do próprio dicionário).