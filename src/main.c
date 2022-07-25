#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef enum {
  CHAR,
  STR,
  INT,
  UINT,
  FLOAT,
  DOUBLE,
} type;

int main() {
  struct Vector names, numbers;
  vector_initialize(&names);
  vector_initialize(&numbers);
  
  int i;

  char *name_list[3] = {"john", "xiu", "opi"};
  for (i = 0; i < 3; i++)
    names.push(&names, name_list[i]);
  
  for (i = 0; i < names.size; i++)
    printf("%s", (char *) names.get(&names, i));

  int number_list[5] = {5, 4, 3, 2, 1};
  for (i = 0; i < 5; i++)
    numbers.push(&numbers, (void *) number_list[i]);
  
  for (i = 0; i < numbers.size; i++)
    printf("%d", (int) numbers.get(&numbers, i));
  
  
  return 0;
}
