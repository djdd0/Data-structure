#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>

#include "linked_string.h"

struct linked_string *create_string()
{
	struct linked_string *s;

	s = (struct linked_string *)malloc(sizeof(struct linked_string));

	return init_string(s );
}

void destroy_string(struct linked_string *s)
{
	uninit_string(s);

	free(s);
}


struct linked_string *init_string(struct linked_string *s)
{
	s->head = NULL;
	s->tail = NULL;
	s->len = 0;

	return s;
}

void uninit_string(struct linked_string *s)
{
	struct node *q, *p = s->head;

	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
}

struct node *create_node( char c)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));

	p->c = c;
	p->next = NULL;

	return p;
}

struct linked_string *add_tail(struct linked_string *t, char c)
{
	struct node *p = create_node(c);

	if (t->len == 0) {
		t->head = t->tail = p;
		t->len++;
	}
	else {
		t->tail->next = p;
		t->tail = p;

		t->len++;
	}

	return t;
}

struct linked_string clone(struct linked_string *s)
{
	struct linked_string t;
	struct node *p;
	int i;

	assert(s->head != NULL );

	init_string( &t );

	/* content copy */
	for (i = 0, p=s->head; i < s->len; i++, p = p->next) {
		add_tail(&t, p->c);
	}

	return t;
}

struct linked_string *concate(struct linked_string *t, struct linked_string *s)
{
	int i;
	struct node *p;

	for (i = 0, p=s->head; i < s->len; i++, p=p->next) {
		add_tail(t, p->c);
	}

	return t;
}

bool is_equal(struct linked_string *s, struct linked_string *t)
{
	int i;
	struct node *p, *q;

	if (s->len != t->len) return false;

	for (i = 0, p=s->head, q=t->head; i < s->len; i++, p=p->next, q=q->next) {
		if (p->c != q->c) return false;
	}

	return true;
}

struct node *get(struct linked_string *t, int i)
{
	struct node *p;
	int j;

	assert(t->len > 0);
	assert(i >= 0 && i<t->len);


	for (j = 0, p = t->head; j<t->len; j++, p = p->next) {
		if (j == i) return p;
	}

	return NULL;
}

struct linked_string substring(struct linked_string *s, int i, int l)
{
	struct linked_string t;
	int j;
	struct node *p;

	assert(i + l <= s->len);

	init_string(&t);

	p = get(s, i);
	assert(p != NULL);

	for (j = 0; j < l; j++, p = p->next) {
		add_tail(&t, p->c);
	}

	return t;
}

int index_of(struct linked_string *s, struct linked_string *t)
{
	int i, j;
	struct node *p, *q, *r;

	for (i = 0, p=s->head; i <= s->len-t->len; i++, p=p->next) {
		for (j = 0, r=p, q=t->head; j < t->len; j++, r = r->next, q=q->next) {
			if (r->c != q->c) break;
		}
		if (j == t->len) return i;
	}

	return -1;
}
