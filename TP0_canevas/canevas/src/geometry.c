#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"

/*
 * affiche le point p
 */
void display_point(const Point p) {
  printf("(");
  display_rational(p.x);
  printf(",");
  display_rational(p.y);
  printf(")");
}

/*
 * affiche le segment s
 */
void display_segment(const Segment s) {
  printf("from: ");
  display_point(s.begin);
  printf(" to: ");
  display_point(s.end);
}

/*
 * renvoie 1 si le point d'intersection key1 précède le point
 * d'intersection key2, 0 sinon
 */
int point_prec(Point key1, Point key2) {
  // A faire
  return;
}

/*
 * renvoie 1 si s1 précède s2, 0 sinon
 */
int seg_prec(Segment s1, Segment s2, Rational x) {
  // A faire
  return;
}

/*
 * renvoie 1 si s1 et s2 ont une intersection, 0 sinon
 */
int intersect(Segment s1, Segment s2) {
  // A faire
  return;
}

/*
 * calcule et renvoie le point d'intersection entre s1 et s2
 */
Point* getIntersectionPoint(Segment s1, Segment s2) {
  // A faire
  return;
}
