#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "library.h"

char * LIST[14][2] = {
    {"418","http"},
    {"india","\'"},
    {"mike","alpha"},
    {"tango","echo"},
    {"alpha","papa"},
    {"!"," "},
    {"718","http"},
    {"india","alpha"},
    {"mike","november"},
    {"oscar","tango"},
    {"alpha","tango"},
    {"echo","alpha"},
    {"papa","oscar"},
    {"tango","."},
};

int main() {
    srand(time(NULL));
    //POPULATION####################################################
    struct library * lib = init();
    printf("\nPopulating library...\n");
    for(int i = 0; i < 14; i++) {
        lib_insert_song(lib, LIST[i][0], LIST[i][1]);
    }

    //PRINTING######################################################
    printf("Printing library:\n");
    print_library(lib);

    char * test_artist_1 = "tango";
    printf("\nPrinting every song by artist: %s\n", test_artist_1);
    lib_print_artist(lib, test_artist_1);

    char * test_artist_2 = "lima"; // nonexistence case test
    printf("Printing every song by artist: %s\n", test_artist_2);
    lib_print_artist(lib, test_artist_2);

    char test_letter_1 = 'a';
    printf("\nPrinting every song under artist letter: %c\n", test_letter_1);
    lib_print_letter(lib, test_letter_1);

    char test_letter_2 = 'j'; // nonexistence case test
    printf("Printing every song under artist letter: %c\n", test_letter_2);
    lib_print_letter(lib, test_letter_2);

    int nrand_1 = 10;
    printf("\nPrinting a psuedo-random sequence of %d songs:\n", nrand_1);
    lib_print_Nrandom(lib, nrand_1);
    
    int nrand_2 = 0; // nonexistence case test
    printf("\nPrinting a psuedo-random sequence of %d songs:\n", nrand_2);
    lib_print_Nrandom(lib, nrand_2);

    //REMOVAL#######################################################
    char * testrm_name_1 = "echo";
    char * testrm_artist_1 = "alpha";
    printf("\nRemoving \"%s\" by %s from library...\n", testrm_name_1, testrm_artist_1);
    lib_remove_song(lib, testrm_name_1, testrm_artist_1);

    char * testrm_name_2 = "lima"; // nonexistance case test
    char * testrm_artist_2 = "whiskey";
    printf("Removing \"%s\" by %s from library...\n", testrm_name_2, testrm_artist_2);
    lib_remove_song(lib, testrm_name_2, testrm_artist_2);

    print_library(lib);
    //SEARCHING####################################################
    char * testsrch_name = "oscar";
    char * testsrch_artist = "tango";
    printf("\nSearching for \"%s\" by %s\n", testsrch_name, testsrch_artist);
    struct song_node * loc = lib_search_song(lib, testsrch_name, testsrch_artist);
    printf("Found song at %p:\n", loc);
    print_node(loc);
    printf("\nSearching for first song by artist %s\n", testsrch_artist);
    print_node(lib_search_artist(lib, testsrch_artist));


    printf("\nFreeing library...\n");
    lib = free_library(lib);
    printf("Printing empty library:\n");
    print_library(lib);
}