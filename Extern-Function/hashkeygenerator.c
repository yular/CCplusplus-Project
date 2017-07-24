#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hashkeygenerator.h"

char KEY_CHAR_POOL[62] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char FIX_HASH_KEY_PREFIX[5] = "mysql";

char *hash_key;

extern char * generateHashKey(){
    srand(time(NULL));
    hash_key = (char*) malloc(27);
    strcpy(hash_key, FIX_HASH_KEY_PREFIX);

    int i = 5;
    for(i = 5; i < 27; ++ i) {
        int idx = (int)( rand()%62 );
        hash_key[i] = KEY_CHAR_POOL[idx];
    }
    hash_key[5] = hash_key[9] = hash_key[14] = hash_key[20] = '-';
    return (char *)hash_key;
}
