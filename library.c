#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "library.h"

struct library * init(){
    return calloc(sizeof(struct library), 1);
}


void print_library(struct library * lib) {
    for (int i = 0; i < 27; i++) {
        print_list(lib->table[i]);
    }
}

void lib_print_artist(struct library * lib, char * artist){
    for (int i = 0; i < 27; i++) {
        list_print_artist(lib->table[i], artist);
    }
}

void lib_print_letter(struct library * lib, char letter){
    if ('A' <= letter <= 'Z') {
        print_list(lib->table[letter - 'A']);
    } else {
        print_list(lib->table[27]);
    }
}

void lib_print_Nrandom(struct library * lib, int n){
    for (; n > 0; n--) {
        print_node(list_select_random(lib->table[rand() % 27]));
    }
}


struct library * free_lib(struct library * lib){
    for (int i = 0; i < 27; i++) {
        free_list(lib->table[i]);
    }
    free(lib);
    return NULL;
}

void lib_remove_song(struct library * lib, char * name, char * artist){
    if ('A' <= name[0] <= 'Z') {
        list_remove_song(lib->table[name[0] - 'A'], name, artist);
    } else {
        list_remove_song(lib->table[27], name, artist);
    }
}


void lib_insert_song(struct library * lib, char * name, char * artist){
    if ('A' <= name[0] <= 'Z') {
        insert_node_lexor((lib->table)[name[0] - 'A'], name, artist);
    } else {
        insert_node_lexor(lib->table[27], name, artist);
    }
}

/*
struct song_node * lib_search_song(struct library * lib, char * name, char * artist){

}

struct song_node * lib_search_artist(struct library * lib, char * artist){

}
/**/