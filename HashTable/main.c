#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main() {
    HashTable* myHashTable = createHashTable();

    insert(myHashTable, "maça", "fruta");
    insert(myHashTable, "banana", "fruta amarela");
    insert(myHashTable, "carro", "veículo");
    insert(myHashTable, "cachorro", "animal de estimação");
    insert(myHashTable, "mesa", "móvel");
    insert(myHashTable, "teste", "exemplo");
    insert(myHashTable, "seta", "direção");

    printHashTable(myHashTable);

    char* result = search(myHashTable, "banana");
    if (result) printf("Valor de 'banana': %s\n", result);
    else printf("'banana' não encontrado.\n");

    result = search(myHashTable, "abacaxi");
    if (result) printf("Valor de 'abacaxi': %s\n", result);
    else printf("'abacaxi' não encontrado.\n");

    insert(myHashTable, "maça", "fruta vermelha");
    printHashTable(myHashTable);

    delete(myHashTable, "carro");
    delete(myHashTable, "laranja");

    printHashTable(myHashTable);

    freeHashTable(myHashTable);
    return 0;
}
