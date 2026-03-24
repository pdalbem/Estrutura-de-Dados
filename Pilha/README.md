# TAD Pilha (Stack)

## Introdução

A **pilha** é uma **estrutura de dados linear** em que os elementos são
organizados de forma sequencial e as operações de inserção e remoção
ocorrem **em apenas uma extremidade da estrutura**, chamada **topo**.

Essa organização segue o princípio:

LIFO = Last In, First Out

Ou seja:

> **o último elemento inserido é o primeiro a ser removido**.

Um exemplo cotidiano é uma pilha de pratos: o último prato colocado no
topo será o primeiro a ser retirado.

Representação conceitual:

    topo
     ↓
    [40]
    [30]
    [20]
    [10]

------------------------------------------------------------------------

# Estrutura Linear

A pilha pertence à classe das **estruturas lineares**.

Uma estrutura é considerada **linear** quando seus elementos formam uma
sequência ordenada:

(a1, a2, a3, ..., an)

onde cada elemento possui:

-   um **único predecessor** (exceto o primeiro elemento)
-   um **único sucessor** (exceto último elemento)


No caso da pilha, as operações são restritas ao **final da sequência**,
denominado **topo**.

------------------------------------------------------------------------

# Definição Formal do TAD Pilha

Um **Tipo Abstrato de Dados (TAD)** define **um conjunto de valores e as
operações permitidas sobre esses valores**, sem especificar sua
implementação.

Formalmente:

TAD = (D, O)

onde:

-   D é o **domínio de valores**
-   O é o **conjunto de operações**

------------------------------------------------------------------------

## Domínio da Pilha

O domínio da pilha pode ser definido como o conjunto de **sequências
finitas de elementos** de um tipo E:

D = { (a1, a2, ..., an) \| ai ∈ E, n ≥ 0 }

onde:

-   n é o tamanho da pilha
-   an representa o **topo da pilha**

------------------------------------------------------------------------

## Operações do TAD Pilha

As principais operações são:

### criar()

Cria uma pilha vazia.

    criar() → Pilha

------------------------------------------------------------------------

### push(x)

Insere um elemento no topo.

    push : Pilha × E → Pilha

Se:

    P = (a1, a2, ..., an)

então:

    push(P, x) = (a1, a2, ..., an, x)

------------------------------------------------------------------------

### pop()

Remove o elemento do topo.

    pop : Pilha → Pilha

Se:

    P = (a1, a2, ..., a(n-1), an)

então:

    pop(P) = (a1, a2, ..., a(n-1))

com n \> 0.

------------------------------------------------------------------------

### top()

Retorna o elemento do topo sem removê-lo.

    top : Pilha → E

    top(P) = an

------------------------------------------------------------------------


# Representação Conceitual

Uma pilha pode ser representada como:

    P = (a1, a2, a3, ..., an)

em que:

-   a1 é o **fundo da pilha**
-   an é o **topo da pilha**

Exemplo:

    topo
     ↓
    [50]
    [40]
    [30]
    [20]
    [10]

------------------------------------------------------------------------

# Classificação das Implementações

Ao implementar concretamente um Tipo Abstrato de Dados (TAD), podemos classificar a implementação segundo dois critérios independentes:

* Forma de r*epresentação dos dados na memória*: como os elementos se relacionam logicamente.

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

## Combinações Viáveis para Pilhas
No caso específico da pilha, a natureza de suas operações — que ocorrem exclusivamente em uma extremidade (o topo) — torna algumas implementações mais naturais e eficientes que outras.

* *Sequencial Estática*: A implementação clássica e mais simples. Um vetor de tamanho fixo e um índice topo. Muito eficiente, mas sujeita a overflow.

Exemplo:

    Índice: 0  1  2  3
    Valor : 10 20 30 40
                      ↑
                     topo

    
Estrutura típica em C:

``` c
struct pilha {
    int dados[MAX];
    int topo;
};
```

* *Sequencial Dinâmica*: Similar à anterior, mas o vetor pode ser realocado quando atinge sua capacidade, eliminando o risco de overflow (dentro dos limites da memória disponível). Mantém a eficiência do acesso direto.


Exemplo:

    Índice: 0  1  2  3
    Valor : 10 20 30 40
                      ↑
                     topo

Estrutura típica em C:

``` c
typedef struct{
    int *dados;
    int topo;
    int capacidade;
}Pilha;

Pilha* criarPilha(int capacidade) {
    Pilha *p = malloc(sizeof(Pilha));
    p->capacidade = capacidade;
    p->topo = -1;
    p->dados = malloc(capacidade * sizeof(int));
    return p;
}
```

* *Encadeada Dinâmica*: Implementação flexível onde cada elemento é um nó alocado dinamicamente. A pilha cresce enquanto houver memória. É a escolha natural quando não se conhece o tamanho máximo ou quando a memória é fragmentada.

Cada nó contém:

-   o valor armazenado
-   um ponteiro para o próximo nó

Estrutura do nó:

``` c
typedef struct no {
    int valor;
    struct no *prox;
} No;
```

Representação:

    topo
     ↓
    [40 | * ] → [30 | * ] → [20 | * ] → [10 | NULL]


**OBS:** Embora tecnicamente possível, a combinação Encadeada Estática não faz sentido prático para pilhas. Para uma pilha, onde as operações são apenas no topo, a complexidade extra do encadeamento não traz nenhuma vantagem em relação à implementação sequencial estática, que é mais simples e igualmente eficiente.