#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"

//typedef enum { false, true } bool;

struct stack *init_stack(struct stack *t)
{
	t->count = 0;

	return t;
}

struct stack *create_stack()
{
	struct stack *t;

	t = (struct stack *)malloc(sizeof(struct stack));

	return init_stack(t);
}

struct stack *push(struct stack *t, T e)
{
	int loc;

	assert(t->count < MAX_ELE);

	loc = t->count;

	t->store[loc] = e;
	t->count++;

	return t;
}

T pop(struct stack *t)
{
	T e;
	int loc;

	assert(t->count > 0);

	loc = t->count - 1;

	e = t->store[loc];

	t->count--;

	return e;
}

bool is_empty(struct stack *t)
{
	return t->count == 0 ? true : false;
}

T top(struct stack *t)
{
	int loc;

	assert(t->count > 0);

	loc = t->count - 1;

	return t->store[loc];
}
