#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"

struct list *create_list(int init_cap)
{
    struct list *l = (struct list *)malloc(sizeof(struct list));
	
	if(init_cap <= 0) init_cap = 10;
	l->ele = (T *)malloc(init_cap * sizeof(T));

	l->capacity = init_cap;
    l->counter = 0;
    return l;
}

struct list *insert(struct list *l, int i, T e)
{
	int j;

	if(l->counter == l->capacity)
	{
		int new_cap = l->capacity * 2;
		T * new_ele = (T *)malloc(sizeof(T)*new_cap);
		for(j=0; j<l->counter; j++)
		{
			new_ele[j] = l->ele[j];
		}
		l->capacity = new_cap;
		free(l->ele);
		l->ele = new_ele;
	}

	assert(i>=0 && i<=l->counter);

    for(j=l->counter; j>i; j--)
    {
        l->ele[j] = l->ele[j-1];
    }

    l->counter ++;
    l->ele[i] = e;
    return l;
}

struct list *delete_at(struct list *l, int i)
{
	int j;

	assert(i>=0 && i<l->counter);

	for(j=i; j<l->counter-1; j++)
	{
		l->ele[j] = l->ele[j+1];
	}

	l->counter --;
	return l;
}

int size(struct list *l)
{
	return l->counter;
}

T get(struct list *l, int i)
{
	assert(i>=0 && i<l->counter);

	return l->ele[i];
}

void replace(struct list *l, int i, T e)
{
	assert(i>=0 && i<l->counter);

	l->ele[i] = e;
}

int index(struct list *l, T e)
{
	int j,i=-1;

	assert(l->counter > 0);

	for (j = 0; j < l->counter - 1; j++)
	{
		if (l->ele[j] == e)
		{
			i = j;
			break;
		}
	}
	return i;
}
