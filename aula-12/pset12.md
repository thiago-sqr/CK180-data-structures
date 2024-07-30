## Exercícios Aula 12

### (Q1)
Escreva uma variação da implementação de dicionário feita em sala que utilize lista duplamente encadeada.

### (Q2)
Uma causa típica de erros em implementações usando listas encadeadas é tentar manipular um nó através de um ponteiro sem lembrar de testar se esse ponteiro é ou não nulo. Esse problema aumenta quando há múltiplos ponteiros sendo testados de forma combinada, como no caso de uma lista duplamente encadeada. Uma solução muitas vezes satisfatória para esse problema é usar um nó sentinela, que é um nó extra, feito para nunca armazenar um elemento propriamente dito da contêiner (exceto temporariamente, como auxílio em determinadas operações), tendo o propósito específico de marcar o fim da lista encadeada. Assim sendo, escreva uma variação da implementação feita em sala, de forma que o último nó aponte para um nó sentinela, ao invés de para nulo. O campo "prox" da sentinela simplesmente não precisa ser preenchido: os percursos da lista devem terminar quando o nó sentinela for atingido.

### (Q3)
Escreva uma implementação de conjunto via lista duplamente encadeada, incorporando os elementos das 2 questões anteriores e mais, como segue:

a) Utilize uma lista duplamente encadeada;

b) Utilize um nó sentinela para marcar o início e o fim da lista, observando que um único nó sentinela é suficiente para marcar início e fim, pois ele pode ser simultaneamente o "anterior do primeiro" e o "próximo do último" (lista circular);

c) Observe que o nó sentinela não precisa ser alocado dinamicamente: ele pode ser um campo da estrutura do conjunto, assim como o ponteiro para o início da lista é um campo dessa estrutura;

d) Observe também que, se o nó sentinela for um campo da estrutura do conjunto, então o ponteiro "início" não é mais necessário, pois o início e o fim da lista são acessíveis diretamente a partir do nó sentinela;

e) Observe que, ao procurar um elemento, nós não precisamos fazer 2 testes por iteração. Mais especificamente, em cada iteração, ao invés de testar "1. chegamos ao final da lista (isto é, ao nó sentinela)?" e "2. Achamos o elemento procurado no nó atual?", basta testar "2. Achamos o elemento procurado no nó atual?", desde que, antes de iniciar o percurso, nós tenhamos copiado no nó sentinela o elemento a ser procurado. Observe que, nesse caso, o elemento procurado sempre vai ser encontrado, quer num nó da lista propriamente dito (caso o elemento procurado pertença ao conjunto), quer no nó sentinela (caso o elemento não esteja no conjunto), onde nós colocamos o elemento antes de iniciar o laço da busca; por essa razão, ao encontrar o elemento procurado, é necessário testar se ele foi encontrado no nó sentinela ou não, pois isso determinará se o elemento de fato está no conjunto ou não.