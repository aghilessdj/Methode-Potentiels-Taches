#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "elmlist.h"
#include "job_1.h"
#include "list_1.h"
#include "io.h"

// Dans les fonctions suivantes on a suposé que la liste G n'est pas vide

void ranking(list_t * G){
    // Calcule des ranks des jobs de la liste
    list_elm_t * aux = G->head;
    job_t * J;
    bool undef = true;
 
    while (undef){// Tant qu'il y a un job qui n'a pas encore un rang
        undef = false;
        while(aux != NULL){
            J = aux->data;
            if(is_empty(J->precedence)){// Si le job n'a pas de tâches précédentes
                J->rank = 0;// Son rang est 0
                aux = aux->suc;// Aller vers l'élément suivant
                J = aux->data;
            }
            else{ // Le job a des tâches précédentes
                list_elm_t * current = get_head(J->precedence);
                while(current != NULL){// parcour la liste des tâches précédentes
                    if(get_job_rank(current->data) == UNDEF){// Si il y a un job qui n'a pas de rang dans cette liste de taches précédentes
                        aux = aux->suc;// aller ver le job suivant dans la liste principale
                        J = aux->data;
                        if(is_empty(J->precedence)){// Si le job n'a pas de tâches précédentes
                            J->rank = 0;
                            aux = aux->suc;
                            J = aux->data;
                        }
                        current = get_head(J->precedence);
                        undef = true;// on a laisser un job qui n'a pas encore de rang
                    }
                    current = current->suc; // l'élément suivant dans la liste des précédentes
                }
                J->rank = 1 + max_rank(J->precedence); //Le rang du job est le max des rangs de ses précédents + 1
                aux = aux->suc;// Aller vers l'élément suivant
            }
        }
        aux = G->head;// On retourne vers le début de la liste
    }
    quick_sort(G,&rangJobCmp);// trier la liste par rang croissant
}

void prune(list_t * G){
    // Supprime les arcs inutils
    list_elm_t * aux = G->head;
    job_t * J;
    list_elm_t * tmp;

    while(aux != NULL){ // Tanque la liste n'est pas vide
        J = aux->data;
        tmp = get_head(J->precedence);
        while (tmp != NULL){
            if(get_job_rank(aux->data) - get_job_rank(tmp->data) > 1){// Si la différence rang entre le job et son job précédent est supérieur à 1
                job_t * J1 = aux->data , * J2 = tmp->data;
                take_out(J1->precedence , tmp->data);// enlever le job des précédent
                set_job_iDegree(J1 , get_job_iDegree(J1)-1);
                take_out(J2->posteriority , aux->data);// Enlever le job des taches qui suivent
                set_job_oDegree(J2 , get_job_oDegree(J2)-1);
                printf("edge [ %s---------->%s ] is pruned from G\n",get_job_tilte(tmp->data),get_job_tilte(aux->data));// Afficher l'arc supprimer
            }
            tmp = tmp->suc;
        }
        aux = aux->suc;
    }
}


void marges(list_t * G){
    // Calcule dates plus tôt, dates plus tard, marges totales et libres et chemin critique 
    job_t * A = new_job("alpha") , * O = new_job("omega");
    list_elm_t * head = G->head , * tail = G->tail;
    job_t * J;
    A->rank = -1;
    A->au_plus_tot = 0;
    O->rank = max_rank(G)+1;
 
    cons(G , A);// Ajouter 'alpha' A au début de la liste
    queue(G , O);// Ajouter 'omega' O à la fin de la liste
    
    while(head != NULL){// Attacher les jobs qui n'ont pas de tâches précédentes avec A
        J = head->data;
        if(get_job_rank(J) == 0){
            cons(J->precedence , A);
            A->output_degree ++;
            cons(A->posteriority , get_data(head));
            set_job_iDegree(get_data(head) , get_job_iDegree(get_data(head))+1);
        }
        head = head->suc;
    }

    while(tail != NULL){// Attacher les jobs qui n'ont pas de tâches suivantes avec O
        J = tail->data;
        if(get_job_rank(J) == max_rank(G)-1){
            cons(O->precedence , get_data(tail));
            O->input_degree ++;
            cons(J->posteriority , O);
            set_job_oDegree(get_data(tail) , get_job_oDegree(get_data(tail))+1);
        }
        tail = tail->pred;
    }
    
    head = get_suc(G->head);
    tail = G->tail;

    job_t * j;
    while(head != NULL){// Calcule les dates plus tôt
        j = head->data;
        j->au_plus_tot = max_tot_life(j->precedence);
        head = head->suc;
    }

    job_t * t = tail->data;
    t->au_plus_tard = t->au_plus_tot; 
    tail = tail->pred;
    while(tail != NULL){// Calcule les dates plus tard
        j = tail->data;
        j->au_plus_tard = min_tard(j->posteriority) - j->life;
        tail = tail->pred;
    }

    // calcule des marges (libre et totale)
    t->marge_libre = 0;
    t->marge_totale = 0;// La marge du dernier element est 0
    t->critique = true;
    tail = get_pred(G->tail);
    while (tail != NULL){// on fait une boucle à partir du dernier element de la list
        // calcule des marge du job de l'élément
        j = tail->data;
        j->marge_totale = j->au_plus_tard - j->au_plus_tot;
        j->marge_libre = min_tot(j->posteriority) - j->au_plus_tot - j->life;

        // Le chemin critique
        if ((j->marge_libre == 0) && (j->marge_libre == j->marge_totale)){
            j->critique = true;
        }
        else{
            j->critique = false;
        }
        tail = tail->pred;// Passer à l'élément suivant
    }
}