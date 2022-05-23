/*
** EPITECH PROJECT, 2021
** NAVY.C
** File description:
** NAVY.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    if (ac == 2) {
        return (create_game_one(av, getpid()));
    } else if (ac == 3 && is_positive_number(av[1]) == 1) {
        return (join_game(ac, av));
    }
    my_putstr("An error has occurred: argument(s) not recognized.\n");
    return (84);
}
