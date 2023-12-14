#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"

struct singly_linked_list *init_list(struct singly_linked_list *t)
{
	t->head = NULL;
	t->count = 0;

	return t;
}

struct singly_linked_list *create_list()
{
    struct singly_linked_list *t = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));

	return init_list(t);
}

struct node *create_node(T e)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));

	p->data = e;
	p->next = NULL;

	return p;
}

struct node *get_node(struct singly_linked_list *t, int i)
{
	struct node *p;
	int j;

	assert(t->count > 0);
	assert(i>=0 && i<t->count);


	for(j=0, p=t->head; j<t->count; j++, p=p->next)
	{
		if(j == i) return p;
	}

	return NULL;
}

struct singly_linked_list *add_head(struct singly_linked_list *t, T e)
{
	struct node *p = create_node(e);

	p->next = t->head;
	t->head = p;
	t->count ++;

	return t;
}

struct singly_linked_list *insert(struct singly_linked_list *t, int i, T e)
{
	struct node *p, *prev_node, *next_node;

	if(i == 0) return add_head(t, e);

	assert(i>0 && i<t->count+1);

	prev_node = get_node(t, i-1);
	assert(prev_node != NULL);

	next_node = prev_node->next;

	p = create_node(e);

	prev_node->next = p;
	p->next = next_node;

	t->count ++;

	return t;
}

struct singly_linked_list *remove_head(struct singly_linked_list *t)
{
	struct node *p;

	assert(t->count > 0);

	p = t->head->next;
	free(t->head);
	t->head = p;
	t->count --;

	return t;
}

struct singly_linked_list *delete_at(struct singly_linked_list *t, int i)
{
	struct node *prev_node, *cur_node;

	assert(t->count > 0);
	if(i == 0) return remove_head(t);

	prev_node = get_node(t, i-1);
	assert(prev_node != NULL);

	cur_node = prev_node->next;
	prev_node->next = cur_node->next;

	t->count --;

	free(cur_node);

	return t;
}

int size(struct singly_linked_list *t)
{
	return t->count;
}

T get(struct singly_linked_list *t, int i)
{
	struct node *p;
	p = get_node(t, i);
	return p->data;
}

void replace(struct singly_linked_list *t, int i, T e)
{
	struct node *p;
	p = get_node(t, i);
	p->data = e;
}

int index(struct singly_linked_list *t, T e)
{
	int n=-1;

	struct node *p;
	int j;

	assert(t->count > 0);

	for(j=0, p=t->head; j<t->count; j++, p=p->next)
	{
		if(p->data == e) n=j;
	}
	return n;
}
