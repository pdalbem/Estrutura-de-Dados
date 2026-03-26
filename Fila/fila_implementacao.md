# Classificação das Implementações

Ao implementar concretamente um Tipo Abstrato de Dados (TAD), podemos
classificar a implementação segundo dois critérios independentes:

-   Forma de *representação dos dados na memória*: como os elementos se
    relacionam logicamente.

-   Forma de *alocação da memória*: como e quando o espaço de memória é
    reservado.

------------------------------------------------------------------------

## Quanto à Representação dos Dados

-   *Representação Sequencial*: Os elementos são armazenados em posições
    contíguas de memória, geralmente utilizando um vetor (array). A
    relação lógica entre os elementos é dada pela própria ordenação
    física dos índices. O acesso é direto e a localidade de memória é
    alta.

-   *Representação Encadeada*: Os elementos podem estar em posições não
    contíguas da memória. Cada elemento (nó) armazena, além do seu
    valor, uma referência explícita (vínculo) que indica onde encontrar
    o próximo elemento.

------------------------------------------------------------------------

## Quanto à Alocação de Memória

-   *Alocação Estática*: O tamanho máximo da estrutura é definido em
    tempo de compilação, permanecendo fixo durante toda a execução do
    programa.

-   *Alocação Dinâmica*: A memória é reservada (e pode ser liberada) em
    tempo de execução, permitindo crescimento e redução da estrutura.

------------------------------------------------------------------------

## Combinações Possíveis

  -----------------------------------------------------------------------
  Representação           Alocação                Descrição da Abordagem
  ----------------------- ----------------------- -----------------------
  Sequencial              Estática                Vetor estático

  Sequencial              Dinâmica                Vetor dinâmico

  Encadeada               Estática                Nós armazenados em
                                                  vetor, com encadeamento
                                                  por índices

  Encadeada               Dinâmica                Nós alocados com
                                                  malloc, ligados por
                                                  ponteiros
  -----------------------------------------------------------------------

------------------------------------------------------------------------

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

Índice: 0 1 2 3 4\
Valor : - - 30 40 50\
↑ ↑\
início fim

Mesmo havendo espaço livre no início, não é possível reutilizar sem
deslocamento.

------------------------------------------------------------------------

### Solução: Fila Circular

Para evitar deslocamentos O(n), usa-se o conceito de circularidade:

Índice: 0 1 2 3 4\
Valor : 50 - 30 40 -\
↑ ↑\
fim início

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

inicio fim\
↓ ↓\
\[10 \| \* \] → \[20 \| \* \] → \[30 \| \* \] → \[40 \| NULL\]

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

------------------------------------------------------------------------

## Resumo Conceitual

-   Pilha → uma extremidade
-   Fila → duas extremidades

Isso exige estratégias diferentes de implementação.
