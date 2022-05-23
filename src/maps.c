/*
** EPITECH PROJECT, 2021
** MAPS.C
** File description:
** MAPS.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

char *get_boats(char *filename)
{
    char *str;
    int size = 32;
    int file = open(filename, O_RDONLY);

    str = malloc(sizeof(char) * (size + 1));
    read(file, str, size);
    str[size] = '\0';
    close(file);
    return (str);
}

int **get_boats_position(char *str)
{
    int **res = malloc(sizeof(int *) * 14);
    int *c;

    for (int i = 0; i < 14; i++) {
        res[i] = malloc(sizeof(int *) * 2);
    }
    for (int i = 0, len = 0; i < 4; i++) {
        c = get_coordinates(str, i);
        if (c[1] == c[3]) {
            for (int j = 0; j < c[0]; j++, res[len][1] = c[0], len++)
                res[len][0] = (c[2] < c[4]) ? (c[1] - 'A' + j * 8 + (c[2] - 1)
                    * 8) : (c[1] - 'A' + j * 8 + (c[4] - 1) * 8);
        } else {
            for (int j = 0; j < c[0]; j++, res[len][1] = c[0], len++)
                res[len][0] = (c[1] < c[3]) ? (c[1] - 'A' + j + c[0] * 8)
                    : (c[3] - 'A' + j + c[0] * 8);
        }
    }
    return (res);
}

char **create_map(char *str)
{
    char **map = malloc(sizeof(char *) * 8);
    int **boats_position = get_boats_position(str);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char *) * 8);
    }
    for (int i = 0, char_nb = 0, boat_id; i < 8; i++) {
        for (int j = 0; j < 8; j++, char_nb++) {
            if ((boat_id = search_2d_array(char_nb, boats_position)) == -1) {
                map[i][j] = '.';
            } else {
                map[i][j] = boat_id + '0';
            }
        }
    }
    for (int i = 0; i < 14; i++) {
        free(boats_position[i]);
    }
    return (map);
}

char **create_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 8);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char *) * 8);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
    }
    return (map);
}
