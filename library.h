#include "songlist.h"
struct library {
    struct song_node * table[27];
};

struct library * init(); // yes

void print_library(struct library * lib); // yes
void lib_print_artist(struct library * lib, char * artist); // yes
void lib_print_letter(struct library * lib, char letter); // yes
void lib_print_Nrandom(struct library * lib, int n); // yes

struct library * free_library(struct library * lib); // yes
void lib_remove_song(struct library * lib, char * name, char * artist); // yes

void lib_insert_song(struct library * lib, char * name, char * artist); // yes
struct song_node * lib_search_song(struct library * lib, char * name, char * artist);
struct song_node * lib_search_artist(struct library * lib, char * artist);
