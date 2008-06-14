#include "colap.h"

colap
colap_create(const tcppos max) {
	return heap_create(max);
}

void
colap_encolar(colap c, const tcpalpha elem) {
	heap_insert(c,elem);
}

tcpalpha
colap_primero(const colap c) {
	return heap_first(c);
}

void
colap_pop(colap c) {
	heap_pop(c);
}

bool
colap_vacia(const colap c) {
	return heap_vacio(c);
}

bool
colap_llena(const colap c) {
	return heap_lleno(c);
}

tcpalpha
colap_saca(colap c) {
	heap_saca(c);
}

colap
colap_destroy(colap c) {
	return heap_destroy(c);
}

