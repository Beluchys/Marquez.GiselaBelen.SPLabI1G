#ifndef ELEMENTOS_H_INCLUDED
#define ELEMENTOS_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}Elemento;

Elemento* element_new();
Elemento* element_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarStr);
Elemento* element_newParametrosNoEsStr(int id, char* nombre, int vac1dosis, int vac2dosis, int sinVacunar);
void element_delete();

int element_SetId(Elemento* this,int id);
int element_GetId(Elemento* this,int* id);
int element_SetNombre(Elemento* this,char* nombre);
int element_GetNombre(Elemento* this,char* nombre);
int element_SetDatoUno(Elemento* this,int vac1dosis);
int element_GetDatoUno(Elemento* this,int* vac1dosis);
int element_SetDatoDos(Elemento* this,int vac2dosis);
int element_GetDatoDos(Elemento* this,int* vac2dosis);
int element_SetDatoTres(Elemento* this,int sinVacunar);
int element_GetDatoTres(Elemento* this,int* sinVacunar);

#endif // ELEMENTOS_H_INCLUDED
