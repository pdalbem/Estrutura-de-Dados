#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define TABLE_SIZE 10

typedef struct Node {
    char* key;
    char* value;
    struct Node* next;
} Node;

struct hashtable {
    Node* buckets[TABLE_SIZE];
};

static unsigned int hash(const char* key) {
    unsigned int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++) 
        hash_value = (hash_value + key[i]) % TABLE_SIZE;
    
    return hash_value;
}

HashTable* createHashTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    if (ht == NULL) 
        exit(EXIT_FAILURE);
    
    for (int i = 0; i < TABLE_SIZE; i++) 
        ht->buckets[i] = NULL;
    
    return ht;
}

void insert(HashTable* ht, const char* key, const char* value) {
    unsigned int index = hash(key);
    Node* current = ht->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            free(current->value);
            current->value = strdup(value);
            printf("Chave '%s' atualizada para '%s'.\n", key, value);
            return;
        }
        current = current->next;
    }

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) 
           exit(EXIT_FAILURE);
    
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;
    printf("Chave '%s' inserida com valor '%s' no índice %d.\n", key, value, index);
}

char* search(HashTable* ht, const char* key) {
    unsigned int index = hash(key);
    Node* current = ht->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) 
            return current->value;
        
        current = current->next;
    }
    return NULL;
}

void delete(HashTable* ht, const char* key) {
    unsigned int index = hash(key);
    Node* current = ht->buckets[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) 
                ht->buckets[index] = current->next;
             else 
                prev->next = current->next;
            
            free(current->key);
            free(current->value);
            free(current);
            printf("Chave '%s' removida.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Chave '%s' não encontrada para remoção.\n", key);
}

void freeHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht);
    printf("Tabela hash liberada.\n");
}

void printHashTable(HashTable* ht) {
    printf("\n--- Conteúdo da Tabela Hash ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* current = ht->buckets[i];
        if (current == NULL) 
            printf("Vazio\n");
        else {
            while (current != NULL) {
                printf("('%s': '%s') -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("-------------------------------\n");
}
