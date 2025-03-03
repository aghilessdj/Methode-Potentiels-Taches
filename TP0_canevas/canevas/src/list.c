#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*
 * créer et renvoie un nouveau nœud (LNode)
 */
static LNode * new_node(void *data) {
  // A faire
  return;
}

/*
 * créer un élément de liste (LNode)
 * y ranger la donnée (data)
 * insérer l'élément en tête de la liste *list
 */
void list_prepend(List *list, void *data) {
  // A faire
}

/*
 * créer un élément de liste (LNode)
 * y ranger la donnée (data)
 * insérer l'élément en queue de la liste *list
 */
void list_append(List *list, void *data) {
  // A faire
}

/*
 * créer un élément de liste (LNode)
 * y ranger la donnée (data)
 * insérer l'élément dans la liste *list après l'élément prev
 * ce dernier est supposé appartenir effectivement à la liste
 */
void list_insert_after(List *list, void *data, LNode *curr) {
  // A faire
}

/*
 * supprimer le premier élément de la liste *list
 * si celle-ci n'est pas vide
 */
void list_remove_first(List *list) {
  // A faire
}

/*
 * supprimer le dernier élément de la liste *list
 * si celle-ci n'est pas vide
 */
void list_remove_last(List *list) {
  // A faire
}

/*
 * supprimer l'élément pointé par node de la liste *list
 * l'élément est supposé appartenir effectivement à la liste
 */
void list_remove_node(List *list, LNode *node) {
  // A faire
}

/*
 * permute les positions des nœuds curr et curr->next
 * dans la liste list
 */
void list_exchange_curr_next(List *list, LNode *curr) {
  // A faire
}

/*
 * supprimer tous les éléments de la liste *list
 * sans pour autant supprimer leurs données (data)
 * qui sont des pointeurs
 */
void list_destroy(List *list) {
  // A faire
}
