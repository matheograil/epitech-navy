/*
** EPITECH PROJECT, 2021
** READ_LINE.C
** File description:
** READ_LINE.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

int get_character(void)
{
    char c;

    if (read(0, &c, 1) == 1) {
        return (c);
    }
    return (84);
}

char *read_line(void)
{
    char c;
    char *str = malloc(sizeof(char) * 3);

    for (int i = 0; 1; i++) {
        if ((c = get_character()) == 84 || i > 2) {
            return ("84");
        }
        if (c == '\n') {
            str[i] = '\0';
            return (str);
        }
        str[i] = c;
    }
}
