#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "job_1.h"

job_t * new_empty_job ( ) {
    job_t * J = calloc ( 1, sizeof (job_t ) );
    assert( J );
    J->precedence = new_list ( );
    J->posteriority = new_list ( );
    J->rank = UNDEF;
    J->au_plus_tard = UNDEF;
    J->au_plus_tot = UNDEF;
    J->marge_totale = UNDEF;
    J->critique = false;
    return J;
}
job_t * new_job ( char * title ) {
    job_t * J = new_empty_job ( );
    J->title = strdup ( title );
    return J;
}
void free_job(job_t ** ptrJ ) {
    assert ( ptrJ && *ptrJ );
    if( (*ptrJ)->title ) free ( (*ptrJ)->title );
    free ( *ptrJ );
    *ptrJ = NULL;
}

void view_job ( job_t * J ) {
    printf ( "JOB %s\n\tpreceeded by [", get_job_tilte ( J ) );
    for(list_elm_t * E = get_head ( J->precedence ); E; E = get_suc ( E ) ) {
        printf ( " %s", get_job_tilte ( get_data ( E ) ) );
    }
    printf ( " ]\n" );
    // if ( !get_numelm ( J->posteriority ) ) printf ( "\t" );
    printf ( "\tfollowed by [" );
    for(list_elm_t * E = get_head(J->posteriority); E; E = get_suc(E)){
        printf(" %s", get_job_tilte(get_data(E)));
    }
    printf ( " ]\n" );
    printf ( "\tiDeg=%d\toDeg=%d\tlife=%2.2lf", J->input_degree, J->output_degree, J->life );
    printf ( "\trank=" );
    if ( J->rank == UNDEF ) printf ( "U" ); else printf ( "%d", J->rank );
    printf ( "\tearly=" );
    if(J->au_plus_tot == UNDEF ) printf("U"); else printf ( "%2.2lf",J->au_plus_tot );
    printf ( "\tlate=" );
    if(J->au_plus_tard == UNDEF ) printf("U"); else printf ( "%2.2lf",J->au_plus_tard );
    printf ( "\ttotale= " );
    if ( J->marge_totale == UNDEF ) printf("U"); else printf ( "%2.2lf", J->marge_totale );
    printf ( "\tlibre= " );
    if ( J->marge_libre == UNDEF ) printf("U"); else printf ( "%2.2lf", J->marge_libre );
    printf ( "\tcritical= " );
    if ( J->critique ) printf("Y\n"); else printf ( "N\n" );
}

char * get_job_tilte(job_t * J){
    assert(J);
    return J->title;
}
void set_job_title(job_t * J, char * title){
    assert(J);
    J->title = title;
}

double get_job_life(job_t * J){
    assert(J);
    return J->life;
}
void set_job_life(job_t * J, double life){
    assert(J);
    J->life = life;
}

int get_job_iDegree(job_t * J){
    assert(J);
    return J->input_degree;
}
void set_job_iDegree(job_t * J, int iDegree){
    assert(J);
    J->input_degree = iDegree;
}
void incr_job_iDegree(job_t * J){
    assert(J);
    J->input_degree++;
}
void decr_job_iDegree(job_t * J){
    assert(J);
    J->input_degree--;
}

int get_job_oDegree(job_t * J){
    assert(J);
    return J->output_degree;
}
void set_job_oDegree(job_t * J, int iDegree){
    assert(J);
    J->output_degree = iDegree;
}
void incr_job_oDegree(job_t * J){
    assert(J);
    J->output_degree++;
}
void decr_job_oDegree(job_t * J){
    assert(J);
    J->output_degree--;
}

int get_job_rank(job_t * J){
    assert(J);
    return J->rank;
}
void set_rank(job_t * J, int rank){
    assert(J);
    J->rank = rank;
}

int titleJobCmp(job_t * J1, job_t * J2){
    assert(J1 && J2);
    return strcmp(J1->title,J2->title);
}

int iDegreeJobCmp(job_t * J1, job_t * J2){
    assert(J1 && J2);

    if(J1->input_degree > J2->input_degree){
        return 1;
    }
    else{
        if(J1->input_degree == J2->input_degree){
            return 0;
        }
        else{
            return -1;
        }
    }
}

int oDegreeJobCmp(job_t * J1, job_t * J2){
    assert(J1 && J2);

    if(J1->output_degree > J2->output_degree){
        return 1;
    }
    else{
        if(J1->output_degree == J2->output_degree){
            return 0;
        }
        else{
            return -1;
        }
    }
}

int rangJobCmp(job_t *J1, job_t * J2){
    if(J1->rank > J2->rank){
        return 1;
    }
    else{
        if(J1->rank == J2->rank){
            return 0;
        }
        else{
            return -1;
        }
    }
}

//fonction ajouter pour le sous programme marges

double get_job_tot(job_t * J){
    assert(J);
    return J->au_plus_tot;
}
double get_job_tard(job_t * J){
    assert(J);
    return J->au_plus_tard;
}

double max_tot_life (list_t * G){

    double max = 0.00;
    if (!is_empty(G)){
        list_elm_t * aux = G->head;
        job_t * j = aux->data;
        max = j->au_plus_tot + j->life;
        aux = aux->suc;
        while (aux != NULL){
            j = aux->data;
            if(max < j->au_plus_tot + j->life){
                max = j->au_plus_tot + j->life;
            }
            aux = aux->suc;
        }
    }
    return max;
}

double min_tard (list_t * G){
    if (!is_empty(G)){
        list_elm_t * aux = G->head;
        job_t * j = aux->data;
        double min = get_job_tard(j);
        aux = aux->suc;
        while (aux != NULL){
            j = aux->data;
            if(min > j->au_plus_tard){
                min = j->au_plus_tard;
            }
            aux = aux->suc;
        }
        return min;
    }
    else{
        return 0;
    }
}

double min_tot (list_t * G){
    if (!is_empty(G)){
        list_elm_t * aux = G->head;
        job_t * j = aux->data;
        double min = get_job_tot(j);
        aux = aux->suc;
        while (aux != NULL){
            j = aux->data;
            if(min > j->au_plus_tot){
                min = j->au_plus_tot;
            }
            aux = aux->suc;
        }
        return min;
    }
    else{
        return 0;
    }
}