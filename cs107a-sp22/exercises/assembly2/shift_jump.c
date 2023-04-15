#include "nanobomb_util.h"

int main() {
  int i = risky_read_int();
  if ((i >> 3) != 0) {
    i += risky_read_int();
  } else {
    i *= risky_read_int();
  }
  return i;
}
