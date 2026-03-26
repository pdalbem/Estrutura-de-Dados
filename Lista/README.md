# TAD Lista (List)

## Introdução

A **lista** é uma **estrutura de dados linear** que permite armazenar uma coleção de elementos de forma sequencial.

Diferentemente da pilha, as operações de inserção e remoção podem ocorrer **em qualquer posição da estrutura**.

A lista pode ser:

- ordenada ou não ordenada
- permitir ou não elementos repetidos

Representação conceitual:

    [10] → [20] → [30] → [40]

------------------------------------------------------------------------

# Estrutura Linear

A lista pertence à classe das **estruturas lineares**.

Uma estrutura é considerada **linear** quando seus elementos formam uma sequência ordenada:

(a1, a2, a3, ..., an)

onde cada elemento possui:

- um **único predecessor** (exceto o primeiro)
- um **único sucessor** (exceto o último)

------------------------------------------------------------------------

# Definição Formal do TAD Lista

Um **Tipo Abstrato de Dados (TAD)** define um conjunto de valores e operações.

Formalmente:

TAD = (D, O)

------------------------------------------------------------------------

## Domínio da Lista

O domínio da lista é o conjunto de **sequências finitas de elementos**:

D = { (a1, a2, ..., an) | ai ∈ E, n ≥ 0 }

------------------------------------------------------------------------

## Operações do TAD Lista

### criar()

Cria uma lista vazia.

    criar() → Lista

------------------------------------------------------------------------

### inserir(pos, x)

Insere um elemento em uma posição específica.

    inserir : Lista × int × E → Lista

------------------------------------------------------------------------

### remover(pos)

Remove o elemento de uma posição.

    remover : Lista × int → Lista

------------------------------------------------------------------------

### acessar(pos)

Retorna o elemento de uma posição.

    acessar : Lista × int → E

------------------------------------------------------------------------

### tamanho()

Retorna a quantidade de elementos.

    tamanho : Lista → int

------------------------------------------------------------------------

# Representação Conceitual

    [10] → [20] → [30] → [40]

------------------------------------------------------------------------

# Classificação das Implementações

## Quanto à Representação

- **Sequencial**: vetor (array)
- **Encadeada**: nós com ponteiros

## Quanto à Alocação

- **Estática**: tamanho fixo
- **Dinâmica**: cresce em tempo de execução

------------------------------------------------------------------------

# Implementações de Lista

## Lista Sequencial Estática

- vetor fixo
- inserção exige deslocamento (shift)

Exemplo:

    Índice: 0  1  2  3
    Valor : 10 20 30 40

Estrutura em C:

```c
typedef struct {
    int dados[100];
    int tamanho;
} Lista;
```

------------------------------------------------------------------------

## Lista Sequencial Dinâmica

- vetor redimensionável

```c
typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Lista;
```

------------------------------------------------------------------------

## Lista Encadeada Dinâmica

Cada elemento é um nó:

```c
typedef struct no {
    int valor;
    struct no *prox;
} No;
```

Representação:

    [10 | *] → [20 | *] → [30 | *] → [40 | NULL]

------------------------------------------------------------------------

# Observações

- Inserção no início é custosa em listas sequenciais
- Inserção é eficiente em listas encadeadas
- A escolha depende do contexto de uso
