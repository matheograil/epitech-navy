/*
** EPITECH PROJECT, 2021
** PRINT.C
** File description:
** PRINT.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

void print_help(void)
{
    my_putstr("USAGE\n"
    "\t./navy [first_player_pid] navy_positions\n"
    "DESCRIPTION\n"
    "\tfirst_player_pid: only for the 2nd player. pid of the first"
    " player.\n"
    "\tnavy_positions: file representing the positions of the"
    " ships.\n");
}

void print_pid(int pid)
{
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
}

void print_map(char **map)
{
    my_putstr(" |");
    for (int i = 0; i < 8; i++) {
        my_putchar('A' + i);
        my_putchar(' ');
    }
    my_putstr("\n-+");
    for (int i = 0; i < 15; i++) {
        my_putchar('-');
    }
    my_putchar('\n');
    for (int i = 0, count = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            (j == 0) ? (my_put_nbr(count + 1), my_putchar('|'), count++) : (0);
            my_putchar(map[i][j]);
            (j != 8) ? (my_putchar(' ')) : (0);
        }
        my_putchar('\n');
    }
}

void print_maps(char **my_map, char **enemy_map)
{
    my_putstr("my positions:\n");
    print_map(my_map);
    my_putchar('\n');
    my_putstr("enemy's positions:\n");
    print_map(enemy_map);
    my_putchar('\n');
}
