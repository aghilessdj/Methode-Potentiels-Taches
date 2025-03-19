#pragma once

#include <stdbool.h>
#include "elmlist.h"

//list_1
typedef struct{
  list_elm_t * head;
  list_elm_t * tail;
  int numelm;
} list_t ;
// Create an empty list
list_t * new_list();
// Delete list, its elements and possibly the data
void del_list(list_t ** ptrL, void (*ptrf) ());
// Clean list; delete its elments but keep data and the list
void clean(list_t * L);
// Is list L empty ?
bool is_empty(list_t * L);
// Gimme the head of L
list_elm_t * get_head(list_t * L);
// Gimme the tail of L
list_elm_t * get_tail(list_t * L);


//list_2
// Gimme the number of elements of L
int get_numelm(list_t * L);
// Take out the data D of the list L if it is present
void take_out(list_t * L, void * D);
// Add a element holding data to the head of L
void cons(list_t * L, void * data);
// Add  a element holding data to the tail of L
void queue(list_t * L, void * data);
// Insert in L a element holding data wrt order given by cmp_ptrf
void ordered_insert(list_t * L, void * data, int (*cmp_ptrf)());
// Do the quick sort
void quick_sort(list_t * L, int (*cmpFct)());
// View list
void view_list(list_t * L, void (*ptrf)());
// Return a ptr to element which data is key else NULL
void find(list_t * L, void ** ptrKey, int (*cmpFct)(), void (*delFct)());