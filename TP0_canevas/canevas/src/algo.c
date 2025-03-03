#include <stdlib.h>
#include <stdio.h>
#include "algo.h"
#include "tree.h"

/*
 * ranger dans une liste les segments stockés
 * dans le fichier texte de nom infilename
 * dont la première ligne est un entier indiquant
 * le nombre de segments et les lignes suivantes
 * les coordonnées des segments.
 * chaque ligne est composée de 2 couples.
 * Le premier couple est les coordonnées du début du segment
 * au format : xnum / xden ; pour l'abscisse
 * et : ynum / yden ; pour l'ordonnée.
 * Le second couple est la fin du segment
 */
List * load_segments(char *infilename) {
  List *segments = (List*) calloc(1, sizeof(List));

  FILE *fptr;
  if ((fptr = fopen(infilename,"r")) == NULL) {
    printf("Error while opening file %s.", infilename);
    exit(1);
  }
  int size;
  fscanf(fptr, "%d", &size);

  for (int i = 0; i < size; i++) {
    long a1, b1, c1, d1, a2, b2, c2, d2;
    fscanf(fptr, "%ld/%ld,%ld/%ld", &a1, &b1, &c1, &d1);
    fscanf(fptr, "%ld/%ld,%ld/%ld", &a2, &b2, &c2, &d2);
    Segment *s = (Segment*) malloc(sizeof(Segment));
    Point p1 = {{a1,b1},{c1,d1}};
    Point p2 = {{a2,b2},{c2,d2}};
    if (point_prec(p1, p2)) {
      (*s).begin = p1;
      (*s).end = p2;
    }
    else {
      (*s).begin = p2;
      (*s).end = p1;
    }
    list_append(segments, s);
  }
  fclose(fptr);
  return segments;
}

/*
 * ranger dans un fichier texte de nom outfilename
 * les points de la liste *intersections.
 * La premier ligne indique le nombre de points.
 * Puis chaque ligne contient les coordonnée de chaque point.
 * Le format des coordonnées est le même que pour les segments.
 */
void save_intersections(char *outfilename, List *intersections) {
  FILE *fptr;
  if ((fptr = fopen(outfilename,"w")) == NULL) {
    printf("Error while opening file %s.\n", outfilename);
    exit(1);
  }

  fprintf(fptr, "%d\n", intersections->size);
  LNode *curr = intersections->head;
  for (int i = 0; i < intersections->size; i++) {
    fprintf(fptr, "%ld/%ld,%ld/%ld\n",
            ((Point*) curr->data)->x.num,
            ((Point*) curr->data)->x.den,
            ((Point*) curr->data)->y.num,
            ((Point*) curr->data)->y.den);
    curr = curr->next;
  }
}

/*
 * exécute l'algorithme glouton sur les segments rangés
 * dans le fichier texte de nom infilename et range les points
 * d'intersection dans le fichier texte de nom outfilename
 */
void allPairs(char *infilename, char *outfilename) {
  // A faire
}

/*
 * exécute l'algorithme Bentley-Ottmmann sur les segments rangés
 * dans le fichier texte de nom infilename et range les points
 * d'intersection dans le fichier texte de nom outfilename
 */
void BentleyOttmmann(char *infilename, char *outfilename) {
  // A faire
}
