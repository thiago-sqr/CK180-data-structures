## Exercícios Aula 17

### (Q1)
Implementar um procedimento de remoção em lista simplesmente encadeada que não necessite testar se o nó removido é o primeiro da lista (sendo portanto apontado pelo ponteiro inicial da lista) ou se não é (nesse caso sendo apontado pelo campo "prox" do nó anterior).

### (Q2)
Escrever uma variação da nossa implementação de árvore em que não haja duplicação do processo de procurar um nó. Mais especificamente, você pode escrever uma função privada que sirva para procurar um nó, mas que retorne um ponteiro apontando para o ponteiro da árvore que aponta para o nó (que pode ser o ponteiro raiz ou um ponteiro de filho esquerdo ou direito), caso o nó exista (e se o nó não existir?). Nesse caso, essa função pode ser utilizada para evitar a repetição do procedimento de busca realizado pelas funções "inserir", "pertence" e "remover".

### (Q3)
Escreva uma variação da implementação de hoje que:
    - Possua, na estrutura do nó, também um ponteiro para o nó "pai" (que naturalmente será nulo no caso da raiz).
    - Na função "inserir", retorne um ponteiro apontando para o nó inserido (o ideal, para fins de encapsulamento/abstração, seria retornar um "iterador" para o nó, mas esse tipo não foi definido em aula, então retornar um ponteiro para o nó é mais simples de explicar). Observe que, nesse caso, a definição do tipo "Noh" tem que ficar fora do tipo "ConjABB".
    - Na função "remover", ao invés de receber um double, receba um ponteiro para o nó a ser removido. Observe que, nesse caso, o nó não precisa ser procurado. Além disso, como todo nó possui um ponteiro para o "pai", então a remoção pode ser iniciada imediatamente.
