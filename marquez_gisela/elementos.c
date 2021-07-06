#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elementos.h"
#include "LinkedList.h"
#include "validaciones_marquez.h"
#include "control.h"

Elemento* element_new()
{
    Elemento* newElement;
    newElement = (Elemento*) calloc(sizeof(Elemento), 1);

    if (newElement != NULL)
    {
        newElement->id = 0;
        strcpy(newElement->nombre, " ");
        newElement->vac1dosis = 0;
        newElement->vac2dosis = 0;
        newElement->sinVacunar = 0;
    }
    return newElement;
}
//---------------------------------------------------------------------------------
Elemento* element_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarStr)
{
    Elemento *newElement;
    newElement = element_new();

    int auxId;
    int auxDatoUno;
    int auxDatoDos;
    int sinVacunar;

    auxId = atoi(idStr);
    auxDatoUno = atoi(vac1dosisStr);
    auxDatoDos = atoi(vac2dosisStr);
    sinVacunar = atoi(sinVacunarStr);

    if (newElement != NULL && idStr != NULL && nombreStr != NULL && vac1dosisStr != NULL && vac2dosisStr != NULL && sinVacunarStr != NULL)
    {
        element_SetId(newElement, auxId);
        element_SetNombre(newElement, nombreStr);
        element_SetDatoUno(newElement, auxDatoUno);
        element_SetDatoDos(newElement, auxDatoDos);
        element_SetDatoTres(newElement, sinVacunar);
    }
    return newElement;
}
//---------------------------------------------------------------------------------
Elemento* element_newParametrosNoEsStr(int id, char* nombre, int datoUno, int datoDos, int datoTres)
{
    Elemento* newElement = element_new();

    if(newElement!=NULL)
    {
        element_SetId(newElement, id);
        element_SetNombre(newElement, nombre);
        element_SetDatoUno(newElement, datoUno);
        element_SetDatoDos(newElement, datoDos);
        element_SetDatoTres(newElement, datoTres);
    }

    return newElement;
}
//---------------------------------------------------------------------------------
void element_delete(Elemento* this)
{
    if (this != NULL)
    {
        free(this);
    }
}
//---------------------------------------------------------------------------------
// FUNCIONES ID //

int element_SetId(Elemento* this,int id)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (id >= 0)
        {
            this->id = id;
            todoOk = 1;
        }
    }
    return todoOk;
}

int element_GetId(Elemento* this,int* id)
{
    int todoOk = 0;

    if (this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;

}

//  FUNCIONES NOMBRE

int element_SetNombre(Elemento* this,char* nombre)
{
    int todoOk = 0;

    if (this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int element_GetNombre(Elemento* this,char* nombre)
{
    int todoOk = 0;

    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

//FUNCIONES DATO UNO
int element_SetDatoUno(Elemento* this,int datoUno)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (datoUno >= 0)
        {
            this->vac1dosis = datoUno;
            todoOk = 1;
        }
    }
    return todoOk;

}


int element_GetDatoUno(Elemento* this,int* datoUno)
{
    int todoOk = 0;

    if (this != NULL && datoUno != NULL)
    {
        *datoUno = this->vac1dosis;
        todoOk = 1;
    }
    return todoOk;
}

// FUNCIONES DATO DOS
int element_SetDatoDos(Elemento* this,int datoDos)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if(datoDos>=0)
        {
            this->vac2dosis = datoDos;
            todoOk = 1;
        }
    }
    return todoOk;
}
int element_GetDatoDos(Elemento* this,int* datoDos)
{
    int todoOk = 0;

    if (this != NULL && datoDos != NULL)
    {
        *datoDos = this->vac2dosis;
        todoOk = 1;
    }
    return todoOk;
}


// FUNCIONES DATO TRES
int element_SetDatoTres(Elemento* this,int datoTres)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if(datoTres>=0)
        {
            this->sinVacunar = datoTres;
            todoOk = 1;
        }
    }
    return todoOk;
}
int element_GetDatoTres(Elemento* this,int* datoTres)
{
    int todoOk = 0;

    if (this != NULL && datoTres != NULL)
    {
        *datoTres = this->sinVacunar;
        todoOk = 1;
    }
    return todoOk;
}
