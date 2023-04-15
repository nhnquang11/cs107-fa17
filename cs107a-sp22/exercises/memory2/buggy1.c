#include <stddef.h>

struct list_node {
  struct list_node *next;
};

int main() {
  struct list_node selfloop;
  selfloop.next = &selfloop;
  //  struct list_node *curr = &selfloop;
  // while (curr != NULL) {
  // curr = curr->next;
  //}
  return 0;
}
