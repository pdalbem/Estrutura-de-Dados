typedef struct hashtable HashTable;

HashTable* createHashTable(); // Aloca e inicializa
void insert(HashTable* ht, const char* key, const char* value);
char* search(HashTable* ht, const char* key);
void delete(HashTable* ht, const char* key);
void freeHashTable(HashTable* ht);
void printHashTable(HashTable* ht);