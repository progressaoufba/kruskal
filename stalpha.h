#ifndef STALPHA_H
#define STALPHA_H

#include <stdlib.h>
#include "arista.h"
/*en nuestro caso usamos*/
typedef arista stalpha;

/*clonamos elementos*/
stalpha
stalpha_clone(const stalpha a);


/*destruimos elementos*/
void
stalpha_destroy(stalpha a);

#endif
