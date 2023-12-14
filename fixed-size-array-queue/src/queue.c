#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#include "queue.h"

struct queue *init_queue( struct queue *q )
{
	q->count = 0;
	q->front_index = 0;

	return q;
}

struct queue *enter(struct queue *q, T e)
{
	int index;

	index = (q->front_index+q->count)%MAX_ELE;

	q->store[index] = e;
	q->count ++;

	return q;
}

T leave(struct queue *q)
{
	T v;
	int index;

	assert( q->count > 0 );

	v = q->store[q->front_index];

	index = (q->front_index+1)%MAX_ELE;
	q->front_index = index;

	q->count --;

	return v;
}

T front(struct queue *q)
{
	T v;

	assert(q->count > 0);

	v = q->store[q->front_index];

	return v;
}

bool is_empty(struct queue *q)
{
	return q->count == 0 ? true : false;
}
