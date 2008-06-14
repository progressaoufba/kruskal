#ifndef CINTWAR_H
#define CINTWAR_H

#include "arista.h"

typedef struct scintwar *cintwar;

cintwar
cwa_create(void); /* constructor */

void
cwa_arr(cintwar cwa); /* arrancar */
/* INFO: es necesario hacer esto para "arrancar" el archivo con "grafo G {" */

void
cwa_insarbol(cintwar cwa, arista a); /* escribe una arista
                                              del arbol generador */
void
cwa_ainsrest(cintwar cwa, arista a); /* escribe una arista
                                              del gafo restante */
cintwar
cwa_destroy(cintwar cwa); /* destructor */
/* INFO: es necesario hacer esto para "cerrar" el archivo con "}" */


#endif
