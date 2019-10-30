#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "songlist.h"

// BASE FUNCTIONALITY

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
    printf("\t%s by %s\n", target->name, target->artist);
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

// ADDITIONAL FUNCTIONALITY
int songcmp(struct song_node * s1, struct song_node * s2) {
    int cmp_artist = strcmp(s1->artist, s2->artist);
    if (cmp_artist == 0) {
        return strcmp(s1->name, s2->name);
    } 
    return cmp_artist;
}

struct song_node * insert_node_lexor(struct song_node * head, char * name, char * artist) {
    struct song_node * next = head->next;
    struct song_node * prev = head;
    struct song_node * new_node = insert_node_front(NULL, name, artist);

    if (songcmp(new_node, head) < 0) { // special case: beginning of list
        new_node->next = head;
        return new_node;
    }

    while ((next != NULL) && (songcmp(new_node, next) >= 0)) {
        prev = next;
        next = next->next;
    }
    new_node->next = next;
    prev->next = new_node;
    return head;
}

struct song_node * select_random(struct song_node * head) {
    int c = 0;
    for (struct song_node * count = head; count != NULL; count = count->next) {c++;}
    int i = rand() % c;
    for (; i > 0; i--) {
        head = head->next;
    }
    return head;
}