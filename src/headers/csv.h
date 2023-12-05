#pragma once
typedef struct Map Map;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <csts.h>
#include "map.h"

void parseCsv(const char* pathname,int mapkeys[]);
void Wallscsv(const char* pathname,Map* map);
FILE* checkCsvFile(const char* pathname);