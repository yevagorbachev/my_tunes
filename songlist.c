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
    while (head != NULL) {
        print_node(head);
        head = head->next;
    }
}

void print_node(struct song_node * target) {
    if (target != NULL) {
        printf("\t%s by %s\n", target->name, target->artist);
    }
}

void list_print_artist(struct song_node * head, char * artist) {
    if (head != NULL) {
        for (struct song_node * next_by_artist = list_search_artist(head, artist); 
            next_by_artist != NULL; 
            next_by_artist = list_search_artist(head = next_by_artist->next, artist)) {
            print_node(next_by_artist);
        }
    }
}


int songcmp(struct song_node * s1, struct song_node * s2) {
    int cmp_artist = strcmp(s1->artist, s2->artist);
    if (cmp_artist == 0) {
        return strcmp(s1->name, s2->name);
    } 
    return cmp_artist;
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

struct song_node * list_remove_song(struct song_node * head, char * name, char * artist) {
    struct song_node * box = insert_node_front(NULL, name, artist);
    struct song_node * next = head->next;
    struct song_node * prev = head;

    if (songcmp(box, head) == 0) {
        free_node(head);
        return next;
    }

    while (songcmp(box, next) != 0) {
        prev = next;
        next = next->next;
        if (next == NULL) {
            return head;
        }
    }

    prev->next = next->next;
    free_node(next);
    return head;
}


struct song_node * insert_node_lexor(struct song_node * head, char * name, char * artist) {
    if (head == NULL) {
        return insert_node_front(NULL, name, artist);
    }
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

struct song_node * list_select_random(struct song_node * head) {
    int c = 0;
    for (struct song_node * count = head; count != NULL; count = count->next) {c++;}
    int i = rand() % c;
    for (; i > 0; i--) {
        head = head->next;
    }
    return head;
}

struct song_node * list_search_song(struct song_node * head, char * name, char* artist) {
    struct song_node * box = insert_node_front(NULL, name, artist);

    while ((head != NULL) && (songcmp(box, head) != 0)) {
        head = head->next;
    }
    free_node(box);
    return head;
}

struct song_node * list_search_artist(struct song_node * head, char* artist) {
    while ((head != NULL) && (strcmp(head->artist, artist) != 0)) {
        head = head->next;
    }
    return head;
}