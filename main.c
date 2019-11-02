#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "library.h"

char * LIST[6][2] = {
    {"Farewell of Slavianka","The Red Army Choir"},
    {"Under Way!","The Erich-Weinert Ensemble"},
    {"On the Road","The Red Army Choir"},
    {"Combat Reconnissaince","Vladimir Vysotskiy"},
    {"Aleksandrov's Song","The Red Army Choir"},
    {"Partisan's Song","The Red Army Choir"},
};

int main() {
    struct library * lib = init();
    printf("Printing empty library:\n");
    print_library(lib);

    printf("Populating library...\n");
    for(int i = 0; i < 6; i++) {
        printf("Inserting \"%s\" by %s\n", LIST[i][0], LIST[i][1]);
        lib_insert_song(lib, LIST[i][0], LIST[i][1]);
    }
    printf("Printing full library:\n");
    print_library(lib);
}