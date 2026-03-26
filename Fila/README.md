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
```text
 frente            traseira
   ↓                  ↓
 [10] [20] [30] [40] [50]
```
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

# Classificação das Implementações

Ao implementar concretamente um Tipo Abstrato de Dados (TAD), podemos classificar a implementação segundo dois critérios independentes:

* Forma de *representação dos dados na memória*: como os elementos se relacionam logicamente.

* Forma de *alocação da memória*: como e quando o espaço de memória é reservado.

## Quanto à Representação dos Dados
* *Representação Sequencial*: Os elementos são armazenados em posições contíguas de memória, geralmente utilizando um vetor (array). A relação lógica entre os elementos é dada pela própria ordenação física dos índices. O acesso é direto e a localidade de memória é alta.

* *Representação Encadeada*: Os elementos podem estar em posições não contíguas da memória. Cada elemento (nó) armazena, além do seu valor, uma referência explícita (vínculo) que indica onde encontrar o próximo elemento. Essa referência pode ser um ponteiro (endereço de memória) ou um índice (em um vetor estático).

## Quanto à Alocação de Memória
* *Alocação Estática*: O tamanho máximo da estrutura é definido em tempo de compilação, permanecendo fixo durante toda a execução do programa. A memória é reservada no momento da declaração da estrutura.

* *Alocação Dinâmica*: A memória é reservada (e pode ser liberada) em tempo de execução, conforme a necessidade do programa. Isso permite que a estrutura cresça e diminua dinamicamente.

## Combinações Possíveis
Ao cruzar os dois critérios, obtemos quatro abordagens teóricas para implementar um TAD:

|Representação	| Alocação	|	Descrição da Abordagem|
| --- | --- | --- |
|Sequencial	|Estática|		Vetor estático |
|Sequencial	|Dinâmica|		Vetor dinâmico |
|Encadeada |	Estática|		Nós armazenados em um vetor, com encadeamento por índices.  |
|Encadeada |	Dinâmica|	Nós alocados individualmente com malloc, ligados por ponteiros. |



## Combinações Viáveis para Filas

Diferente da pilha, a fila possui operações em duas extremidades:

-   inserção no fim
-   remoção no início

Isso muda completamente o impacto das implementações.

------------------------------------------------------------------------

### Sequencial Estática

Implementação com vetor de tamanho fixo.

Problema clássico:\
Se usar um vetor simples, ocorre desperdício de espaço após remoções.

Exemplo problemático:
```text
    Índice: 0  1  2  3  4
    Valor : -  - 30 40  50
                 ↑       ↑
               inicio   fim
```
Mesmo havendo espaço livre no início, não é possível reutilizar sem
deslocamento.

------------------------------------------------------------------------

### Solução: Fila Circular

Para evitar deslocamentos O(n), usa-se o conceito de circularidade:

    Índice: 0   1  2  3   4
    Valor : 50  - 30  40  50
            ↑      ↑       
           fim    inicio   

O vetor é tratado como se fosse circular.

Estrutura típica:

``` c
struct fila {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
};
```

------------------------------------------------------------------------

### Sequencial Dinâmica

Semelhante à anterior, porém o vetor pode crescer com realloc.

Mantém: - eficiência O(1) - uso de fila circular

Vantagem: - remove limitação de tamanho fixo

Estrutura típica em C:

``` c
typedef struct {
    int *dados;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
} Fila;
```

------------------------------------------------------------------------

### Encadeada Dinâmica

Implementação natural para filas.

Cada elemento é um nó com: - valor - ponteiro para o próximo

A fila mantém dois ponteiros: - inicio (remoção) - fim (inserção)

Estrutura do nó:

``` c
typedef struct no {
    int valor;
    struct no *prox;
} No;
```

Representação:
```text
inicio                                  fim
   ↓                                     ↓
[10 | * ] → [20 | * ] → [30 | * ] → \[40 | NULL]
```
Estrutura da fila:

``` c
typedef struct {
    No *inicio;
    No *fim;
} Fila;
```

------------------------------------------------------------------------

### Encadeada Estática

Implementação onde os nós ficam em um vetor e são ligados por índices.

Embora possível, é pouco utilizada na prática, pois:

-   adiciona complexidade
-   não traz vantagem significativa
-   perde a simplicidade da versão dinâmica

------------------------------------------------------------------------

## Comparação Geral

  Implementação         Vantagens             Desvantagens
  --------------------- --------------------- -----------------------
  Sequencial Estática   Simples, rápida       Overflow, desperdício
  Sequencial Dinâmica   Flexível, eficiente   Realloc necessário
  Encadeada Dinâmica    Crescimento natural   Overhead de ponteiros
  Encadeada Estática    Controle de memória   Complexa

------------------------------------------------------------------------

## Observação Didática Importante

Fila sequencial eficiente = fila circular

Sem circularidade: - remoção pode ser O(n)

