#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "elmlist.h"
#include "list_1.h"
#include "list_2.h"
#include "job_1.h"
#include "job_2.h"
#include "job_3.h"
#include "rank.h"
#include "io.h"

void partition(list_t * L,list_elm_t * pivot,list_t * val_inf_pivot,list_t * val_sup_pivot,int (*cmpFct)()){
    printf("Aghiles");
}

list_t * read_graph ( char * filename ) {
    FILE * fd = fopen ( filename, "rt" );
    list_t * G = new_list ( );
    assert ( fd && G );
    char job_name [ BUFSIZ ];

    while ( !feof ( fd ) ) {

        fscanf ( fd, " %s", job_name);
        if ( !strcmp (job_name, "NIL" ) ) continue;

        job_t * J = new_job ( job_name );

	/**  @note
	    À l'appel J pointe sur le job que l'on vient de créer.
	    
	    FIND retrouve le job J dans la liste G des jobs grâce à la fonction titleJobCmp.
	    Si ce job n'est pas dans la liste G alors
	        le job pointé par J est enregistré dans G
	    Si ce job est déjà dans G alors
	        le job pointé par J est supprimé grâce à free_job
		puis le pointeur de J est réassigné sur le job trouvé dans G
	 */
	find ( G, ( void ** ) &J, &titleJobCmp, &free_job );

	fscanf ( fd, "%lf", &(J->life) );

	/** @note
	    Enregistrement des préséances
	*/
	job_t * predJ;
	fscanf( fd, " %s", job_name );
	while ( strcmp ( job_name, "NIL" ) ) {
	  predJ = new_job ( job_name );
    
	  find ( G, (void **) &predJ, &titleJobCmp, &free_job );

	  ordered_insert ( predJ->posteriority, J, &titleJobCmp );
	  incr_job_oDegree ( predJ );

	  ordered_insert ( J->precedence, predJ, &titleJobCmp );
	  incr_job_iDegree ( J );

	  fscanf ( fd, " %s", job_name );
	}
	
	/** @note valeurs par défaut des autres champs */
        J->dyn_input_degree = J->input_degree;
        J->rank = UNDEF;
        J->au_plus_tard = UNDEF;
        J->au_plus_tot = UNDEF;
        J->marge_totale = UNDEF;
        J->critique = false;
    }

    view_list(G,&view_job);
    return G;
}

void quick_sort(list_t * L, int (*cmpFct)()){
    assert(L && cmpFct);

    if(L->numelm > 1){
        list_elm_t * pivot = get_head(L);
        L->head = get_suc(pivot); // reste(L)
        pivot->pred = NULL;
        pivot->suc = NULL;

        list_t * val_inf_pivot = new_list();
        list_t * val_sup_pivot = new_list();

        partition(L,pivot,val_inf_pivot,val_sup_pivot,cmpFct);
        
        /// On supprimer les éléments de L sans supprimer ni L ni les jobs
        list_elm_t * S;
        for(list_elm_t * E = L->head; E; E = S){
            S = E->suc;
            free(E);
        }

        /** @note
         * Si la partie inf est vide alors L commence par le pivot
         * Sinon on tri grâce à cmpFct la partie inf puis on ajoute en queue le pivot
         */
        if(is_empty(val_inf_pivot)){
            L->head = pivot;
            L->tail = pivot;
            L->numelm = 1;
        }else{
            quick_sort(val_inf_pivot,cmpFct);
            L->head = val_inf_pivot->head;
            L->tail = val_inf_pivot->tail;
            L->numelm = val_inf_pivot->numelm;
            pivot->pred= L->tail;
            L->tail->suc = pivot;
            L->tail = pivot;
            L->numelm += 1;
        }
        /** @note
         * Si la partie sup n'est pas vide alors
         * On la trie puis on la concatène à la partie inf
         */
        if(! is_empty(val_sup_pivot)){
            quick_sort(val_sup_pivot,cmpFct);
            val_sup_pivot->head->pred = pivot;
            set_suc(pivot, val_sup_pivot->head);
            L->tail = val_sup_pivot->tail;
            L->numelm += val_sup_pivot->numelm;
        }
        free(val_inf_pivot);
        free(val_sup_pivot);
    }
}