/*
 * ArrayEmployees.h
 *
 *  Created on: Sep 28, 2020
 *      Author: Administrator
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
    } Employee;

void initEmployees(Employee[],int);
Employee addEmployee(Employee[],int);
void printAnEmployee(Employee);
int printEmployees(Employee[],int);
void sortEmployees(Employee[],int);
int createEmployeeId(Employee[],int);
void addEmployeeList(Employee[],int);
int findFree(Employee[],int);
int removeEmployee(Employee[],int);
int findEmployeeById(Employee[],int);
void editEmployeeName(Employee[],int);
void editEmployeeLastName(Employee[],int);
void editEmployeeSalary(Employee[],int);
void editEmployeeSector(Employee[],int);
float salaryAdd(Employee[],int);
float salaryAverage(Employee[],int);
void salaryMoreThanAverage(Employee[],int);
void printSalary(Employee[],int);


#endif /* ARRAYEMPLOYEES_H_ */
