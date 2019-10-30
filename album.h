struct library {
    struct song_node * table[27];
};

struct library * init();
void album_rm(struct library * );
void album_deeprm(struct library *);
