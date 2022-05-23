/*
** EPITECH PROJECT, 2021
** PLAY.C
** File description:
** PLAY.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

int check_attack_coord(char *coord)
{
    if (coord[0] < 'A' || coord[0] > 'H' || coord[1] < '1' || coord[1] > '8') {
        return (84);
    }
    return (0);
}

int first_turn(int my_pid, int player2_pid)
{
    char *attack_coord;

    if (my_pid == player2_pid) {
        my_putstr("waiting for enemy's attack...\n");
        pause();
    } else {
        my_putstr("attack: ");
        while (check_attack_coord(attack_coord = read_line()) == 84) {
            my_putstr("wrong position\n");
            my_putstr("attack: ");
        }
        if (send_attack(my_atoi(&attack_coord[0]) * (attack_coord[1] - 'H'),
            player2_pid, 1) == 84) {
                free(attack_coord);
                return (84);
            }
        pause();
    }
    free(attack_coord);
    return (0);
}

void free_arrays(char *str, char **my_map, char **enemy_map)
{
    free(str);
    for (int i = 0; i < 8; i++) {
        free(my_map[i]);
        free(enemy_map[i]);
    }
}

int play(int player1_pid, int player2_pid, char *filename)
{
    int exit_code;
    char *str = get_boats(filename);
    char **my_map = create_map(str);
    char **enemy_map = create_empty_map();
    int player = 1;
    int my_pid = getpid();

    while ((exit_code = winner_or_loser(my_map, enemy_map)) == -1) {
        print_maps(my_map, enemy_map);
        if (player == 1 && first_turn(my_pid, player2_pid) == 84) {
            return (84);
        }
        (player == 1) ? (player = 2) : (player = 1);
    }
    print_maps(my_map, enemy_map);
    (exit_code == 0) ? (my_putstr("I won\n")) : (my_putstr("Enemy won\n"));
    free_arrays(str, my_map, enemy_map);
    return (exit_code);
}
