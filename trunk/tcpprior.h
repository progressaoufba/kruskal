#ifndef TCPPRIOR_H
#define TCPPRIOR_H

/*ESTAMOS USANDO alpha_menor, dentro del heap
  NO SIRVEDE NADA ESTA COSA */
#include <stdlib.h>
#include "bool.h"
#include "tcpalpha.h"





typedef int tcpprior; /*en este caso es el peso*/


tcpprior /*devuelve el peso*/
alfa_prior(const tcpalpha elem);


/*determina la prioridad del peso, return x<y*/
bool
prior_ord(const tcpprior x, const tcpprior y);


#endif
