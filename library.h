#include "songlist.h"
struct library {
    struct song_node * table[27];
};

struct library * init();

void print_library(struct library * lib);
void lib_print_artist(struct library * lib, char * artist);
void lib_print_letter(struct library * lib, char letter);
void lib_print_Nrandom(struct library * lib, int n);

struct library * free_lib(struct library * lib);
void lib_remove_song(struct library * lib, char * name, char * artist);

void lib_insert_song(struct library * lib, char * name, char * artist);
struct song_node * lib_search_song(struct library * lib, char * name, char * artist);
struct song_node * lib_search_artist(struct library * lib, char * artist);
