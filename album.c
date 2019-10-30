#include<stdlib.h>
#include<string.h>
#include "songlist.h"
#include "album.h"


struct library * init() {
    struct library * lib = calloc(sizeof(struct library), 1);
    return lib;
}