#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "control.h"
#include "validaciones_marquez.h"

int main()
{
    int option = 0;
    char path[128];
    int aux = 0;
    int cargador = 0;
    LinkedList* filtro = NULL;
    LinkedList* masCastigados = NULL;
    LinkedList* lista = NULL;

    filtro = ll_newLinkedList();
    masCastigados = ll_newLinkedList();
    do
    {
        option = menuOpciones();
        switch(option)
        {
        case 1:
            lista = ll_newLinkedList();
            utn_getNombre(path, 128, "Ingrese el nombre del archivo que desea abrir (sin la extension del archivo): \n"
                          "    Prueba con: vacunas: ", "    Nombre incorrecto, reintente.\n", 5);
            strMinuscula(path);
            strcat(path,".csv");
            printf("\n\n El archivo a abrir sera: %s\n",path);
            controller_loadFromText(path, lista);

            system("pause");
            system("cls");

            break;
        case 2:
            listar_element(lista);
            system("pause");
            system("cls");
            break;
        case 3:
            lista = ll_map(lista, setDatoUno);
            lista = ll_map(lista, setDatoDos);
            lista = ll_map(lista, setDatoTres);
            if(listar_element(lista))
            {
                printf("Estadisticas asignadas con exito!.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:

            filtro = ll_filter(lista, filtroPaisExitoso);

            if(listar_element(filtro))
            {
                controller_saveAsText("Exitoso.csv", filtro);
            }
            else
            {
                printf("Hubo un error en la carga.\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            filtro = ll_filter(lista, filtroPaisAlHorno);
            if (listar_element(filtro))
            {
                controller_saveAsText("AlHorno.csv", filtro);
            }
            else
            {
                printf("Hubo un error en la carga.\n");
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if(lista==NULL)
            {
                printf("Error en la Lista.\n");
            }
            else if(!ll_sort(lista, element_OrdenarPorVacunados, 0))
            {
                listar_element(lista);
            }
            system("pause");
            system("cls");
            break;
        case 7:
            masCastigados = masCastigado(lista);
				if(listar_element(masCastigados)){
					printf("Los Paises más castigados.\n\n");
				}
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 8);
    return 0;
}
