struct library {
    struct song_node * table[27];
};

struct library * init();

void print_library(struct library * library);
void library_print_artist(struct library * library, char * artist);
void library_print_letter(struct library * library, char letter);

struct library * free_library