#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "songlist.h"

// BASE FUNCTIONALITY

struct song_node * init(char * name, char * artist) {
    struct song_node * egg = malloc(sizeof(struct song_node *));
    egg->next = NULL;
    egg->name = malloc(strlen(name));
    strcpy(egg->name, name);
    egg->artist = malloc(strlen(artist));
    strcpy(egg->artist, artist);
}

struct song_node * insert_node_front(struct song_node * head, char * name, char * artist) {
    struct song_node * egg = init(name, artist);
    egg->next = head;
    return egg;
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
    if (target != NULL) {
        printf("\t%s by %s\n", target->name, target->artist);
    } else {
        printf("Empty song node\n");
    }
}

struct song_node * free_node(struct song_node * target) {
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
    while ((next != NULL) && (i-- > 1)) {
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
    struct song_node * new_node = init(name, artist);

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

struct song_node * search_song(struct song_node * head, char * name, char* artist) {
    struct song_node * box = init(name, artist);

    while ((head != NULL) && (songcmp(box, head) != 0)) {
        head = head->next;
    }
    free_node(box);
    return head;
}

struct song_node * search_artist(struct song_node * head, char* artist) {
    while ((head != NULL) && (strcmp(head->artist, artist) != 0)) {
        head = head->next;
    }
    return head;
}