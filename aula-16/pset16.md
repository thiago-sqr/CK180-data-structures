## Exercícios Aula 16

### (Q1)
Escreva uma função que receba um vetor com números em ordem crescente e que retorne uma árvore binária de busca contendo esses números. Essa árvore deve ser a melhor possível, no sentido de que sua raiz deve ser "o elemento do meio" do vetor, e analogamente para cada subárvore, atingindo assim a menor altura possível. Você pode escolher os parâmetros a serem recebidos pela função, mas ela deve retornar um ponteiro para a raiz da árvore criada.

### (Q2)
Na questão anterior, nenhuma exigência foi feita para o caso de faltar memória para alocar os nós da árvore; implicitamente, em caso de falta de memória, a função deveria apenas propagar o bad_alloc jogado pelo operador new, sem tratar a memória que já havia sido alocada. A sua tarefa agora é escrever uma variação da função da questão anterior que, em caso de falha de alocação de memória, antes de encerrar sua execução, desaloque todos os nós que haviam sido alocados anteriormente. Você escolhe se, nesse cenário, a função continua jogando uma exceção ou se, ao invés disso, ela retorna um ponteiro nulo. Neste segundo caso, você pode considerar útil utilizar a variação do operador new que, em caso de falha de alocação, ao invés de jogar uma exceção, retorna um ponteiro nulo: "new(std::nothrow)"; exemplo: "int *v = new(std::nothrow) int [10]".
