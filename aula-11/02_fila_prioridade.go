/*
 *   Engenharia de Computação, DETI~DC, UFC
 *   Exercício 11-2: 18-jul-2024
 *
 *   Implementação de deque usando lista duplamente encadeada
 */
package fila

type No struct {
	valor int
	prox  *No
}

type Fila struct {
	inicio, fim *No
}

func novaFila() *Fila {
	return &Fila{inicio: nil, fim: nil}
}

func (f *Fila) vazia() bool {
	return (f.fim == nil && f.inicio == nil)
}

func (f *Fila) inserir(x int) {
	novoNo := &No{valor: x, prox: nil}
	if f.fim == nil {
		f.inicio = novoNo
	} else {
		f.fim.prox = novoNo
	}
	f.fim = novoNo
}

func (f *Fila) inserirPrioridade(x int) {
	novoNo := &No{valor: x, prox: f.inicio}
	if f.vazia() {
		f.fim = novoNo
	}
	f.inicio = novoNo
}

// Considerando fila não vazia
func (f *Fila) remover() {
	if f.inicio == f.fim {
		f.inicio = nil
		f.fim = nil
	} else {
		f.inicio = f.inicio.prox
	}
}

// Considerando fila não vazia
func (f *Fila) consultar() int {
	return f.inicio.valor
}

func (f *Fila) destruirFila() {
	f.inicio = nil
	f.fim = nil
}
