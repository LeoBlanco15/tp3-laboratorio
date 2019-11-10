#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include"utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	Employee* new = employee_new();
	int r;
	char * id;
	char*horasTrabajadas;
	char* salario;
	char *nombre;
	int idInt, horasTrabajadasInt;
	int salarioFloat;
	nombre = (char*)malloc(120*sizeof(char));
	id = (char*)malloc(120*sizeof(char));
	horasTrabajadas = (char*)malloc(120*sizeof(char));
	salario = (char*)malloc(120*sizeof(char));
	if(nombre!=NULL && id!=NULL && horasTrabajadas!=NULL && salario!=NULL)
	{
		pFile = fopen(path, "r");
		if(pFile == NULL)
		{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
		}
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,horasTrabajadas,salario);
		if(r==4)
		{
			if(esNumerico(id)== 0 && esNumerico(horasTrabajadas)== 0 && esNumerico(salario)== 0)
			{
			idInt = atoi(id);
			horasTrabajadasInt = atoi(horasTrabajadas);
			salarioFloat= atoi(salario);
			new  =  employee_newParametros(idInt,nombre,horasTrabajadasInt, salarioFloat);
			ll_add(pArrayListEmployee, new);
			}
		}
		else
		{
			printf("que mierda le pasa?");
			break;
		}

		}while(!feof(pFile));
	}
	fclose(pFile);
	free(id);
	free(nombre);
	free(horasTrabajadas);
	free(salario);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	Employee* new;
	Employee aux;
	int r;


		pFile = fopen(path, "rb");
		if(pFile == NULL)
		{
			printf("El archivo no existe");
			exit(EXIT_FAILURE);
		}
		while(!feof(pFile))
			{
			r= fread(&aux,sizeof(Employee),1,pFile);
			if(r==1)
			{
				printf("%d \n", aux.id);
				new = employee_new();
				*new = aux;
				ll_add(pArrayListEmployee,new);
			}
			}
		fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* new;
	int id;
	int salario;
	int horasTrabajadas;
	char nombre[50];
	new= employee_new();
	if(new!=NULL)
	{
	id= ll_len(pArrayListEmployee);
	id++;
	printf("%d", id);
	__fpurge(stdin);
	getString(nombre,"\nIngrese nombre: ","Error",1,50,0);
	printf("\nIngrese sueldo: ");
	__fpurge(stdin);
	scanf("%d", &salario);
	printf("\nIngrese horas trabajadas: ");
	__fpurge(stdin);
	scanf("%d",&horasTrabajadas);
	new = employee_newParametros(id,nombre,horasTrabajadas, salario);
	ll_add(pArrayListEmployee,new);
	}
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Node* auxNode;
	Employee* auxE = employee_new();
	char nombre[50];
	int horasTrabajadas;
	int salario;
	int respuesta=0;
	char respuesta2;
	int id;
	int idDos;
	printf("posicion de la lista que desea cambiar: ");
	__fpurge(stdin);
	scanf("%d",&id);
	auxNode=test_getNode(pArrayListEmployee, id);
	if(auxNode!=NULL)
	{
		auxE = auxNode->pElement;
		printf("\n used esta a punto de cambiar al usuario: %d"
				"\n esta seguro que quiere hacerlo? y/n", auxE->id);
		__fpurge(stdin);
		scanf("%c", &respuesta2);
		if(respuesta2 == 'y')
		{
			idDos= auxE->id;
			salario= auxE->sueldo;
			horasTrabajadas= auxE->horasTrabajadas;
		    strcpy(nombre, auxE->nombre);
			printf("\n1- Camiar nombre\
					\n2- Cambiar horas trabajadas\
					\n3- Cambiar salario\
					\n4- Cancelar");
			__fpurge(stdin);
			scanf("%d", &respuesta);
			switch(respuesta)
			{
			case 1:
				getString(nombre,"\nIngrese nombre modificado: ","Error",1,50,0);
				break;
			case 2:
				printf("\nIngrese las horas modificadas: ");
				__fpurge(stdin);
				scanf("%d",&horasTrabajadas);
				break;
			case 3:
				printf("\nIngrese el salario modificado: ");
				__fpurge(stdin);
				scanf("%d",&salario);
				break;
			case 4:
				break;
			default:
				printf("\nNo es una opcion valida");
				break;
			}
		if(auxE!=NULL)
		{
			auxE = employee_newParametros(idDos, nombre, horasTrabajadas, salario);
			auxNode->pElement=auxE;
		}
		}
	}
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxE;
	Node* auxN;
	int id;
	int i;
	int flag = 0;
	if(pArrayListEmployee!=NULL)
	{
		auxN=pArrayListEmployee->pFirstNode;
		printf("\nIngrese el id del empleado que desea eliminar");
		__fpurge(stdin);
		scanf("%d", &id);
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxE=auxN->pElement;
			if(auxE->id == id)
			{
				ll_remove(pArrayListEmployee,i);
				flag = 1;
				break;
			}
			auxN=auxN->pNextNode;
		}
		if(flag!=0)
			printf("\nEl id no pudo ser encontrado");
	}


    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxE;
	Node* auxN;
	int i;
	if(pArrayListEmployee!=NULL)
	{
		auxN=pArrayListEmployee->pFirstNode;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxE=auxN->pElement;
			if(auxE != NULL)
			{
				printf("%d, %s, %d, %d \n", auxE->id, auxE->nombre, auxE->horasTrabajadas, auxE->sueldo);
			}
			auxN=auxN->pNextNode;
		}
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Node* aux;
	Employee* new;
	int i=0;
	new = (Employee*)malloc(sizeof(Employee));
	if(new==NULL)
		exit(-3);
	pFile = fopen(path,"w");
	if(pFile!=NULL)
	{
		aux = pArrayListEmployee->pFirstNode;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			new = aux->pElement;
			fprintf(pFile, "%d,%s,%d,%d\n", new->id,new->nombre,new->horasTrabajadas,new->sueldo);
			aux = aux->pNextNode;
		}
	}
		fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Node* aux;
	Employee* new;
	Employee auxE;
	int i=0;
	int r;
	new = (Employee*)malloc(sizeof(Employee));
	if(new==NULL)
		exit(-3);
	pFile = fopen(path,"wb");
	if(pFile!=NULL)
	{
		aux = pArrayListEmployee->pFirstNode;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			new = aux->pElement;
			auxE = *new;
			r = fwrite(&auxE,sizeof(Employee), 1, pFile);
			if(r<1)
				printf("\n no se pudo leer el archivo");
			aux = aux->pNextNode;
		}
	}
		fclose(pFile);
    return 1;
}

