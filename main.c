/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 16:56:05 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 19:21:29 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int     main(int argc, char **argv)
{
    char    *line;
    int     fd;
    int     i;
    int     a;

    i = 1;
    a = 1;
    (void)argc;
    fd = open(argv[1], O_RDONLY);
    while (i > 0)
    {
        i = get_next_line(fd, &line);
        printf("%d | %d\t| %s\n", i, a, line);
        a++;
    }
    return (0);
}