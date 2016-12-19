/*
** main.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger
** 
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
** 
** Started on  Mon Dec 19 16:49:34 2016 Nathan Trehout
** Last update Mon Dec 19 17:06:05 2016 Joubert Miguel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "include/my.h"

int	main()
{
  char	*dest;
  dest = malloc(sizeof(char) * 100);
  retgetkey();
  printf("%s\n", dest);
  return (0);
}
