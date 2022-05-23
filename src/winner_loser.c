/*
** EPITECH PROJECT, 2021
** WINNER_LOSER.C
** File description:
** WINNER_LOSER.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

int winner_or_loser(char **my_map, char **enemy_map)
{
    int my_hits_nb = 0;
    int enemy_hits_nb = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            (my_map[i][j] == 'x') ? (my_hits_nb++) : (0);
            (enemy_map[i][j] == 'x') ? (enemy_hits_nb++) : (0);
        }
    }
    if (my_hits_nb == 14) {
        return (1);
    } else if (enemy_hits_nb == 14) {
        return (0);
    }
    return (-1);
}
