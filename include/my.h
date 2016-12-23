/*
** my.h for keylogger in /home/azword/delivery/Perso/PSU/Keylogger/include
**
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Dec 19 16:53:54 2016 Nathan Trehout
** Last update Fri Dec 23 12:13:04 2016 Nathan Tréhout
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>

char    *set_name(char *name, char *buffer, char *dest);

void	create_python(int fd, char *dest);

void     prepare_python(int fd, char *name);

int	fs_open_file(char *path);

int	find_command(char *str);

int	verif_file();

int	put_in_file(char *str, int i);

int	store_send_input(char *key_logs);

int	my_putstr(char *str);

int	my_strlen(char *str);

#endif
