#include "vector.h"
#include <stdlib.h>

unsigned int initial_capacity = 4;

void vector_initialize(Vector *v); 
unsigned int length(Vector *self);
void push(Vector *self, void *value);
void *pop(Vector *self);
void *get(Vector *self, unsigned int index);
void *insert(Vector *self, unsigned int index, void *value);
void *remove(Vector *self, unsigned int index);
void empty(Vector *self);

static void resize(Vector *self, unsigned int capacity);

void vector_initialize(Vector *v) {
  v->capacity = initial_capacity;
  v->size = 0;
  v->data = malloc(sizeof(void *) * v->capacity);
  
  v->length = length;
  v->push = push;
  v->pop = pop;
  v->get = get;
  v->insert = insert;
  v->remove = remove;
  v->empty = empty;
}

unsigned int length(Vector *self) {
  return self->size;
}

void push(Vector *self, void *value) {
  if (self->capacity == self->size) 
    resize(self, self->capacity * 2);
  
  self->data[self->size++] = value;
}

void *pop(Vector *self) {
  if (self->size == 0)
    return NULL;
  
  void *old_value = self->insert(self, self->size - 1, NULL);
  self->size--;
  
  return old_value;
}

void *get(Vector *self, unsigned int index) {
  if (index >= 0 && index < self->capacity)
    return self->data[index];
  
  return NULL;
}

void *insert(Vector *self, unsigned int index, void *value) {
  while(index > self->capacity) 
    resize(self, self->capacity * 2); 
  
  void *old_value = self->data[index];
  self->data[index] = value;  
  
  return old_value;
}

void *remove(Vector *self, unsigned int index) {
  if (index >= self->size) 
    return NULL;
  
  void *old_value = self->insert(self, index, NULL);
  for (; index < self->size - 1; index++)
    self->data[index] = self->data[index + 1];
  
  self->data[index + 1] = NULL;
  self->size--;
  
  if (self->size == self->capacity / 4)
    resize(self, self->capacity /2);
  
  return old_value;
  
}

void empty(Vector *self) {
  free(self->data);
  resize(self, initial_capacity);
  self->size = 0;
}

static void resize(Vector *vector, unsigned int capacity) {
  void **data = realloc(vector->data, sizeof(void *) * capacity);
  if (data) {
    vector->data = data;
    vector->capacity = capacity;
  }
}