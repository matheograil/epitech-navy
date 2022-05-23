/*
** EPITECH PROJECT, 2021
** MY_ATOI.C
** File description:
** MY_ATOI function.
*/

int my_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
        res = res * 10 + str[i] - '0';
        i++;
    }
    res *= sign;
    return (res);
}
