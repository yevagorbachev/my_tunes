#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "songlist.h"
#include "album.h"

int main() {
    srand(time(NULL));
    printf("Populating list...\n");
    struct song_node * slist = song_init("Farewell of Slavianka", "The Red Army Choir");
    slist = insert_node_front(slist, "Under Way!", "Erich-Weinert Ensemble");
    slist = insert_node_front(slist, "Aleksandrov's Song", "The Red Army Choir");
    slist = insert_node_front(slist, "Agressive Reconnissaince", "Vladimir Vysotskiy");
    printf("List populated...\n\n");

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