#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "songlist.h"

struct song_node * insert_node_front(struct song_node * head, char * name, char * artist) {
    struct song_node * carrier = malloc(sizeof(struct song_node *));
    carrier->next = head;
    
    carrier->name = calloc(strlen(name), sizeof(char));
    strcpy(carrier->name, name);
    carrier->artist = calloc(strlen(artist), sizeof(char));
    strcpy(carrier->artist, artist);
    

    return carrier;
}

void print_list(struct song_node * head) {
    int s = 1;
    while (head != NULL) {
        printf("Song #%d:\n", s++);
        print_node(head);
        head = head->next;
    }
}

void print_node(struct song_node * target) {
    printf("\tSong name: %s\n\tArtist name: %s\n", target->name, target->artist);
}

struct song_node * free_node(struct song_node * target) {
    printf("Removing song at %p:\n", target);
    print_node(target);
    free(target->name);
    free(target->artist);
    free(target);
    return NULL;
}

struct song_node * free_list(struct song_node * head) {
    struct song_node * next = head;
    while (next != NULL) {
        next = head->next;
        free_node(head);
        head = next;
    }
    return NULL;
}

struct song_node * remove_node_index(struct song_node * head, int i) {
    struct song_node * next = head->next;
    struct song_node * prev = head;
    if (i == 0) {
        free_node(head);
        return next;
    }
    for (int h = 1; h < i; h++) {
        if (next == NULL) {
            printf("Out of bounds!\n");
            return NULL;
        }
        prev = next;
        next = next->next;
    }
    prev->next = next->next;
    free_node(next);
    return head;
}