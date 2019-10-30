struct song_node {
    char * name;
    char * artist;
    struct song_node * next;
};

int nsrand();

// BASE FUNCTIONALITY
struct song_node * insert_node_front(struct song_node *, char *, char *);
void print_node(struct song_node *);
void print_list(struct song_node *);
struct song_node * free_node(struct song_node *);
struct song_node * free_list(struct song_node *);
struct song_node * remove_node_index(struct song_node *, int);

// ADDITIONAL FUNCTIONALITY
struct song_node * insert_node_lexor(struct song_node *, char *, char *);
struct song_node * select_random(struct song_node *);
struct song_node * search_song(struct song_node *, char *, char *);
struct song_node * search_artist(struct song_node *, char *);
