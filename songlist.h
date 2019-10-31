struct song_node {
    char * name;
    char * artist;
    struct song_node * next;
};

struct song_node * insert_node_front(struct song_node * next, char * name, char * artist);

void print_node(struct song_node * target);
void print_list(struct song_node * head);
void list_print_artist(struct song_node * head, char * artist);

struct song_node * free_node(struct song_node * target);
struct song_node * free_list(struct song_node * head);
struct song_node * list_remove_song(struct song_node * head, char * name, char * artist);

struct song_node * insert_node_lexor(struct song_node * head, char * name, char * artist);
struct song_node * list_select_random(struct song_node * head);
struct song_node * list_search_song(struct song_node * head, char * name, char * artist);
struct song_node * list_search_artist(struct song_node * head, char * artist);
