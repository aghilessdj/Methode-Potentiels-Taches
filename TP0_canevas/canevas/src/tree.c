#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

static void preorder(EventNode *node) {
  if (node != NULL) {
    display_point(node->key);
    printf("\n");
    preorder(node->left);
    preorder(node->right);
  }
}

static void inorder(EventNode *node) {
  if (node != NULL) {
    inorder(node->left);
    display_point(node->key);
    printf("\n");
    inorder(node->right);
  }
}

static void postorder(EventNode *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    display_point(node->key);
    printf("\n");
  }
}

// order = 0 (preorder), 1 (inorder), 2 (postprder)
void display_tree_keys(const EventTree *tree, int order) {
  switch (order) {
    case 0:
      preorder(tree->root);
      break;
    case 1:
      inorder(tree->root);
      break;
    case 2:
      postorder(tree->root);
      break;
    default:
      printf("display_tree_keys: non valid order parameter\n");
      exit(1);
  }
}

/*
 * renvoie un nouveau EventNode d'attribut
 *  <key, type, s1, s2, NULL, NULL>
 */
EventNode * new_event(Point key, int type, Segment *s1, Segment *s2) {
  // A faire
  return;
}

/*
 * recherche la place dans tree du nouvel événement event
 * et l'insère.
 * L'ABR est modifié et la modification peut porter sur sa racine.
 */
void insert_event(EventTree *tree, EventNode *event) {
  // A faire
}

/*
 * trouve le prochain événement, le supprime de l'arbre et le renvoie
 */
EventNode* get_next_event(EventTree *tree) {
  // A faire
  return;
}

/*
 * renvoie 1 si le clef key existe dans l'ABR tree, O sinon
 */
int event_exists(EventTree *tree, Point key) {
  // A faire
  return;
}
