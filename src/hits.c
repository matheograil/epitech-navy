/*
** EPITECH PROJECT, 2021
** HITS.C
** File description:
** HITS.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

int hit_result(char **map, int i, int j)
{
    if (map[i][j] >= '2' && map[i][j] <= '5') {
        return (1);
    }
    return (0);
}

char **hit(char **map, int i, int j, int status)
{
    if (status == 1) {
        map[i][j] = 'x';
    } else {
        map[i][j] = 'o';
    }
    return (map);
}
