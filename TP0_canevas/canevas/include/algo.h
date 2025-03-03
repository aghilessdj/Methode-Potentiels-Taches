#ifndef ALGO_H_
#define ALGO_H_

#include "list.h"

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
List * load_segments(char *infilename);

/*
 * ranger dans un fichier texte de nom outfilename
 * les points de la liste *intersections.
 * La premier ligne indique le nombre de points.
 * Puis chaque ligne contient les coordonnée de chaque point.
 * Le format des coordonnées est le même que pour les segments.
 */
void save_intersections(char *outfilename, List *intersections);

/*
 * exécute l'algorithme glouton sur les segments rangés
 * dans le fichier texte de nom infilename et range les points
 * d'intersection dans le fichier texte de nom outfilename
 */
void allPairs(char *infilename, char *outfilename);

/*
 * exécute l'algorithme Bentley-Ottmmann sur les segments rangés
 * dans le fichier texte de nom infilename et range les points
 * d'intersection dans le fichier texte de nom outfilename
 */
void BentleyOttmmann(char *infilename, char *outfilename);

#endif
