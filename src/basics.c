/*
** EPITECH PROJECT, 2021
** BASICS.C
** File description:
** BASICS.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

int is_positive_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (0);
        }
    }
    return (1);
}

int absolute_value(int nb)
{
    if (nb < 0) {
        nb *= -1;
    }
    return (nb);
}

int search_1d_array(int nb, int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        if (nb == arr[i]) {
            return (1);
        }
    }
    return (0);
}

int *get_coordinates(char *str, int lines_nb)
{
    static int coord[5];

    coord[0] = my_atoi(&str[0 + lines_nb * 8]);
    coord[1] = str[2 + lines_nb * 8];
    coord[2] = my_atoi(&str[3 + lines_nb * 8]);
    coord[3] = str[5 + lines_nb * 8];
    coord[4] = my_atoi(&str[6 + lines_nb * 8]);
    return (coord);
}

int search_2d_array(int nb, int **arr)
{
    for (int i = 0; i < 14; i++) {
        if (nb == arr[i][0]) {
            return (arr[i][1]);
        }
    }
    return (-1);
}
