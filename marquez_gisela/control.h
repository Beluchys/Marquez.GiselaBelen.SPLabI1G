#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED
#include "elementos.h"

int filtroPaisExitoso(void*cantidad);
int controller_saveAsText(char* path, LinkedList* pArraysElement);
int filtroPaisAlHorno(void*cantidad);
int element_OrdenarPorVacunados(void * dosisUno, void *dosisDos);
int mostrarPais(Elemento* this);
int menuOpciones();
int controller_ListObject(LinkedList *this);
void* setDatoUno(void*datoUno);
int getRandomDatoUno(void);
void* setDatoDos(void* datoDos);
int getRandomDatoDos(void);
void* setDatoTres(void* datoTres);
int getRandomDatoTres(void);


#endif // CONTROL_H_INCLUDED
