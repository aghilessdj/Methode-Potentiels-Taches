#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "elmlist.h"
#include "list_1.h"
#include "job_1.h"
#include "rank.h"

list_t * read_graph ( char * filename );

void quick_sort(list_t * L, int (*cmpFct)());