#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "library.h"

struct library * init(){
    return calloc(sizeof(struct library), 1);
}


void print_library(struct library * lib) {
    if (lib != NULL) {
        for (int i = 0; i < 27; i++) {
            print_list(lib->table[i]);
        }
    }
}

void lib_print_artist(struct library * lib, char * artist){
    for (int i = 0; i < 27; i++) {
        list_print_artist(lib->table[i], artist);
    }
}

void lib_print_letter(struct library * lib, char letter){
    if (('A' <= letter) && (letter <= 'Z')) {
        print_list(lib->table[letter - 'A']);
    } else {
        print_list(lib->table[26]);
    }
}

void lib_print_Nrandom(struct library * lib, int n){
    int i;
    while (n > 0) {
        i = rand() % 27;
        struct song_node * rlist = lib->table[i];
        if (rlist != NULL) {
            print_node(list_select_random(rlist));
            n--;
        }
    }
    // for (; n > 0; n--) {
    //     print_node(list_select_random(lib->table[rand() % 27]));
    // }
}


struct library * free_library(struct library * lib){
    for (int i = 0; i < 27; i++) {
        free_list(lib->table[i]);
    }
    free(lib);
    return NULL;
}

void lib_remove_song(struct library * lib, char * name, char * artist){
    if (('A' <= artist[0]) && (artist[0] <= 'Z')) {
        struct song_node ** loc = &lib->table[artist[0] - 'A'];
        *loc = list_remove_song(*loc, name, artist);
    } else {
        struct song_node ** loc = &lib->table[26];
        *loc = list_remove_song(*loc, name, artist);
    }
}


void lib_insert_song(struct library * lib, char * name, char * artist){
    if (('A' <= artist[0]) && (artist[0] <= 'Z')) {
        struct song_node ** loc = &lib->table[artist[0] - 'A'];
        printf("inserting \"%s\" by %s under letter %c\n", name, artist, artist[0]);
        *loc = insert_node_lexor(*loc, name, artist);
    } else {
        struct song_node ** loc = &lib->table[26];
        *loc = insert_node_lexor(*loc, name, artist);
    }
}

/*
struct song_node * lib_search_song(struct library * lib, char * name, char * artist){

}

struct song_node * lib_search_artist(struct library * lib, char * artist){

}
/**/