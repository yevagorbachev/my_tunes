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
    struct library * lib = init();
    printf("Printing empty library:\n");
    print_library(lib);

    printf("Populating library...\n");
    for(int i = 0; i < 14; i++) {
        lib_insert_song(lib, LIST[i][0], LIST[i][1]);
    }
    printf("Printing full library:\n");
    print_library(lib);
    printf("Freeing library...\n");
    lib = free_library(lib);
    printf("Printing empty library:\n");
    print_library(lib);
    printf("%d\n", ('A' <= '.') && ('.' <= 'Z'));
    /**/
}