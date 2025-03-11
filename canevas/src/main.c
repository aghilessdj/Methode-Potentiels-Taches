#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "elmlist.h"
#include "list_1.h"
#include "list_2.h"
#include "job_1.h"
#include "job_2.h"
#include "job_3.h"
#include "rank.h"
#include "io.h"

int main(int argc, char ** argv){

    if(argc < 2) exit(-1);

    printf("Ar dagi telha %s\n",argv[1]);

    list_t * G = read_graph(argv[1]);

    printf("Hello\n\n");

    printf("Liste des tÃ¢ches lue\n");
    view_list(G, &view_job);

    printf("Liste des tÃ¢ches triÃ©e par degrÃ© d'entrÃ©e croissant\n");
    quick_sort(G, &iDegreeJobCmp);
    view_list(G,&view_job);

    printf("Liste des tÃ¢ches triÃ©e par rang croissant\n");
    ranking(G);
    view_list(G,&view_job);

    printf("Prune edges\n");
    prune(G);
    view_list(G,&view_job);

    printf("\nMarges totales des tÃ¢ches\n");
    marges(G);
    view_list(G,&view_job);
    return 0;
}