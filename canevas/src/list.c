#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "elmlist.h"
#include "job_1.h"
#include "list_1.h"

list_t * new_list(){
    //alouer un espace mémoire de taille du type list
    list_t *L=calloc(1,sizeof(list_t));
    //initialiser la tête et le dernier element à NULL
    L->head = NULL;
    L->tail = NULL;
    L->numelm = 0;//initialiser le nombre d'element à 0

    return L;
}

void del_list (list_t ** ptrL,void (*ptrf) ()){
    //supprimer une liste avec la supression de la mémoire alouer
    assert(*ptrL && ptrL && ptrf);
    
    list_elm_t *current = (*ptrL)->head;
    list_elm_t *temp;
    
    while (current) {
        temp = current;
        current = current->suc;
        
        if (ptrf) {
            ptrf(temp->data); // Libérer les données si nécessaire
        }
        
        free(temp); // Libérer le nœud
    }
    
    free(*ptrL);
    *ptrL = NULL;
}

void clean(list_t * L){
    //supprimer les noeud de la list sans supprimer les données (data)
    assert(L);

    list_elm_t *current = L->head;
    list_elm_t *temp;
    
    while (current != NULL) {
        temp = current;
        current = current->suc;
        free(temp);
    }
    
    L->head = NULL;
    L->tail = NULL;
    L->numelm = 0;
}

bool is_empty ( list_t * L ){ // vérifie si la list est vide 
    assert(L);
    return L->numelm == 0;
}

list_elm_t * get_head ( list_t * L ){ // retourne la tête de la list
    assert(L);
    return L->head;
}

list_elm_t * get_tail ( list_t * L ){ // retourne le dernier element d'une liste
    assert(L);
    return L->tail;
}

int get_numelm(list_t * L){ // retoune le nombre d'élément d'une liste
    assert(L);
    return L->numelm;
}

void take_out(list_t *L, void *D) {
    // retirer une donnée d'une liste sans libérer sa mémoire
    assert(L && D);
    
    list_elm_t *current = L->head;
    
    while (current != NULL) {
        if (current->data == D) {
            if (current->pred)
                current->pred->suc = current->suc;
            else
                L->head = current->suc;

            if (current->suc)
                current->suc->pred = current->pred;
            else
                L->tail = current->pred;
            
            L->numelm--;
            return;
        }
        current = current->suc;
    }
}

void cons ( list_t * L, void * data ){
    // ajouter une donnée dans la tête d'une liste
    assert(L);

    if (!L) return;
    
    list_elm_t *new_elem = (list_elm_t *)malloc(sizeof(list_elm_t));
    assert(new_elem); // Vérification de l'allocation
    
    new_elem->data = data;
    new_elem->suc = L->head;
    new_elem->pred = NULL;
    
    if (L->head) {
        L->head->pred = new_elem;
    } else {
        L->tail = new_elem; // Si la liste était vide, le nouvel élément est aussi la queue
    }
    
    L->head = new_elem;
    L->numelm++;
}

void queue ( list_t * L, void * data ){
    // ajouter une donnée à la fin d'une liste
    assert(L);
    
    list_elm_t *new_elem = (list_elm_t *)malloc(sizeof(list_elm_t));
    assert(new_elem); // Vérification de l'allocation
    
    new_elem->data = data;
    new_elem->suc = NULL;
    new_elem->pred = L->tail;
    
    if (L->tail) {
        L->tail->suc = new_elem;
    } else {
        L->head = new_elem; // Si la liste était vide, le nouvel élément est aussi la tête
    }
    
    L->tail = new_elem;
    L->numelm++;// incrémenté le nombre d'element
}

void view_list ( list_t * L, void (*ptrf)() ){
    // Affichage d'une liste
    assert(L && ptrf);
    
    list_elm_t *current = L->head;
    while (current) {
        ptrf(current->data);
        current = current->suc; //incrémentation
    }
}

void ordered_insert ( list_t * L, void * data , int (* cmpFct)() ){
    // insérer une donnée en ordre
    assert(L && cmpFct);
    
    list_elm_t *new_elem = (list_elm_t *)malloc(sizeof(list_elm_t));
    assert(new_elem);
    
    new_elem->data = data;
    new_elem->suc = NULL;
    new_elem->pred = NULL;
    
    if (!L->head) { //Si la liste est vide
        L->head = L->tail = new_elem;
    } else {
        list_elm_t *current = L->head;
        while (current && cmpFct(data, current->data) > 0) {
            current = current->suc;
        }
        
        if (!current) { //Insérer à la fin
            new_elem->pred = L->tail;
            L->tail->suc = new_elem;
            L->tail = new_elem;
        } else if (!current->pred) { //Insérer au début
            new_elem->suc = L->head;
            L->head->pred = new_elem;
            L->head = new_elem;
        } else { //Insérer au milieu
            new_elem->suc = current;
            new_elem->pred = current->pred;
            current->pred->suc = new_elem;
            current->pred = new_elem;
        }
    }
    
    L->numelm++;
}


void find(list_t * L, void ** ptrKey, int (*cmpFct)(), void (*delFct)()) {

    list_elm_t * current = L->head ;

    while (current != NULL) {
        // Comparer l'élément courant avec la clé
        if (cmpFct(current->data, *ptrKey) == 0) {
            delFct(ptrKey);
            *ptrKey = current->data; // Mettre à jour ptrKey pour pointer vers l'élément trouvé
            return; // Élément trouvé, on quitte la fonction
        }
        current = current->suc; // Passer à l'élément suivant
    }
    // Si l'élément n'a pas été trouvé
    queue (L , *ptrKey );
}
