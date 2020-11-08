#include "utn.h"
int MenuPrincipal(void) {
	int opcion;

	printf("\n/****************************************************");
	printf("\nMenu:");
	printf(
			"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
	printf(
			"\n2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).");
	printf("\n3. Alta de empleado");
	printf("\n4. Modificar datos de empleado");
	printf("\n5. Baja de empleado");
	printf("\n6. Listar empleados");
	printf("\n7. Ordenar empleados");
	printf(
			"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)..");
	printf(
			"\n9. Guardar los datos de los empleados en el archivo data.dat (modo binario).");
	printf("\n10. Salir");
	printf("\n*****************************************************/\n");
	scanf("%d", &opcion);

	return opcion;
}

int MostrarMenu(char *texto) {
	int opcion;

	printf(texto);
	scanf("%d", &opcion);

	return opcion;
}

void CargarTexto(char mensaje[], char texto[], int largo) {
	printf("%s", mensaje);
	fflush(stdin);
	fgets(texto, largo, stdin);
	texto[strlen(texto) - 1] = '\0';
}

int GetInt(char mensaje[], char error[], int min) {
	int num;

	printf("%s", mensaje);
	scanf("%d", &num);

	while (num < min) {

		printf("%s", error);
		scanf("%d", &num);
	}
	return num;
}

char ConfirmarOperacion(void) {
	char respuesta;

	do {
		printf("\n Desea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = tolower(respuesta);
	} while (respuesta != 's' && respuesta != 'n');

	return respuesta;
}
int CargarEntero(char mensaje[], char error[], int minimo, int maximo) {
	int num;

	printf("%s", mensaje);
	scanf("%d", &num);

	while (num != minimo && num != maximo) {

		printf("%s", error);
		scanf("%d", &num);
	}
	return num;
}

