#ifndef TREE_H_
#define TREE_H_

#include "geometry.h"

// type = 0 (intersection), 1 (begin), 2 (end)
typedef struct EventNode {
  Point key;    // position de l'événement utilisée comme clé dans l'ABR
  int type;     // type = 0 (intersection), 1 (début), 2 (fin)
  Segment *s1;  // si le type est 0, alors s1 et s2 sont les deux
                // segments qui ont une intersection en position key
  Segment *s2;  // si le type est 1 ou 2, alors s2 = NULL
  struct EventNode *left;   // pointeur vers le fils gauche
  struct EventNode *right;  // pointeur vers le fils droit
} EventNode;

typedef struct EventTree {
  EventNode *root;  // pointeur vers la racine de l'arbre
  int size;         // nombre d'événements dans l'arbre
} EventTree;

// order = 0 (preorder), 1 (inorder), 2 (postprder)
void display_tree_keys(const EventTree *tree, int order);

/*
 * renvoie un nouveau EventNode d'attribut
 *  <key, type, s1, s2, NULL, NULL>
 */
EventNode * new_event(Point key, int type, Segment *s1, Segment *s2);

/*
 * recherche la place dans tree du nouvel événement event
 * et l'insère.
 * L'ABR est modifié et la modification peut porter sur sa racine.
 */
void insert_event(EventTree *tree, EventNode *event);

/*
 * trouve le prochain événement, le supprime de l'arbre et le renvoie
 */
EventNode * get_next_event(EventTree *tree);

/*
 * renvoie 1 si le clef key existe dans l'ABR tree, O sinon
 */
int event_exists(EventTree *tree, Point key);

#endif
