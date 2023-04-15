#include <stdlib.h>

#include "nanobomb_util.h"

int main() {
  char *s = risky_read_string();
  if (s != NULL) {
    free(s);
  }
  return 0;
}
