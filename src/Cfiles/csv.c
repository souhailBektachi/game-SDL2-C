#include "csv.h"
void parseCsv(const char* pathname,int mapkeys[]){
        FILE* file = fopen(pathname, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        
    }
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



