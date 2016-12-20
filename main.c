/*
** main.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger
**
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Dec 19 16:49:34 2016 Nathan Trehout
** Last update Tue Dec 20 19:06:39 2016 Nathan Tréhout
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

int	is_prefix(char *p)
{
  if (p[0] == 's' && p[1] == 'u' && p[2] == 'd' && p[3] == 'o')
    return (1);
  else if (p[0] == 'f' && p[1] == 'i' && p[2] == 'r' && p[3] == 'e' && p[4] == 'f' && p[5] == 'o' && p[6] == 'x')
    return (2);
  else
    return (84);
}

int	write_sudo(char *prefix, char *to_write)
{
  FILE *file;


  file = fopen("sudo.txt", "w");
  fputs(to_write, file);

}

int	write_firefox(char *prefix, char *to_write)
{

}

int	init(char *to_write, char *prefix)
{
  if (is_prefix(prefix) == 1)
    write_sudo(prefix, to_write);
  else if (is_prefix(prefix) == 2)
    write_firefox(prefix, to_write);
  else
    return (84);
  return (0);
}


int	main()
{
  init("salut tout le monde !", "sudo");
  return (0);
}
