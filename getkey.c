/*
** getkey.c for  in /home/joubert/delivery/Keylogger
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Dec 19 16:55:04 2016 Joubert Miguel
** Last update Mon Dec 19 17:25:18 2016 Joubert Miguel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

void	retgetkey()
{
  FILE *file;
  int	key;
  //int	i;
  //char	*dest;

  file = fopen("key.txt", "w");
  //i = 0;
  //dest = malloc(sizeof(char) * 100);
  initscr();
  keypad(stdscr, TRUE);
  while (1)
    {
      key = getch();
      clear();
      refresh();
      if (key == ' ')
	break;
      if (key == 's')
	fputc('s', file);
      //dest[i++] = 's';
      if (key == 'u')
	fputc('u', file);
      //dest[i++] = 'u';
    }
  endwin();
  fclose(file);
  //dest[i] = '\0';
}
