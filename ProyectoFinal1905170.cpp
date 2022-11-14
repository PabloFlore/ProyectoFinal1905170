#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#include<fstream>

using namespace std;

int* art, * year, registros, desicion, n = 1, * item;
string* nombre, * clasificacion, * caracteristica, * genero, * descripcion;
float* precio, * iva, * total;
char enie = 165;

void alta();
void eliminar();
void lista();
void modificar();
void archivos();

int main()
{
	int opc;
	printf("\t ****TIENDADEVIDEOJUEGOS****\n");
	printf("1.-Agregar\n2.-Modificar\n3.-Eliminar\n4.-Lista\n5.-Limpiar pantalla\n6.-Salir\n");
	scanf_s("%d", &opc);
	switch (opc)
	{
	case 1:
		alta();
		system("pause");
		return main();
		break;
	case 2:
		modificar();
		system("pause");
		return main();
		break;
	case 3:
		eliminar();
		system("pause");
		return main();
		break;
	case 4:
		lista();
		system("pause");
		return main();
		break;
	case 5:
		system("cls");
		return main();
		break;
	case 6:
		archivos();
		exit(1);
	default:
		printf("Ingrese una opcion valida \n");
		break;

	}

}

void alta()
{
	printf("Cuantos registros quiere dar de alta\n");
	scanf_s("%d", &registros);
	item = new int[registros];
	year = new int[registros];
	nombre = new string[registros];
	clasificacion = new string[registros];
	caracteristica = new string[registros];
	genero = new string[registros];
	descripcion = new string[registros];
	precio = new float[registros];
	iva = new float[registros];
	total = new float[registros];
	int a = 202200;
	*item = a;
	for (int i = 0; i < registros; i++)
	{
		item[i] = a;
		printf("Articulo: %d\n", item[i]);
		printf("Ingrese el a%co\n", 164);
		scanf_s("%d", &year[i]);
		printf("Ingrese el nombre\n");
		cin.ignore();
		getline(cin, nombre[i]);
		printf("Ingrese la clasificacion\n");
		getline(cin, clasificacion[i]);
		printf("Ingrese las caracteristicas\n");
		getline(cin, caracteristica[i]);
		printf("Ingrese el genero\n");
		getline(cin, genero[i]);
		printf("Ingrese la descripcion\n");
		getline(cin, descripcion[i]);
		printf("Ingrese el precio\n");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];
		printf("\n");
		a = a + 1;
	}
}

void modificar()
{
	int modificado;
	int modopc;
	int modopc2 = 1;
	do
	{
		printf("Ingrese el numero de articulo a modificar\n");
		scanf_s("%d", &modificado);
	} while (modificado <= 0);

	for (int i = 0; i < registros; i++)
	{
		if (modificado == item[i])
		{
			printf("\tQue desea modificar del articulo?\n");
			printf("1.-Todo\n2.-A%co\n3.-Nombre\n4.-Clasificacion\n5.-Caracteristicas\n6.-Genero\n7.-Descripcion\n8.-Precio\n9.-Volver al menu\n", 164);
			scanf_s("%d", &modopc);
			switch (modopc)
			{
			case 1:
				printf("Ingrese el a%co\n", 164);
				scanf_s("%d", year);
				printf("Ingrese el nombre\n");
				cin.ignore();
				getline(cin, nombre[i]);
				printf("Ingrese la clasificacion\n");
				getline(cin, clasificacion[i]);
				printf("Ingrese las caracteristicas\n");
				getline(cin, caracteristica[i]);
				printf("Ingrese el genero\n");
				getline(cin, genero[i]);
				printf("Ingrese la descripcion\n");
				getline(cin, descripcion[i]);
				printf("Ingrese el precio\n");
				scanf_s("%f", &precio[i]);
				iva[i] = precio[i] * .16;
				total[i] = precio[i] + iva[i];
				break;
			case 2:
				printf("Ingrese el a%co\n", 164);
				scanf_s("%d", year);
				break;
			case 3:
				printf("Ingrese el nombre\n");
				cin.ignore();
				getline(cin, nombre[i]);
				break;
			case 4:
				printf("Ingrese la clasificacion\n");
				getline(cin, clasificacion[i]);
				break;
			case 5:
				printf("Ingrese las caracteristicas\n");
				getline(cin, caracteristica[i]);
				break;
			case 6:
				printf("Ingrese el genero\n");
				getline(cin, genero[i]);
				break;
			case 7:
				printf("Ingrese la descripcion\n");
				getline(cin, descripcion[i]);
			case 8:
				printf("Ingrese el precio\n");
				scanf_s("%f", &precio[i]);
				iva[i] = precio[i] * .16;
				total[i] = precio[i] + iva[i];
				break;
			case 9:
				break;
			default:
				printf("Ingrese una opcion valida \n");
				break;
				return modificar();
			}
		}
	}
}

