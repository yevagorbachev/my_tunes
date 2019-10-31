#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "songlist.h"
#include "album.h"

int main() {
    srand(time(NULL));
    // printf("Populating list...\n");
    struct song_node * slist = insert_node_front(NULL, "Farewell of Slavianka", "The Red Army Choir");
    slist = insert_node_lexor(slist, "Army of the People", "The Red Army Choir");
    slist = insert_node_lexor(slist, "Combat Reconniassance", "Vladimir Vysotskiy");
    slist = insert_node_lexor(slist, "Alexandrov's Song", "The Red Army Choir");
    slist = insert_node_lexor(slist, "Under Way!", "The Erich-Weinert Ensemble");
    
    slist = list_remove_song(slist, "Under Way!", "The Erich-Weinert Ensemble");
    printf("First song by The Erich-Weinert Ensemble:\n");
    print_node(list_search_artist(slist, "The Erich-Weinert Ensemble"));

    print_list(slist);
    printf("\n\n");
    
    remove_song(slist, "Under Way!", "Erich-Weinert Ensemble");
    print_list(slist);
    printf("\n\n");
    
    remove_song(slist, "Aleksandrov's Song", "The Red Army Choir");
    print_list(slist);
    printf("\n\n");
    free_list(slist);
    
}