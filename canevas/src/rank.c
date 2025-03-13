#include <stdio.h>
#include <stdlib.h>
#include "elmlist.h"
#include "job_1.h"
#include "job_2.h"
#include "job_3.h"
#include "list_1.h"
#include "list_2.h"
#include "io.h"

int max_rank (list_t * G){
    int max = 0;
    list_elm_t * aux = G->head;
    while (aux != NULL){
        if(get_job_rank(aux->data) > max){
            max = get_job_rank(aux->data);
        }
        aux = aux->suc;
    }
    return max;
}

void ranking(list_t * G){

    list_elm_t * aux = G->head;
    job_t * J;

    while(aux != NULL){
        J = aux->data;
        if(is_empty(J->precedence)){
            J->rank = 0;
            aux = aux->suc;
            J = aux->data;
        }
        else{
            list_elm_t * current = get_head(J->precedence);
            while(current != NULL){
                if(get_job_rank(current->data) == UNDEF){
                    aux = aux->suc;
                    J = aux->data;
                    current = get_head(J->precedence);
                }
                current = current->suc;
            }
            J->rank = 1 + max_rank(J->precedence);
            aux = aux->suc;
        }
    }

    aux = G->head;
    while(aux != NULL){
        J = aux->data;
        if(is_empty(J->precedence)){
            J->rank = 0;
            aux = aux->suc;
            J = aux->data;
        }
        else{
            list_elm_t * current = get_head(J->precedence);
            while(current != NULL){
                if(get_job_rank(current->data) == UNDEF){
                    aux = aux->suc;
                    J = aux->data;
                    current = get_head(J->precedence);
                }
                current = current->suc;
            }
            J->rank = 1 + max_rank(J->precedence);
            aux = aux->suc;
        }
    }
    
    quick_sort(G,&rangJobCmp);
    
}

void prune(list_t * G){
    printf("TODO");
}

void marges(list_t * G){
    printf("TODO");
}