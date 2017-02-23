// controllo che argc sia maggiore o uguale a 2
int step_one (int);

// controllo lunghezza nomi file (max 255 caratteri)
int step_one_point_five (int, char **);

// popolo la lista e, al contempo, conteggio il numero delle opzioni
int step_two (int, char **, struct input_data *);

// controllo che venga fornito il nome di almeno un file
int step_three (int, struct input_data *);

// parsing delle opzioni
int step_four (int, char **, struct input_data *);

// verifico l'esistenza dei file specificati
int step_five (struct input_data *);
