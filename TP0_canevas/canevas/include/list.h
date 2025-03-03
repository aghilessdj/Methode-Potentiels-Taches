#ifndef LIST_H_
#define LIST_H_

typedef struct LNode {
  void *data;          // données
  struct LNode *next;  // pointeur vers le prochain noeud
  struct LNode *prev;  // pointeur vers le précédent noeud
} LNode;

typedef struct List {
  LNode *head;  // pointeur vers le premier noeud
  LNode *tail;  // pointeur vers le dernier noeud
  int size;     // nombre des noeuds
} List;

/*
 * créer un élément de liste (LNode)
 * y ranger la donnée (data)
 * insérer l'élément en tête de la liste *list
 */
void list_prepend(List *list, void *data);

/*
 * créer un élément de liste (LNode)
 * y ranger la donnée (data)
 * insérer l'élément en queue de la liste *list
 */
void list_append(List *list, void *data);

/*
 * créer un élément de liste (LNode)
 * y ranger la donnée (data)
 * insérer l'élément dans la liste *list après l'élément prev
 * ce dernier est supposé appartenir effectivement à la liste
 */
void list_insert_after(List *list, void *data, LNode *prev);

/*
 * supprimer le premier élément de la liste *list
 * si celle-ci n'est pas vide
 */
void list_remove_first(List *list);

/*
 * supprimer le dernier élément de la liste *list
 * si celle-ci n'est pas vide
 */
void list_remove_last(List *list);

/*
 * supprimer l'élément pointé par node de la liste *list
 * l'élément est supposé appartenir effectivement à la liste
 */
void list_remove_node(List *list, LNode *node);

/*
 * permute les positions des nœuds curr et curr->next
 * dans la liste list
 */
void list_exchange_curr_next(List *list, LNode *curr);

/*
 * supprimer tous les éléments de la liste *list
 * sans pour autant supprimer leurs données (data)
 * qui sont des pointeurs
 */
void list_destroy(List *list);

#endif
