#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"



Employee* employee_new(){

Employee* emp = (Employee*)malloc(sizeof(Employee));

if(emp != NULL){
    emp->id = 0;
    strcpy(emp->nombre, " ");
    emp->horasTrabajadas =0 ;
    emp->sueldo = 0;

}
return emp;
}
Employee*  employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldo){

Employee* emp = (Employee*)malloc(sizeof(Employee));

if(emp != NULL){
    emp->id = idStr;
    strcpy(emp->nombre, nombreStr);
    emp->horasTrabajadas = horasTrabajadasStr;
    emp->sueldo = sueldo;

}
return emp;
}
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	if(horasTrabajadas>=0)
			this->horasTrabajadas = horasTrabajadas;
		else
			printf("El salario es incorrecto");
		return 0;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	if(sueldo>=0)
		this->sueldo = sueldo;
	else
		printf("El salario es incorrecto");
	return 0;
}

Employee* employee_delete(){

Employee* emp = (Employee*)malloc( sizeof(Employee));

if(emp != NULL){
    emp->id = 0;
    strcpy(emp->nombre, " ");
    emp->horasTrabajadas =0 ;
    emp->sueldo = 0;

}
return emp;
}

