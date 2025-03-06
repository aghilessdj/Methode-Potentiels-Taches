#pragma once

#include "list_1.h"

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