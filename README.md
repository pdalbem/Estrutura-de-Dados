# Estrutura de Dados
Material da disciplina de Estrutura de Dados (ESDD).


## 🛠️ Guia de Configuração do Ambiente 

Este guia tem como objetivo ajudar você a configurar seu computador para compilar e executar os códigos da disciplina de **Estrutura de Dados**. Siga os passos abaixo de acordo com o seu sistema operacional.


### 1. Instalação do Compilador (GCC)

O compilador é essencial para transformar seu código-fonte em um programa executável.

### **Windows**
A forma mais recomendada é através do **MSYS2**. 

Veja o tutorial completo de instalação [aqui neste link](https://code.visualstudio.com/docs/cpp/config-mingw).

1. Baixe e instale o [MSYS2](https://www.msys2.org/).
2. Abra o terminal do MSYS2 e execute o comando:  
   `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`
3. Adicione o caminho da pasta `bin` (geralmente `C:\msys64\ucrt64\bin`) às **Variáveis de Ambiente (PATH)** do Windows para que o comando `gcc` funcione em qualquer terminal.

### **Linux**
A maioria das distribuições já possui ou facilita muito a instalação:
* **Ubuntu/Debian:** `sudo apt update && sudo apt install build-essential`
* **Fedora:** `sudo dnf groupinstall "Development Tools"`

### **macOS**
Instale as ferramentas de linha de comando do Xcode:
1. Abra o Terminal e digite:
   `xcode-select --install`

---

### 2. Editor de Código Recomendado: VS Code

Utilizaremos o **Visual Studio Code** pela sua versatilidade. Acesse o [site](https://code.visualstudio.com/) para efetuar o download. Após instalá-lo, abra-o e procure na aba de **Extensions (Ctrl+Shift+X)** por:

**C/C++ Extension Pack (Microsoft):** Oferece realce de sintaxe, IntelliSense (autocompletar) e suporte a depuração.


---

### 3. Usando o Terminal

Embora existam botões que facilitam o trabalho, é fundamental saber compilar seus programas via linha de comando. 

### **Comandos Básicos**

Navegue até a pasta dds seus arquivos pelo terminal e utilize:

**Para programas em C:**
```bash
# Compila o código
gcc *.c -o programa

# Executa o programa
./programa
``` 

### Conteúdo

[1. Complexidade de Algoritmos](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/Complexidade%20de%20Algoritmo)

[2. Tipo Abstrato de Dado](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/TAD)

[3. Pilha](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/Pilha)

[4. Fila](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/Fila)

[5. Lista](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/Lista)

[6. Lista Encadeada](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/ListaEncadeada)

[7. Lista Duplamente Encadeada](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/ListaDuplamenteEncadeada)

[8. Árvore Binária de Busca](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/ArvoreBinariaBusca)

[9. Árvore AVL](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/AVL)

[10. Heap](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/Heap)

[11. Grafo](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/Grafo)

[12. Tabela Hash](https://github.com/pdalbem/Estrutura-de-Dados/tree/main/HashTable)
