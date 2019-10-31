struct library {
    struct song_node * table[27];
};

struct library * lib_init();
void album_rm(struct library * );
void album_deeprm(struct library *);

void print_letter(struct library *, char);
void print_artist(struct library *, char *);
void print_lib(struct library *);
void print_randsn(struct library *, int);

void insert_lib(struct library *, struct song_node *);
struct song_node * lib_search_song(struct library *, char *, char * );
struct song_node * lib_search_artist(struct library *, char *);

