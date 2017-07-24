#include <stdio.h>
#include <string.h>
#include <time.h>

#include "hashkeygenerator.h"

int main() {

    char *key_one = generateHashKey();
    puts(key_one);

    unsigned int retTime = time(0) + 10;
    while (time(0) < retTime);


    char *key_two = generateHashKey();
    puts(key_two);

    if(strcmp(key_one, key_two) == 0) {
        puts("Two Identical Keys are generated!");
        return 1;
    }

    return 0;
}
