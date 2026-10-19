#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    // Variables locales
    char nombres[MAX][50];
    float precios[MAX];
    int contprod = 0;
    int op;
    int i; // Usando 'i' en lugar de 'f'
    int encontrar;
    char nombuscar[50];
    float total = 0, promedio = 0;
    int posCaro = 0, posBarato = 0;

    do
    {
        system("cls"); 
        printf("=======SISTEMA DE GESTION DE INVENTARIO========\n");
        printf("1. Ingresar producto\n");
        printf("2. Mostrar inventario completo\n");
        printf("3. Calcular precio total y promedio\n");
        printf("4. Encontrar producto mas caro y mas barato\n");
        printf("5. Buscar producto por nombre\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion entre 1-6: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                system("cls");
                if (contprod < MAX)
                {
                    printf("Ingrese el nombre del producto: ");
                    scanf(" %[^\n]", nombres[contprod]);
                    printf("Ingrese el precio del producto: ");
                    scanf("%f", &precios[contprod]);
                    contprod++;
                    printf("Dato agregado correctamente..\n");
                }
                else
                {
                    printf("No hay espacio disponible en el inventario..\n");
                }
                system("pause");
                break;

            case 2:
                system("cls");
                if (contprod == 0)
                {
                    printf("No hay productos registrados..\n");
                }
                else
                {
                    printf("--- LISTA DE PRODUCTOS ---\n");
                    for (i = 0; i < contprod; i++)
                    {
                        printf("%d.- %s - $%.2f\n", i + 1, nombres[i], precios[i]);
                    }
                }
                system("pause");
                break;

            case 3:
                system("cls");
                if (contprod == 0)
                {
                    printf("No hay productos registrados..\n");
                }
                else
                {
                    total = 0;
                    for (i = 0; i < contprod; i++)
                    {
                        total += precios[i];
                    }
                    promedio = total / contprod;
                    printf("Precio total del inventario: $%.2f\n", total);
                    printf("Precio promedio de los productos: $%.2f\n", promedio);
                }
                system("pause");
                break;

            case 4:
                system("cls");
                if (contprod == 0)
                {
                    printf("No hay productos registrados..\n");
                }
                else
                {
                    posCaro = 0;
                    posBarato = 0;
                    for (i = 1; i < contprod; i++)
                    {
                        if (precios[i] > precios[posCaro])
                        {
                            posCaro = i;
                        }
                        if (precios[i] < precios[posBarato])
                        {
                            posBarato = i;
                        }
                    }
                    printf("Producto mas CARO: %s ($%.2f)\n", nombres[posCaro], precios[posCaro]);
                    printf("Producto mas BARATO: %s ($%.2f)\n", nombres[posBarato], precios[posBarato]);
                }
                system("pause");
                break;

            case 5:
                system("cls");
                printf("Ingrese el nombre del producto a buscar: ");
                scanf(" %[^\n]", nombuscar);
                encontrar = 0;

                for (i = 0; i < contprod; i++)
                {
                    if (strcmp(nombres[i], nombuscar) == 0)
                    {
                        printf("Producto encontrado en la posicion %d. Precio: $%.2f\n", i + 1, precios[i]);
                        encontrar = 1;
                    }
                }

                if (encontrar == 0)
                {
                    printf("Datos no encontrados..\n");
                }
                system("pause");
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida..\n");
                system("pause");
                break;
        }

    } while (op != 6);

    return 0;
}