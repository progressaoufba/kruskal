#ifndef CRA_H
#define CRA_H

#include "arista.h"
#include "bool.h"


typedef struct scintrar *cintrar;

cintrar
cra_create(void); /* constructor */

void
cra_arr(cintrar cra); /* arrancar */

void
cra_av(cintrar cra); /* avanzar */

arista
cra_elec(const cintrar cra); /* elemento corriente */

bool
cra_fin(const cintrar cra); /* fin cinta */

int
cra_vcant(const cintrar cra); /* devuelve la cantidad de vertices */

int
cra_acant(const cintrar cra); /* devuelve la cantidad de aristas */

cintrar
cra_destroy(cintrar cra); /* destructor */


#endif
