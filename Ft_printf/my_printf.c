/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:33:22 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/03/03 23:33:30 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void my_printf_str(va_list *my_list)
{
    char  *src = va_arg(*my_list, char *);

    write(1, src, strlen(src));
}

void my_printf_char(va_list *my_list)
{
    char  c = va_arg(*my_list, int);

    write(1, &c, 1);
}

void my_printf_nbr(va_list *my_list)
{
    int num = va_arg(*my_list, int);

    char buffer[20];
    sprintf(buffer, "%d", num);
    write(1, buffer, strlen(buffer));
}

int findIndex(char *tab, char element)
{
    int index = 0;

    for (index = 0; tab[index] != 0; index++)
    {
        if (tab[index] == element)
            return (index);
    }
    return (-1);
}
void my_printf(char *src, ...)
{
    void (*tabFunction[3]) (va_list *) = { my_printf_str, my_printf_char
                                                        , my_printf_nbr};
    char tabIndex[4] = {'s', 'c', 'd', 0};
    va_list my_list;
    int i = 0;
    int tmpIndex = 0;

    va_start(my_list, src);
    for (i = 0; src[i] != 0; i++)
    {
        if (i != 0 && src[i - 1] == '%')
        {
            tmpIndex = findIndex(tabIndex, src[i]);
            if (tmpIndex != -1)
                (*tabFunction[tmpIndex]) (&my_list);
        }
        else if (src[i] != '%')
            write(1, &src[i], 1);
    }
}
int main(int ac, char const **argv)
{
    my_printf("AZERTY %s %d %c\n", "QWERTY", 42, 'q');
}
