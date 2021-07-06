#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "elementos.h"
#include "parser.h"

int parser_ObjectFromText(FILE *pFile, LinkedList *this) {
	Elemento *pObject;
	char auxID[128];
	char pais[128];
	char datoUno[128];
	char datoDos[128];
	char datoTres[128];

	int success = 0;
	int firstElement = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, pais, datoDos, datoUno, datoTres);
				firstElement = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, pais, datoDos, datoUno, datoTres);
			pObject = element_newParametros(auxID, pais,datoDos, datoUno,datoTres);

			if (pObject != NULL) {
				ll_add(this, pObject);
				success = 1;
			}
		}
	}
	return success;
}

