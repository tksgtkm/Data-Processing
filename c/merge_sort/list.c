#include <stdio.h>
#include <stdlib.h>

struct item {
  int value;
  struct item *next_ptr;
};

void enter(struct item *first_ptr, const int value) {
  struct item *before_ptr;
  struct item *after_ptr;
  struct item *new_item_ptr;

  before_ptr = first_ptr;
  after_ptr = before_ptr->next_ptr;

  while (1) {
    if (after_ptr == NULL)
      break;

    if (after_ptr->value >= value)
      break;

    after_ptr = after_ptr->next_ptr;
    before_ptr = before_ptr->next_ptr;
  }

  new_item_ptr = malloc(sizeof(struct item));
  new_item_ptr->value = value;

  before_ptr->next_ptr = new_item_ptr;
  new_item_ptr->next_ptr = after_ptr;
}

void print(struct item *first_ptr) {
  struct item *cur_ptr;
  for (cur_ptr = first_ptr; cur_ptr != NULL; cur_ptr = cur_ptr->next_ptr)
    printf("%d ", cur_ptr->value);
  printf("\n");
}

int main() {
  struct item *head_ptr = NULL;

  head_ptr = malloc(sizeof(struct item));

  head_ptr->value = 0;
  head_ptr->next_ptr = NULL;

  enter(head_ptr, 5);
  enter(head_ptr, 4);
  enter(head_ptr, 8);
  enter(head_ptr, 9);
  enter(head_ptr, 1);
  enter(head_ptr, 2);

  print(head_ptr);

  return 0;
}
