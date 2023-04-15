#include <stdio.h>

char *foo(char *s, char *t) {
  s[0] = t[2];
  t[2] = 'g';
  s = t;
  t = NULL;
  return s+1;
}

int main() {
  char s[] = "abc";
  char t[] = "def";
  printf("%s\n", foo(s, t));
  printf("%s\n", s);
  return 0;
}
