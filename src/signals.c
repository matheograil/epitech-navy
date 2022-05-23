/*
** EPITECH PROJECT, 2021
** SIGNALS.C
** File description:
** SIGNALS.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

int send_attack(int char_nb, int receiver_pid, int player)
{
    while (char_nb != 0) {
        if (kill(receiver_pid, (player == 1) ? (SIGUSR1) : (SIGUSR2)) == -1) {
            return (84);
        }
        usleep(1);
        char_nb--;
    }
    return (0);
}
