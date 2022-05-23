/*
** EPITECH PROJECT, 2021
** PROTOTYPES.H
** File description:
** PROTOTYPES.H file.
*/

#ifndef PROTOTYPES_H_

    #define PROTOTYPES_H_

int main(int, char **);

int create_game_one(char **, int);
int create_game_two(char **, int);
int join_game(int, char **);
void get_player2_pid(int, siginfo_t *, void *);

int check_file(char *);
int check_lines(char *);
int check_characters(char *);
int check_boats(char *);
int check_boats_position(char *);

int is_positive_number(char *);
int absolute_value(int);
int search_1d_array(int, int *, int);
int *get_coordinates(char *, int);
int search_2d_array(int, int **);

int play(int, int, char *);
int first_turn(int, int);
int check_attack_coord(char *);
void free_arrays(char *, char **, char **);

char *get_boats(char *);
char **create_map(char *);
int **get_boats_position(char *);
char **create_empty_map(void);

char *read_line(void);
int get_character(void);

int send_attack(int, int, int);

int hit_result(char **, int, int);
char **hit(char **, int, int, int);

int winner_or_loser(char **, char **);

void print_pid(int);
void print_help(void);
void print_map(char **);
void print_maps(char **, char **);

#endif /* !PROTOTYPES_H_ */
