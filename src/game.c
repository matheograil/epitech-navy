/*
** EPITECH PROJECT, 2021
** GAME.C
** File description:
** GAME.C file.
*/

#include "../inc/my.h"
#include "../inc/prototypes.h"

static volatile int player2_pid = -1;

void get_player2_pid(int signum, siginfo_t *info, void *context)
{
    player2_pid = info->si_pid;
}

int create_game_two(char **av, int player1_pid)
{
    if (check_file(av[1]) == 84) {
        my_putstr("An error has occurred: invalid file.\n");
        return (84);
    }
    print_pid(player1_pid);
    my_putstr("waiting for enemy connection...\n");
    return (0);
}

int create_game_one(char **av, int player1_pid)
{
    struct sigaction sa;
    int exit_code;

    if (create_game_two(av, player1_pid) == 84) {
        return (84);
    }
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_player2_pid;
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    if (player2_pid == -1) {
        my_putstr("An error has occurred: invalid received pid.\n");
        return (84);
    }
    my_putstr("enemy connected\n\n");
    if ((exit_code = play(player1_pid, player2_pid, av[1])) == 84) {
        my_putstr("An error has occurred: the enemy has disconnected.\n");
    }
    return (exit_code);
}

int join_game(int ac, char **av)
{
    int player1_pid = my_atoi(av[1]);
    int exit_code;

    player2_pid = getpid();
    if (check_file(av[2]) == 84) {
        my_putstr("An error has occurred: invalid file.\n");
        return (84);
    }
    print_pid(player2_pid);
    if (kill(player1_pid, SIGUSR2) == -1) {
        my_putstr("An error has occurred: invalid pid.\n");
        return (84);
    }
    my_putstr("successfully connected\n\n");
    if ((exit_code = play(player1_pid, player2_pid, av[2])) == 84) {
        my_putstr("An error has occurred: the enemy has disconnected.\n");
    }
    return (exit_code);
}
