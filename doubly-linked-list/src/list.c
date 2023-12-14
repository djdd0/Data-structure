#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"

struct doubly_linked_list *init_list( struct doubly_linked_list *t )
{
	t->head = NULL;
	t->tail = NULL;
	t->counter = 0;

	return t;
}

struct doubly_linked_list *create_list()
{
    struct doubly_linked_list *t = (struct doubly_linked_list *)malloc( sizeof(struct doubly_linked_list) );

	return init_list( t );
}

struct node *create_node( T e )
{
	struct node *p = (struct node *)malloc( sizeof(struct node) );

	p->data = e;
	p->prev = NULL;
	p->next = NULL;

	return p;
}

struct node *get_node(struct doubly_linked_list *t, int i)
{
	struct node *p;
	int j;

	assert(t->counter > 0);
	assert(i>=0 && i<t->counter);


	for(j=0, p=t->head; j<t->counter; j++, p=p->next)
	{
		if(j == i) return p;
	}

	return NULL;
}

struct doubly_linked_list *add_head(struct doubly_linked_list *t, T e)
{
	struct node *p = create_node(e);

	p->next = t->head;
	if(t->counter == 0) t->tail = p;
	else t->head->prev = p;
	t->head = p;
	t->counter ++;

	return t;
}

struct doubly_linked_list *add_tail( struct doubly_linked_list *t, T e )
{
	struct node *p = create_node(e);

	p->prev = t->tail;
	if(t->counter == 0) t->head = p;
	else t->tail->next = p;
	t->tail = p;
	t->counter ++;

	return t;
}

struct doubly_linked_list *insert(struct doubly_linked_list *t, int i, T e)
{
	struct node *p, *prev_node, *next_node;

	if(i == 0) return add_head(t, e);
	else if(i == t->counter) return add_tail( t, e );

	assert(i>0 && i<t->counter);

	prev_node = get_node(t, i-1);
	assert(prev_node != NULL);

	next_node = prev_node->next;

	p = create_node(e);

	prev_node->next = p;
	p->next = next_node;

	p->prev = prev_node;
	next_node->prev = p;

	t->counter ++;

	return t;
}

struct doubly_linked_list *remove_head(struct doubly_linked_list *t)
{
	struct node *p;

	assert(t->counter > 0);

	p = t->head->next;
	free(t->head);
	t->head = p;
	if(t->counter == 1) t->tail=NULL;
	else p->prev = NULL;
	t->counter --;

	return t;
}

struct doubly_linked_list *remove_tail(struct doubly_linked_list *t)
{
	struct node *p;

	assert(t->counter > 0);

	p = t->tail->prev;
	free(t->tail);
	t->tail = p;
	if(t->counter == 1) t->head=NULL;
	else p->next = NULL;
	t->counter --;

	return t;
}

struct doubly_linked_list *delete_at(struct doubly_linked_list *t, int i)
{
	struct node *prev_node, *cur_node, *next_node;

	assert(t->counter > 0);
	if(i == 0) return remove_head(t);
	else if(i == t->counter) return remove_tail(t);

	cur_node = get_node(t, i);
	assert(prev_node != NULL);

	prev_node = cur_node->prev;
	next_node = cur_node->next;
	prev_node->next = next_node;
	next_node->prev = prev_node;

	t->counter --;

	free(cur_node);

	return t;
}

int size(struct doubly_linked_list *t)
{
	return t->counter;
}

T get(struct doubly_linked_list *t, int i)
{
	struct node *p;
	p = get_node(t, i);
	return p->data;
}

void replace(struct doubly_linked_list *t, int i, T e)
{
	struct node *p;
	p = get_node(t, i);
	p->data = e;
}

int index(struct doubly_linked_list *t, T e)
{
	int n=-1;

	struct node *p;
	int j;

	assert(t->counter > 0);

	for(j=0, p=t->head; j<t->counter; j++, p=p->next)
	{
		if(p->data == e) n=j;
	}
	return n;
}
