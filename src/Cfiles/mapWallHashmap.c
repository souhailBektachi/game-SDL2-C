#include "hashmap.h"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>







unsigned int hash(int key) {
    return key % HASH_SIZE;
}

KeyValue* createPair(int key, char type) {
    KeyValue* newPair = (KeyValue*)malloc(sizeof(KeyValue));
    newPair->map.key = key;
    newPair->map.type = type;
    newPair->next = NULL;
    return newPair;
}

void insert(HashMap* map, int key, char type) {
    unsigned int index = hash(key);

    KeyValue* newPair = createPair(key, type);

    if (map->table[index] == NULL) {
        map->table[index] = newPair;
    } else {
        KeyValue* current = map->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPair;
    }
}

char getType(const HashMap* map, int key) {
    
    unsigned int index = hash(key);

    KeyValue* current = map->table[index];

    while (current != NULL) {
        if (current->map.key == key) {
            return current->map.type;
        }
        current = current->next;
    }

    return '\0';
}

void cleanup(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; ++i) {
        KeyValue* current = map->table[i];
        while (current != NULL) {
            KeyValue* temp = current;
            current = current->next;
            free(temp);
        }
    }
}


