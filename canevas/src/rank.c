#include <stdio.h>
#include <stdlib.h>
#include "elmlist.h"
#include "job_1.h"
#include "list_1.h"
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

    list_elm_t * aux = G->head;
    job_t * J;
    list_elm_t * tmp;

    while(aux != NULL){
        J = aux->data;
        tmp = get_head(J->precedence);
        while (tmp != NULL){
            if(get_job_rank(aux->data) - get_job_rank(tmp->data) > 1){
                job_t * J1 = aux->data , * J2 = tmp->data;
                take_out(J1->precedence , tmp->data);
                take_out(J2->posteriority , aux->data);
                printf("edge [ %s---------->%s ] is pruned from G\n",get_job_tilte(tmp->data),get_job_tilte(aux->data));
            }
            tmp = tmp->suc;
        }
        aux = aux->suc;
    }
}


void marges(list_t * G){
    job_t * A = new_job("alpha") , * O = new_job("omega");
    list_elm_t * head = G->head , * tail = G->tail;
    job_t * J;
    A->rank = -1;
    A->au_plus_tot = 0;
    O->rank = max_rank(G)+1;

    cons(G , A);
    queue(G , O);
    
    while(head != NULL){
        J = head->data;
        if(get_job_rank(J) == 0){
            cons(J->precedence , A);
            cons(A->posteriority , get_data(head));
        }
        head = head->suc;
    }

    while(tail != NULL){
        J = tail->data;
        if(get_job_rank(J) == max_rank(G)-1){
            cons(O->precedence , get_data(tail));
            cons(J->posteriority , O);
        }
        tail = tail->pred;
    }
    
    head = get_suc(G->head);
    tail = G->tail;

    job_t * j;
    while(head != NULL){
        j = head->data;

        j->au_plus_tot = max_tot_life(j->precedence);
        head = head->suc;
    }

    job_t * t = tail->data;
    t->au_plus_tard = t->au_plus_tot; 
    tail = tail->pred;
    while(tail != NULL){
        j = tail->data;
        j->au_plus_tard = min_tard(j->posteriority) - j->life;
        tail = tail->pred;
    }


    t->marge_libre = 0;
    t->marge_totale = 0;
    tail = G->tail;
    tail = tail->pred;
    while (tail != NULL){
        j = tail->data;
        j->marge_totale = j->au_plus_tard - j->au_plus_tot;
        j->marge_libre = min_tot(j->posteriority) - j->au_plus_tot - j->life;
        tail = tail->pred;
    }    
}