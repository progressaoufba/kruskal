#include "stalpha.h"


stalpha
stalpha_clone(const stalpha a){
	return arista_clone(a);
}


/*destruimos elementos*/
void
stalpha_destroy(stalpha a){
	a=arista_destroy(a);
	a=NULL;
}
