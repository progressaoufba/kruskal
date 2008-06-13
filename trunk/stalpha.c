#include "stalpha.h"


stalpha
stalpha_clone(const stalpha a){
	arista aux;
	
	aux=arista_clone(a);
	return aux;
}


/*destruimos elementos*/
void
stalpha_destroy(stalpha a){
	a=arista_destroy(a);
	a=NULL;
}
