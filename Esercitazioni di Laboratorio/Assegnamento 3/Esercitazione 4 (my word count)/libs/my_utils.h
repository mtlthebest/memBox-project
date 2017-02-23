#define FILENAME_MAX_LENGTH 255

struct element
{
  char filename[FILENAME_MAX_LENGTH + 1];
  struct element *next;
};

struct input_data
{
  int numero_opzioni;
  int numero_file;
  int count_lines;
  int count_words;
  struct element *primo;
};

void show_file_list (struct input_data *);
void show_all_contents (struct input_data *);
void free_mem (struct input_data *);
void enqueue (char *, struct input_data *);
int my_lc (char *, int *);
int my_wc (char *, int *);
