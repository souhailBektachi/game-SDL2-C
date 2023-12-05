#pragma once
#include "csts.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct{
    int key;
    char type;
}mapwall;

typedef struct KeyValue {
    mapwall map;
    
    struct KeyValue* next;
} KeyValue;
typedef struct HashMap {
    KeyValue* table[HASH_SIZE];
} HashMap;
unsigned int hash(int key);
KeyValue* createPair(int key, char type) ;
void insert(HashMap* map, int key, char type);
char getType(const HashMap* map, int key);
void cleanup(HashMap* map);
