#include "tcpprior.h"

tcpprior /*devuelve el peso*/
alfa_prior(const tcpalpha elem){
	return arista_weight(elem);
}

/*determina la prioridad del peso*/
bool
prior_ord(const tcpprior x, const tcpprior y){
	return (x<y);
}
