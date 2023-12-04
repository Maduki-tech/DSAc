#include <stdio.h>
#include <stdlib.h>
typedef struct HashTable HashTable;

struct HashTable {
    int key;
    int value;
};

HashTable *createHashTable(int size) {
    HashTable *hashTable = malloc(sizeof(HashTable) * size);
    return hashTable;
}

void put(HashTable **hashTable, int key, int value) {
    HashTable *internHashTable = *hashTable;
    internHashTable[key].key = key;
    internHashTable[key].value = value;
}

int get(HashTable **hashTable, int key) {
    HashTable *internHashTable = *hashTable;
    return internHashTable[key].value;
}


int main(int argc, char *argv[]) {

    HashTable *hashTable = createHashTable(10);

    put(&hashTable, 1, 8);
    put(&hashTable, 2, 2);
    put(&hashTable, 3, 3);

    printf("%d\n", get(&hashTable, 1));
    printf("%d\n", get(&hashTable, 2));


    return 0;
}
