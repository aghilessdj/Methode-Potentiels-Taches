#pragma once

void ranking(list_t * G); // Calcule des ranks des jobs de la liste
void prune(list_t * G); // Supprime les arcs inutils

void marges(list_t * G);// Calcule dates plus tôt, dates plus tard, marges totales et libres et chemin critique