void eliminar()
{
	int eliminar;
	printf("Ingrese el numero de articulo que quiere eliminar\n");
	scanf_s("%d", &eliminar);

	for (int i = 0; i < registros; i++)
	{
		if (eliminar == item[i])
		{
			item[i] = 0;
		}
	}
}

void lista()
{
	int op2;
	string busc;

	printf("1.-Buscar por clasificacion\n2.-Buscar por genero\n3.-Mostrar todos los articulos\n");
	scanf_s("%d", &op2);
	switch (op2)
	{
	case 1:
		printf("Ingrese la clasificacion a buscar \n");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == busc)
			{
				if (item[i] != 0)
				{
					printf("ARTICULO %d\n", item[i]);
					printf("A%co: %d\n", 164, year[i]);
					printf("Videojuego: %s\n", nombre[i].c_str());
					printf("Clasificacion: %s\n", clasificacion[i].c_str());
					printf("Descripcion: %s\n", descripcion[i].c_str());
					printf("Subtotal: %f\n", precio[i]);
					printf("IVA: %f\n", iva[i]);
					printf("Total: %f\n", total[i]);
					printf("\n");
				}
			}
		}
		break;

	case 2:
		printf("Ingrese el genero a buscar\n");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (genero[i] == busc)
			{
				if (item[i] != 0)
				{
					printf("ARTICULO %d\n", item[i]);
					printf("A%co: %d\n", 164, year[i]);
					printf("Videojuego: %s\n", nombre[i].c_str());
					printf("Clasificacion: %s\n", clasificacion[i].c_str());
					printf("Descripcion: %s\n", descripcion[i].c_str());
					printf("Subtotal: %f\n", precio[i]);
					printf("IVA: %f\n", iva[i]);
					printf("Total: %f\n", total[i]);
					printf("\n");
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < registros; i++)
		{
			if (item[i] != 0)
			{
				printf("ARTICULO %d\n", item[i]);
				printf("A%co: %d\n", 164, year[i]);
				printf("Videojuego: %s\n", nombre[i].c_str());
				printf("Clasificacion: %s\n", clasificacion[i].c_str());
				printf("Descripcion: %s\n", descripcion[i].c_str());
				printf("Subtotal: %f\n", precio[i]);
				printf("IVA: %f\n", iva[i]);
				printf("Total: %f\n", total[i]);
				printf("\n");
			}
		}
		break;
	default:
		printf("Ingrese una opcion valida\n");
		return lista();
		break;
	}
}

void archivos()
{
	ofstream archivo;
	string nombrearchivo;
	nombrearchivo = "Proyecto final";
	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO GENERAR EL ARCHIVO\n");
		system("pause");
		exit(1);
	}

	archivo << "\t \t INFORMACION\n";
	for (int i = 0; i < registros; i++)
	{
		if (item[i] != 0)
		{
			archivo << "DATO \n" << i + 1 << endl;
			archivo << "ARTICULO:" << item[i] << endl;
			archivo << "A";
			archivo << "Ñ";
			archivo << "O:" << year[i] << endl;
			archivo << "VIDEOJUEGO:" << nombre[i] << endl;
			archivo << "CLASIFICACION:" << clasificacion[i] << endl;
			archivo << endl;
		}

	}
	archivo.close();
}

