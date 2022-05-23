/*
** EPITECH PROJECT, 2021
** CHECKS.C
** File description:
** CHECKS.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

int check_lines(char *str)
{
    int i = 0;
    int lines_nb = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            lines_nb++;
        }
        i++;
    }
    if (lines_nb != 4 || i != 32 || my_atoi(&str[0]) != 2
        || my_atoi(&str[8]) != 3 || my_atoi(&str[16]) != 4
        || my_atoi(&str[24]) != 5) {
        return (84);
    }
    return (0);
}

int check_characters(char *str)
{
    for (int i = 0, lines_nb = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            lines_nb++;
            continue;
        }
        if ((str[0 + lines_nb * 8] < '1' || str[0 + lines_nb * 8] > '8')
            || (str[1 + lines_nb * 8] != ':')
            || (str[2 + lines_nb * 8] < 'A' || str[0 + lines_nb * 8] > 'H')
            || (str[3 + lines_nb * 8] < '1' || str[0 + lines_nb * 8] > '8')
            || (str[4 + lines_nb * 8] != ':')
            || (str[5 + lines_nb * 8] < 'A' || str[0 + lines_nb * 8] > 'H')
            || (str[6 + lines_nb * 8] < '1' || str[0 + lines_nb * 8] > '8')) {
            return (84);
        }
    }
    return (0);
}

int check_boats(char *str)
{
    int *arr = malloc(sizeof(int) * 4);

    for (int i = 0, len = 0, lines_nb = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            arr[len] = str[0 + lines_nb * 8] - '0';
            len++;
            lines_nb++;
            continue;
        }
        if (absolute_value((str[2 + lines_nb * 8] + str[3 + lines_nb * 8])
            - (str[5 + lines_nb * 8] + str[6 + lines_nb * 8])) + 1
            != str[0 + lines_nb * 8] - '0'
            || search_1d_array(str[0 + lines_nb * 8] - '0', arr, len) == 1) {
            free(arr);
            return (84);
        }
    }
    free(arr);
    return (0);
}

int check_boats_position(char *str)
{
    int **boats_position = get_boats_position(str);

    for (int i = 0, trigger = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++, trigger = 0) {
            if (boats_position[i][0] == boats_position[j][0] && trigger == 1) {
                for (int i = 0; i < 14; i++) {
                    free(boats_position[i]);
                }
                return (84);
            } else if (boats_position[i][0] == boats_position[j][0]) {
                trigger++;
            }
        }
    }
    for (int i = 0; i < 14; i++) {
        free(boats_position[i]);
    }
    return (0);
}

int check_file(char *filename)
{
    int file = open(filename, O_RDONLY);
    int size;
    char *str;

    if (file == -1) {
        return (84);
    }
    size = 32;
    str = malloc(sizeof(char) * (size + 1));
    read(file, str, size);
    str[size] = '\0';
    if (check_lines(str) == 84 || check_characters(str) == 84
        || check_boats(str) == 84 || check_boats_position(str) == 84) {
        return (84);
    }
    free(str);
    close(file);
    return (0);
}
