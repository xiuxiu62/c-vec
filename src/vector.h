#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
  void **data;
  unsigned int capacity;
  unsigned int size;
  
  struct Vector (*create)(); 
  unsigned int (*length)(struct Vector *self);
  void (*push)(struct Vector *self, void* value);
  void *(*pop)(struct Vector *self);
  void *(*get)(struct Vector *self, unsigned int index);
  void *(*insert)(struct Vector *self, unsigned int index, void *value);
  void *(*remove)(struct Vector *self, unsigned int index);
  void (*empty)(struct Vector *self);
} Vector;

void vector_initialize(Vector *v);

#endif
