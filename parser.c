#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	/*int r;
		int id, horasTrabajadas;
		float salario;
		char *nombre;
		nombre = (char*)malloc(120*sizeof(char));
		if(nombre!=NULL)
		{
			pFile = fopen(path, "r");
			if(pFile == NULL)
			{
			printf("El archivo no existe");
			exit(EXIT_FAILURE);
			}
			do
			{
				r = fscanf(pFile,"%d,%[^,],%d,%f\n",&id,nombre,&horasTrabajadas,&salario);
			if(r==4)
			{
				if(id>=0 && nombre!=NULL && horasTrabajadas>=0 && salario >=0)
				printf("Lei %d,%s,%d,%f\n",id,nombre,horasTrabajadas,salario);
			}
			else
			{
				printf("se rompio");
				break;
			}
			}
			while(!feof(pFile));
		}*/

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
