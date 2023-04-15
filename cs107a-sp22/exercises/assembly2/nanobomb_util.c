#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nano_intro() {
  printf("You wish to defuse this ðŸ’£  nanobomb ðŸ’£  ? There's only two ways this could end.\n");
}

void nano_explode() {
  fprintf(stderr, "\x1b[31mðŸ¤¯  oh noes you exploded ðŸ’¥  b o o m ðŸ’¥\x1b[0m\n");
  exit(1);
}

void nano_defuse() {
  printf("\x1b[32mðŸŽ‰ CONGRATS!ðŸŽ‰   You've defused this nanobomb.\x1b[0m\n");
}

/* Callers are responsible for freeing the returned string. */
static char *risky_read_line() {
  char *line = NULL;
  size_t n = 0;
  if (getline(&line, &n, stdin) < 0) {
    fprintf(stderr, "couldn't parse that...so then...\n");
    nano_explode();
  }
  size_t length = strlen(line);
  if (line[length - 1] == '\n') {
    line[length - 1] = '\0';
  }
  if (line[0] == '\0') {
    fprintf(stderr, "that's an empty line...so then...\n");
    nano_explode();
  }
  return line;
}

/* Callers are responsible for freeing the returned string. */
char *risky_read_string() {
  printf("Enter a string: ");
  return risky_read_line();
}

int risky_read_int() {
  printf("Enter an integer: ");
  char *line = risky_read_line();
  int n = atoi(line);
  free(line);
  return n;
}
