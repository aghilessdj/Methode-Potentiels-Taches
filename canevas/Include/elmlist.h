#pragma once

typedef struct list_elm {
    void * data;
    struct list_elm * suc , * pred;
} list_elm_t ;

list_elm_t * new_list_elm ( void * data );
/* *
* @brief delete the list element E and optionnaly its datum
* @param ptrf : a ptr to fct that deallocates datum's memory ;
* if ptrf is NULL , datum is not freed
*/
void del_list_elm( list_elm_t * E, void (*ptrf) () );

list_elm_t * get_suc ( list_elm_t * E );
list_elm_t * get_pred ( list_elm_t * E );
void * get_data ( list_elm_t * E );

void set_suc ( list_elm_t * E, list_elm_t * S );
void set_pred ( list_elm_t * E, list_elm_t * P );
void set_data ( list_elm_t * E, void * data );

void view_list_elm ( list_elm_t * E, void (* ptrf)() );