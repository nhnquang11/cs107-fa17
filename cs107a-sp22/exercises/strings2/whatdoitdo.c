#include <stdio.h>
#include <string.h>

/**
 * Does...something! How does it work?
 *
 * @param s It's a string...but that's all we know...
 */
void whatdoitdo(char *s) {
    char *curr = s;
    // Hint: The value of an assignment like (x = 5) is the assigned value.
    while (1) {
        char *ptr = strchr(curr, '-');
        if (ptr == NULL) {
            break;
        }
        
        *ptr = '_';
        curr = ptr + 1;
    }
}

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    // Make a copy of the argument. Conventionally don't modify argv.
    int length = strlen(argv[i]);
    char buf[length+1];
    strcpy(buf, argv[i]);

    whatdoitdo(buf);

    printf("Original: %s | Afterwards: %s\n", argv[i], buf);
  }
}
