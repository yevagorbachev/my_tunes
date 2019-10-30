#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "songlist.h"
#include "album.h"

int main() {
    srand(time(NULL));
    // printf("Populating list...\n");
    struct song_node * slist = insert_node_front(NULL, "Farewell of Slavianka", "Red Army Choir");
    slist = insert_node_lexor(slist, "Army of the People", "Red Army Choir");
    slist = insert_node_lexor(slist, "Combat Reconniassance", "Vladimir Vysotskiy");
    slist = insert_node_lexor(slist, "Alexandrov's Song", "Red Army Choir");
    slist = insert_node_lexor(slist, "Under Way!", "Erich-Weinert Ensemble");
    print_list(slist);
    
    printf("\n\n");

    slist = remove_node_index(slist, 4);
    slist = remove_node_index(slist, 0);
    slist = remove_node_index(slist, 1);

    print_list(slist);
    
    search_song(slist, "Army of the People", "Red Army Choir");


    printf("\n\n");

    printf("Fully depopulating list...\n");
    slist = free_list(slist);
    printf("Printing empty list:\n");
    print_list(slist);
}