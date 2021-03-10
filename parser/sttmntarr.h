#ifndef STTMNTARR_H
#define STTMNTARR_H

#include "node.h"

typedef struct sttmntarr {
    unsigned int size;
    unsigned int count;
    struct statement* statement_arr;
} sttmntarr ;

void sttmntarr_construct(struct sttmntarr* sarr);
void sttmntarr_add(struct sttmntarr* sarr, struct statement el);

#endif