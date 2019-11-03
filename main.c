#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "library.h"

char * LIST[14][2] = {
    {"418","HTTP"},
    {"India","\'"},
    {"Mike","Alpha"},
    {"Tango","Echo"},
    {"Alpha","Papa"},
    {"!"," "},
    {"718","HTTP"},
    {"India","Alpha"},
    {"Mike","November"},
    {"Oscar","Tango"},
    {"Alpha","Tango"},
    {"Echo","Alpha"},
    {"Papa","Oscar"},
    {"Tango","."},
};

int main() {
    srand(time(NULL));
    struct library * lib = init();
    for(int i = 0; i < 14; i++) {
        lib_insert_song(lib, LIST[i][0], LIST[i][1]);
    }
    // int i = rand() % 14;
    // printf("Removing \"%s\" by %s\n", LIST[i][0], LIST[i][1]);
    // lib_remove_song(lib, LIST[i][0], LIST[i][1]);
    // print_library(lib);
    lib_remove_song(lib, " ", "NOPE");
    print_library(lib);
    printf("Freeing library...\n");
    lib = free_library(lib);
    /**/
}