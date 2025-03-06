#pragma once

#include <stdbool.h>
#include "elmlist.h"


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