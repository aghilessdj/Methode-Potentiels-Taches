#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "elmlist.h"

list_elm_t * new_list_elm (void * data){

    list_elm_t * L = calloc(1,sizeof(list_elm_t));
    L->data = data;
    L->suc = NULL;
    L->pred = NULL;

    return L;
}

void del_list_elm(list_elm_t * E, void (*ptrf) ()){
    assert(ptrf && E);

    (*ptrf) (E->data);
    (*ptrf) (E->suc);
    (*ptrf) (E->pred);

    (*ptrf) (E);
    E = NULL;
}

list_elm_t * get_suc ( list_elm_t * E ){
    assert(E);
    return E->suc;
}

list_elm_t * get_pred ( list_elm_t * E ){
    assert(E);
    return E->pred;
}

void * get_data ( list_elm_t * E ){
    assert(E);
    return E->data;
}

void set_suc ( list_elm_t * E, list_elm_t * S ){
    assert(E && S);

    E->suc = S;
}

void set_pred ( list_elm_t * E, list_elm_t * P ){
    assert(E && P);

    E->pred = P;
}

void set_data ( list_elm_t * E, void * data ){
    assert(E && data);

    E->data = data;
}

void view_list_elm ( list_elm_t * E, void (* ptrf)() ){
    assert(E && E->data);

    (* ptrf) (E->data);
}