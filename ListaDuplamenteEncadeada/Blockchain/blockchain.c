#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <time.h>
#include "blockchain.h"

#define HASH_SIZE (SHA256_DIGEST_LENGTH * 2 + 1)

// Estrutura do bloco
typedef struct Block {
    int id;
    char hash[HASH_SIZE];
    char prev_hash[HASH_SIZE];
    char data[100];
    time_t timestamp;  
    struct Block *prev;
    struct Block *next;
} Block;

// lista
struct blockchain {
    Block *inicio;
    Block *fim;
    int count;
} ;

// Função para gerar um hash SHA-256
void generate_hash(char *output, int id, const char *prev_hash, const char *data) {
    char input[256]; // Buffer para armazenar os dados a serem hashados
    unsigned char hash[SHA256_DIGEST_LENGTH]; // Buffer para o hash SHA-256

    // Criando a string de entrada que será transformada em hash
    snprintf(input, sizeof(input), "%d-%s-%s", id, prev_hash, data);

    // Gerando o hash SHA-256
    SHA256((unsigned char*)input, strlen(input), hash);

    // Convertendo o hash para string hexadecimal
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    output[SHA256_DIGEST_LENGTH * 2] = '\0'; // Adicionando o terminador de string
}

// Função para criar um bloco
Block* create_block(int id, const char *prev_hash, const char *data) {
    Block *new_block = (Block*)malloc(sizeof(Block));
    if (!new_block) 
       exit(1);
    
    new_block->id = id;
    strcpy(new_block->prev_hash, prev_hash);
    strcpy(new_block->data, data);
    new_block->timestamp = time(NULL);  // Define o timestamp para o momento da criação
    generate_hash(new_block->hash, id, prev_hash, data);
    new_block->prev = NULL;
    new_block->next = NULL;
    return new_block;
}

// Função para inicializar a blockchain
Blockchain* criarBlockchain() {
    Blockchain *bc = (Blockchain*)malloc(sizeof(Blockchain));
    bc->inicio = NULL;
    bc->fim = NULL;
    bc->count = 0;
    return bc;
}

// Função para adicionar um bloco
void adicionarBloco(Blockchain *bc, const char *data) {
    const char *prev_hash = (bc->fim) ? bc->fim->hash : "GENESIS";
    Block *new_block = create_block(bc->count + 1, prev_hash, data);
    
    if (!bc->inicio) {
        bc->inicio = bc->fim = new_block;
    } else {
        bc->fim->next = new_block;
        new_block->prev = bc->fim;
        bc->fim = new_block;
    }
    bc->count++;
}

// Função para remover o último bloco
void removerBloco(Blockchain *bc) {
    if (!bc->fim) 
        return;
        
    Block *to_delete = bc->fim;
    bc->fim = to_delete->prev;
    if (bc->fim) {
        bc->fim->next = NULL;
    } else {
        bc->inicio = NULL;
    }
    free(to_delete);
    bc->count--;
}

// Função para exibir a blockchain
void mostrarBlockchain(Blockchain *bc) {
    Block *current = bc->inicio;
    while (current) {
        // Exibe os campos de cada bloco, incluindo o timestamp
        printf("ID: %d\nData: %s\nHash: %s\nPrev Hash: %s\nTimestamp: %s------------\n",
               current->id, current->data, current->hash, current->prev_hash, ctime(&current->timestamp));
        current = current->next;
    }
}

// Função para liberar memória
void liberarBlockchain(Blockchain *bc) {
    Block *current = bc->inicio;
    while (current) {
        Block *next = current->next;
        free(current);
        current = next;
    }
    free(bc);
}
