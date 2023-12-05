#include "csv.h"

FILE* checkCsvFile(const char* pathname){
    FILE* file =fopen(pathname,"r");
    if(file == NULL){
                fprintf(stderr, "Error opening file\n");
            
    }
    return file;
}
void parseCsv(const char* pathname,int mapkeys[]){
        FILE* file=checkCsvFile(pathname);
    int i=0;

    char line[MAX_LINE_SIZE];
        while (fgets(line, sizeof(line), file) != NULL) {
        char* tile = strtok(line, ",");
        
        
        while (tile != NULL) {
            
            int value = atoi(tile);
            mapkeys[i]=value;
            i++;

            
            

            

            tile = strtok(NULL, ",");
        }

       
    }



}

void Wallscsv(const char* pathname,Map* map){
    FILE* file=checkCsvFile(pathname);
    int typeindex=0;
    int i=0;
    
    char line[MAX_LINE_SIZE];
            while (fgets(line, sizeof(line), file) != NULL){
            char* tile = strtok(line, ",");
            while (tile != NULL) {
            int value = atoi(tile);
                if(value !=-1){
            insert(&map->walls,value,WALLS_TYPES[typeindex]);
            i++;}
            tile = strtok(NULL, ",");
            }
            typeindex++;


    
}
    map->wallsSize=i;
}



