struct song_node {
    char * name;
    char * artist;
    struct song_node * next;
};

struct song_node * song_init(char *, char *);
struct song_node * insert_node_front(struct song_node *, char *, char *);

void print_node(struct song_node *);
void print_list(struct song_node *);

struct song_node * free_node(struct song_node *);
void free_list(struct song_node *);
struct song_node * remove_song(struct song_node *, char *, char *);

int songcmp(struct song_node *, struct song_node *);
struct song_node * insert_node_lexor(struct song_node *, char *, char *);
struct song_node * list_select_random(struct song_node *);
struct song_node * list_search_song(struct song_node *, char *, char *);
struct song_node * list_search_artist(struct song_node *, char *);
