struct library {
    struct song_node * table[27];
};

struct library * init();
struct library * album_rm(struct library * );
struct library * album_deeprm(struct library *);
