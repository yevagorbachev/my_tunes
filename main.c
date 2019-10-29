#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "songlist.h"
#include "album.h"

int main() {
    printf("%d\n", strcmp("Alexandrov", "Farewell"));
    /*
    printf("Populating list...\n");
    struct song_node * slist = insert_node_front(NULL, "Farewell of Slavianka", "Red Army Choir");
    slist = insert_node_lexor(slist, "Army of the People", "Red Army Choir");
    slist = insert_node_lexor(slist, "Combat Reconniassance", "Vladimir Vysotskiy");
    slist = insert_node_lexor(slist, "Alexandrov's Song", "Red Army Choir");
    slist = insert_node_lexor(slist, "Under Way!", "Erich-Weinert Ensemble");
    printf("Printing fully populated list:\n");
    print_list(slist);

    printf("\n\n");
    
    printf("Partially depopulating list...\n");
    slist = remove_node_index(slist, 2);
    printf("\nList status:\n");
    print_list(slist);
    slist = remove_node_index(slist, 3);
    printf("\nList status:\n");
    print_list(slist);
    slist = remove_node_index(slist, 0);
    printf("\nPrinting partially depopulated list:\n");
    print_list(slist);

    printf("\n\n");
    
    printf("Fully depopulating list...\n");
    slist = free_list(slist);
    printf("Printing empty list:\n");
    print_list(slist);
    /**/
}