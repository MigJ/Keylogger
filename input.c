#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const evval[3] = {
  "RELEASED",
  "PRESSED ",
      "REPEATED"
};

int main(int ac, char **av)
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
  fputs("SALUT", file);
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
    if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2)
      {
	  fputs("SALUT", file);
          fread(buffer, 100, 1, file);
	  printf("%d\n", ev.value);
      }

  }
  fflush(stdout);
  fprintf(stderr, "%s.\n", strerror(errno));
  fclose(file);
  return EXIT_FAILURE;
}
