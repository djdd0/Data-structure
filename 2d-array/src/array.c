#include <stdio.h>
#include <assert.h>
#include <malloc.h>


#include "array.h"

struct array *init_array( struct array *t, int rows, int cols )
{
	assert( rows > 0 );
	assert( cols > 0 );
	t->rows = rows;
	t->cols = cols;
	t->data = (T **)malloc( sizeof(T*)*rows );
	for( int i=0; i<t->rows; i++) {
		t->data[i] = (T *)malloc( sizeof(T)*cols );
		for( int j=0; j<t->cols; j++) {
			t->data[i][j] = 0;
		}
	}

	return t;
}

void uninit_array( struct array *t )
{
  assert( t->rows > 0 );
  assert( t->cols > 0 );
  assert( t->data != NULL );
  
  for( int i=0; i<t->rows; i++ ) {
	  free( t->data[i] );
  }
  free(t->data);
  
}

int get_rows( struct array *t )
{
	assert( t->rows > 0 );
	return t->rows;
}

int get_cols( struct array *t )
{
	assert( t->cols > 0 );
	return t->cols;
}

T get( struct array *t, int row, int col )
{
	assert( row >= 0 );
	assert( row < t->rows );
	assert( col >= 0 );
	assert( col < t->cols );
	return t->data[row][col];
}

struct array *set( struct array *t, int row, int col, T e )
{
	assert( row >= 0 );
	assert( row < t->rows );
	assert( col >= 0 );
	assert( col < t->cols );
	t->data[row][col] = e;
	return t;
}
