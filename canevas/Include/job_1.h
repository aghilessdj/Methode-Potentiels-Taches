#pragma once

#include "list_1.h"

//job_1

#define UNDEF -2
/** Des redondances possibles avec d'autres TAs ! */
typedef struct {
  char * title;                 // Nom de la tâche
  double life;                  // Durée de la tâche
  int input_degree;             // Son degré de dépendance
  int output_degree;            // Les tâches qui en dépendent
  int rank;                     // Rang de la tâche
  int dyn_input_degree;         // Facilité de prog
  list_t * precedence;   // Les tâches précédentes
  list_t * posteriority; // Les tâches ultérieures
  double au_plus_tot;           // Date au plus tôt
  double au_plus_tard;          // Date au plus tard
  double marge_totale;          // Marge totale
  double marge_libre;           // Marge libre
  bool critique;                // Une tâche critique ?
} job_t;


//job_2
job_t * new_empty_job();
job_t * new_job(char * title);
void free_job(job_t ** ptrJ);

void view_job(job_t * J);

char * get_job_tilte(job_t * J);
void set_job_title(job_t * J, char * title);

double get_job_life(job_t * J);
void set_job_life(job_t * J, double life);

int get_job_iDegree(job_t * J);
void set_job_iDegree(job_t * J, int iDegree);
void incr_job_iDegree(job_t * J);
void decr_job_iDegree(job_t * J);


//job_3
int get_job_oDegree(job_t * J);
void set_job_oDegree(job_t * J, int oDegree);
void incr_job_oDegree(job_t * J);
void decr_job_oDegree(job_t * J);

int get_job_rank(job_t * J);
void set_rank(job_t * J, int rank);

int titleJobCmp(job_t * J1, job_t * J2);
int iDegreeJobCmp(job_t * J1, job_t * J2);
int oDegreeJobCmp(job_t * J1, job_t * J2);
int rangJobCmp(job_t *J1, job_t * J2);

//Les fonction ajouter
double get_job_tot(job_t * J); // Retourne Date au plus tôt d'un job
double get_job_tard(job_t * J); // Retourne Date au plus tard d'un job

int max_rank(list_t * G); // Retourne la valeur du rank la plus grande dans une liste de job
double max_tot_life (list_t * G); // Retourne la valeur du life la plus grande dans une liste de job
double min_tard (list_t * G); // Retourne la valeur du Date au plus tard la plus petite dans une liste de job
double min_tot (list_t * G); // Retourne la valeur du Date au plus tôt la plus petite dans une liste de job