#include<stdlib.h>
#include<string.h>
#include "songlist.h"
#include "album.h"


struct library * init() {
    struct library * lib = calloc(sizeof(struct library), 1);
    return lib;
}

void album_rm(struct library * lib) {
    free(lib);
}

void album_deeprm(struct library * lib) {
    for (int i = 0; i < 27; i++) {
        free_list((lib->table)[i]);
    }
    free(lib);
}