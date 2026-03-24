# TAD Fila (Queue)

## Introdução

A **fila** é uma **estrutura de dados linear** em que os elementos são
organizados de forma sequencial, e as operações de inserção e remoção
ocorrem em **extremidades opostas** da estrutura.

Essa organização segue o princípio **FIFO --- First In, First Out**, ou seja > **o primeiro elemento inserido é o primeiro a ser removido**

Esse comportamento modela situações reais do cotidiano, como:

-   filas de atendimento
-   impressão de documentos
-   processamento de tarefas
-   buffers de comunicação

Representação conceitual:

    frente            traseira
      ↓                  ↓
    [10] [20] [30] [40] [50]

------------------------------------------------------------------------

# Estrutura Linear

A fila pertence à classe das **estruturas lineares**, caracterizadas
por:

-   organização sequencial dos elementos
-   relação de ordem bem definida
-   cada elemento possui:
    -   um predecessor (exceto o primeiro)
    -   um sucessor (exceto o último)

Formalmente:

(a1, a2, a3, ..., an)

Na fila:

-   **a1** → elemento da **frente**
-   **an** → elemento da **traseira**

------------------------------------------------------------------------

# Definição Formal do TAD Fila

TAD = (D, O)

------------------------------------------------------------------------

## Domínio da Fila

D = { (a1, a2, ..., an) \| ai ∈ E, n ≥ 0 }

------------------------------------------------------------------------

# Operações do TAD Fila

As operações de uma fila são bem definidas e possuem comportamento restrito.

## criar()
Cria uma fila vazia

criar() → Fila

## enqueue(x)
Insere um elemento no final da fila.

enqueue(F, x) = (a1, ..., an, x)

## dequeue()
Remove o elemento da frente da fila.

dequeue(F) = (a2, ..., an)

## front()
Retorna o elemento da frente sem removê-lo.

front(F) = a1

## rear()
Retorna o elemento da traseira.

rear(F) = an


------------------------------------------------------------------------

# Implementação Sequencial (Array)

Uso de vetor com dois índices: front e rear.

``` c
struct fila {
    int dados[MAX];
    int front;
    int rear;
};
```

------------------------------------------------------------------------

# Problema na Remoção

## Abordagem 1: Remoção com Shift
Funcionamento:

* remove o elemento da posição 0

* desloca todos os elementos

``` c
for (int i = 0; i < n-1; i++) {
    fila[i] = fila[i+1];
}
```
Análise:

* Complexidade: O(n)
* Muito custoso
* Ineficiente para grandes volumes



## Abordagem 2: Fila Circular
O vetor é tratado como circular. Quando chega ao final:

```
indice = (indice + 1) % capacidade
```

Vantagens: 
-   Sem deslocamento
-   Inserção: O(1)
-   Remoção: O(1)
-    Melhor uso da memória

Exemplo:

              fim   inicio
               ↓     ↓
    [10] [20] [30] [40] [50]


------------------------------------------------------------------------

