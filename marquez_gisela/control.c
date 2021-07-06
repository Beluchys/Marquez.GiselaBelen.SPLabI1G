#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "elementos.h"
#include "validaciones_marquez.h"
#include "parser.h"

//MENUS
int menuOpciones()
{
    int opcion=-1;
    printf("    -----------------------  MENU PRINCIPAL  -----------------------\n");
    printf("    ----------------------------------------------------------------\n");
    printf("1- Cargar archivo y Asignarle un Nombre.\n");
    printf("2- Imprimir lista.\n");
    printf("3- Asignar estadísticas.\n");
    printf("4- Filtrar por países exitosos.\n");
    printf("5- Filtrar por países en el horno.\n");
    printf("6- Ordenar por nivel de vacunación.\n");
    printf("7- Mostrar más castigado.\n");
    printf("8- Salir.\n");
    printf("    ----------------------------------------------------------------\n");

    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 8, 3);
    return opcion;
}



//-------------------------------------------------------------------
/** \brief Carga los datos de los Alumnos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArraysElement LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArraysElement)
{
    int todoOk = -1;
    FILE* f = NULL;

    if(path!=NULL && pArraysElement!=NULL)
    {
        f = fopen(path,"r");
        if(f != NULL)
        {
            parser_ObjectFromText(f, pArraysElement);
            todoOk = 1;
            fclose(f);
        }
    }
    return todoOk;
}

int listar_element(LinkedList* pArraysElement)
{
    int todoOk = 0;

    if(pArraysElement != NULL)
    {
        system("cls");
        printf("----------------------------------------------------------------------\n");
        printf("   ID         PAIS      VAC_1_DOSIS    VAC_2_DOSIS     VAC_2_DOSIS\n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0; i<ll_len(pArraysElement); i++)
        {
            mostrarPais((Elemento*) ll_get(pArraysElement, i));
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}
// MOSTRAR UN PAIS
int mostrarPais(Elemento* this)
{
    int retorno = 0;
    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int vac3dosis;

    if(this!=NULL &&
            element_GetId(this, &id) &&
            element_GetNombre(this, nombre) &&
            element_GetDatoUno(this, &vac1dosis) &&
            element_GetDatoDos(this, &vac2dosis) &&
            element_GetDatoTres(this, &vac3dosis))
    {
        printf(" %4d   %16s     %8d     %8d       %8d\n",id,nombre,vac1dosis,vac2dosis,vac3dosis);
        retorno=1;
    }
    return retorno;
}

int filtroPaisExitoso(void*cantidad)
{
    int exito = 0;
    int sinVacunar;

    Elemento* exitoso;

    if(cantidad!=NULL)
    {
        exitoso = (Elemento*)cantidad;
        element_GetSinVacunar(exitoso, &sinVacunar);
        if(sinVacunar<5000)
        {
            exito = 1;
        }
    }

    return exito;
}

int element_GetSinVacunar(Elemento *this, int *sinVacunar)
{
    int success = 0;

    if (this != NULL && sinVacunar != NULL)
    {
        *sinVacunar = this->sinVacunar;
        success = 1;
    }
    return success;
}

int controller_ListObject(LinkedList *this)
{
    Elemento *pObject;
    int sucess = 0;
    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

    if (this != NULL)
    {
        printf("----------------------------------------------------------------------\n");
        printf("   ID         PAIS      VAC_1_DOSIS    VAC_2_DOSIS     VAC_2_DOSIS\n");
        printf("----------------------------------------------------------------------\n");
        sucess = 1;

        for (int i = 0; i < ll_len(this); i++)
        {
            pObject = ll_get(this, i);
            element_GetId(pObject, &id);
            element_GetDatoUno(pObject, &vac1dosis);
            element_GetDatoDos(pObject, &vac2dosis);
            element_GetDatoTres(pObject, &sinVacunar);
            element_GetNombre(pObject, nombre);
            printf("    [%3d] [%-10s] [%07d] [%07d] [%07d]  \n", id, nombre, vac1dosis, vac2dosis, sinVacunar);
        }
    }
    return sucess;
}



void* setDatoUno(void*datoUno)
{
	Elemento* aux = NULL;

	if(datoUno!=NULL){
		aux = (Elemento*)datoUno;
		element_SetDatoUno(aux, getRandomDatoUno());

	}
	return aux;
}
int getRandomDatoUno(void)
{
	int aleatorio;

	aleatorio = (rand()% 60) + 1000;

	return aleatorio;
}

void* setDatoDos(void* datoDos)
{
	Elemento* aux = NULL;

	if(datoDos!=NULL){
		aux = (Elemento*)datoDos;
		element_SetDatoDos(aux, getRandomDatoDos());

	}
	return aux;
}
int getRandomDatoDos(void)
{
	int aleatorio;

	aleatorio = (rand()% 40) + 40000;

	return aleatorio;
}


void* setDatoTres(void* datoTres)
{
	Elemento* aux = NULL;

	if(datoTres!=NULL){
		aux = (Elemento*)datoTres;
		element_SetDatoTres(aux, getRandomDatoTres());
	}
	return aux;
}

int getRandomDatoTres(void)
{
	int aux;

	aux = (rand()% 9000) + 40000;

	return aux;
}


int controller_saveAsText(char* path, LinkedList* pArraysElement)
{
    int todoOk=-1;
    int id;
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
    char nombre[128];

    Elemento* aux = NULL;

    FILE* f = NULL;

    if(path!=NULL && pArraysElement!=NULL)
    {
        f = fopen(path, "w");
        if(f ==NULL)
        {
            todoOk = 0;
        }
        else
        {
            fprintf(f, "id,nombre,vac1dosis,vac2dosis,sinVacunar\n");
            for(int i=0; i < ll_len(pArraysElement); i++)
            {
                aux = (Elemento*) ll_get(pArraysElement, i);
                if(aux!=NULL &&
                        element_GetId(aux, &id) &&
                        element_GetNombre(aux, nombre) &&
                        element_GetDatoUno(aux, &vac1dosis) &&
                        element_GetDatoDos(aux, &vac2dosis)&&
                        element_GetDatoTres(aux, &sinVacunar)
                  )
                {
                    fprintf(f, "%d,%s,%d,%d,%d\n", id,nombre,vac1dosis,vac2dosis,sinVacunar);
                }
            }
            todoOk = 1;
            fclose(f);
        }
    }
    return todoOk;

}

int filtroPaisAlHorno(void*cantidad)
{
    int success = 0;
    int vac1dosis;
    int sinVacunar;

    Elemento* alHorno;
    if(cantidad!=NULL)
    {
        alHorno = (Elemento*)cantidad;
        element_GetDatoTres(alHorno, &sinVacunar);
        element_GetDatoUno(alHorno, &vac1dosis);
        if(sinVacunar >= (vac1dosis*3))
        {
            success = 1;
        }
    }

    return success;
}

int element_OrdenarPorVacunados(void * dosisUno, void *dosisDos)
{
    int dosis_a;
    int dosis_b;
    int success = 0; // si los tiempos son iguales, devuelve 0

    element_GetDatoUno(dosisUno, &dosis_a);
    element_GetDatoUno(dosisDos, &dosis_b);

    if (dosis_a > dosis_b)
    {
        success = 1;
    }
    else if (dosis_a < dosis_b)
    {
        success = -1;
    }
    return success;
}


LinkedList* masCastigado(LinkedList* this)
{
    LinkedList* mappList = NULL;
    Elemento* pElement = NULL;

    int cantidadSinVacunar;
    int cantidadMayor;
    int flag = 0;
    char nombrePais[128];

    if(this==NULL)
    {
        printf("La lista esta vacia.\n");
    }
    else
    {
        mappList = ll_newLinkedList();
        for(int i = 0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            element_GetDatoTres(pElement, &cantidadSinVacunar);
            if(!flag || cantidadSinVacunar > cantidadMayor)
            {
                cantidadMayor = cantidadSinVacunar;
                element_GetNombre(pElement, nombrePais);
                flag = 1;
            }
        }
        printf("El mayor numero sin vacunar es: %d\n",cantidadMayor);
        printf("El Pais mas castigado es: %s\n",nombrePais);
        printf("Como se puede observar debajo.\n");

        pElement = NULL;
        for(int i = 0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            element_GetDatoTres(pElement, &cantidadSinVacunar);
            if(cantidadSinVacunar==cantidadMayor)
            {
                ll_add(mappList, pElement);
            }
        }
    }
    return mappList;
}
