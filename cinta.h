#ifndef CINTA_H
#define CINTA_H

#include "bool.h"
#include "tcalpha.h"  /*aca se definen las funciones tcalpha_***   */


typedef struct celda *aList;
typedef struct scinta *cinta;

aList
aList_vacia(void);

cinta
cinta_create(aList l);

void
cinta_arr(cinta c);

bool
cinta_fin(cinta c);

void
cinta_av(cinta c);

tcalpha
cinta_elec(cinta c);

/*generamos un tcalpha_clone, por lo que se genera memoria nueva*/
void
cinta_ins(cinta c, tcalpha t);

void
cinta_del(cinta c);

aList
cinta_destroy(cinta c);

#endif
