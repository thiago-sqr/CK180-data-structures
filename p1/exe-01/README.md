## EXERCÍCIOS AULA 01

### (Q01)

Tenha um compilador C++ para usar quando necessário, sabendo que há diferentes caminhos para isso:

Na pressa, basta buscar por "online C++ compiler" no Google, lembrando que também há aplicativos para celular (exemplo: para Android);

Para uso regular, o mais conveniente é ter um compilador instalado no computador. Instalar uma IDE pode ser uma alternativa rápida: Visual Studio Code (com seu pacote para C++), Code::Blocks, Dev-C++, etc.

Você também pode separar o editor de texto do compilador, que é como eu farei em sala. No Windows, o Notepad++ é um editor simples e popular, e para o compilador você pode instalar o MSYS2 e em seguida o pacote mingw-w64-i686-gcc.
Você pode testar a sua instalação com este programa:

```
#include <iostream>

int main ()
  {
   std::cout << "Olá, mundo!\n";
  }
```