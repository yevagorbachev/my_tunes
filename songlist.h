struct song_node {
    char * name;
    char * artist;
    struct song_node * next;
};

void free_node(struct song_node *);
void free_list(struct song_node *);
