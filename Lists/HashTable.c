#include <stdio.h>
#include <stdlib.h>
typedef struct HashTable HashTable;

struct HashTable {
    long key;
    int value;
};

HashTable *createHashTable(int size) {
    HashTable *hashTable = malloc(sizeof(HashTable) * size);
    return hashTable;
}

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    printf("%lu\n", hash);
    return hash;
}
void put(HashTable **hashTable, char *key, int value) {
    HashTable *internHashTable = *hashTable;
    int index = hash(key);
    internHashTable[index].key = index;
    internHashTable[index].value = value;
}

int get(HashTable **hashTable, int key) {
    HashTable *internHashTable = *hashTable;
    return internHashTable[key].value;
}

int main(int argc, char *argv[]) {

    HashTable *hashTable = createHashTable(10);

    put(&hashTable, "a", 1);
    put(&hashTable, "b", 2);
    put(&hashTable, "c", 3);

    printf("%d\n", get(&hashTable, hash("a")));

    free(hashTable);
    return 0;
}
