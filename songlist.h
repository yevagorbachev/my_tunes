struct song_node {
    char * name;
    char * artist;
    struct song_node * next;
};

struct song_node * insert_node_front(struct song_node *, char *, char *);
struct song_node * insert_node_lexor(struct song_node *, char *, char *);
void print_list(struct song_node *);
void print_node(struct song_node *);
struct song_node * remove_node_index(struct song_node *, int i);
struct song_node * free_list(struct song_node *);
struct song_node * free_node(struct song_node *);
