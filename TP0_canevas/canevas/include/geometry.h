#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include "rational.h"

/*
 * Ahmed met à jour la structure suivante pour définir le type Point
 * (enlève les commentaires) 
 */
typedef struct Point {
//  Rational x;  // abscisse
//  Rational y;  // ordonnée
} Point;

/*
 * Bérénice met à jour la structure suivante pour définir le type Segment
 * (enlève les commentaires)
 */
typedef struct Segment {
//  Point begin;  // début du segment
//  Point end;  // fin du segment
} Segment;

/*
 * affiche le point p
 */
void display_point(const Point p);

/*
 * affiche le segment s
 */
void display_segment(const Segment s);

/*
 * renvoie 1 si le point d'intersection key1 précède le point
 * d'intersection key2, 0 sinon
 */
int point_prec(Point key1, Point key2);

/*
 * renvoie 1 si s1 précède s2, 0 sinon
 */
int seg_prec(Segment s1, Segment s2, Rational x);

int orientation(Point p, Point q, Point r);
int onSegment(Point p, Point q, Point r);

/*
 * renvoie 1 si s1 et s2 ont une intersection, 0 sinon
 */
int intersect(Segment s1, Segment s2);

/*
 * calcule et renvoie le point d'intersection entre s1 et s2
 */
Point * getIntersectionPoint(Segment s1, Segment s2);

#endif
