#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include"utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    int option = 0;
    LinkedList* lista = ll_newLinkedList();
    do{
    	printf("Menu:\n"
     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
     "3. Alta de empleado\n"
    "4. Modificar datos de empleado\n"
    "5. Baja de empleado\n"
     "6. Listar empleados\n"
     "7. Ordenar empleados\n"
     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
     "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    "10. Salir\n");
    	__fpurge(stdin);
    	scanf("%d",&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",lista);
                break;
            case 2:
            	controller_loadFromBinary("datab.csv" , lista);
            	break;
            case 3:
            	controller_addEmployee(lista);
            	break;
            case 4:
            	controller_editEmployee(lista);
            	break;
            case 5:
            	controller_removeEmployee(lista);
            	break;
            case 6:
            	controller_ListEmployee(lista);
            	break;
            case 7:
            	ll_sort(lista, swapEmployee, 1);
            	break;
            case 8:
            	controller_saveAsText("data2.csv",lista);
            	break;
            case 9:
            	controller_saveAsBinary("datab.csv",lista);
        }
    }while(option != 10);
    return 0;
}


/*int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}*/





