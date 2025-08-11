#include "stdio.h"
#include "math.h"

float pila[5];

//Funciones

void imprimirPila()
{
    printf("\n◄•••- RPN Calculator -•••►\n");
    for (int i = 4; i >= 0; i--)
    {
        printf("%d |\t%f\n", i+1, pila[i]);
    }
}

void push(float valor)
{
    // Mover los elementos hacia arriba
    for (int i = 4; i > 0; i--)
    {
        pila[i] = pila[i - 1];
    }
    //Insertar
    pila[0] = valor;
}

void pop()
{
    //Bajar numeros
    for (int i = 0; i < 4; i++)
    {
        pila[i] = pila[i + 1];
    }
    //Limpiar ultimo
    pila[4] = 0;
}


//------PROGRAMMA PRINCIPAL------//

int main(int argc, char const *argv[])
{
    int opcion=0,operacion=0;
    float valor = 0,resultado=0;
    
    do
    {
    //Limpiar pantalla
    //printf("\033[2J"); 
    imprimirPila();

    // Mostrar opciones
    printf("Seleccione una opcion:\n");
    printf("1. Introducir valor \t 2. Elegir operacion \t 3. Borrar ultimo \t 4. Limpiar pila \t 0. Salir\n");
    scanf("%d", &opcion);

    //Opciones
    switch (opcion)
    {
    //Introducir valor
    case 1:
        printf("\tIngrese un valor: ");
        scanf("%f", &valor);
        push(valor);
        break;
    //Elegir operacion
    case 2:
        // Mostrar opciones de operacion
        printf("Seleccione una operacion:\n");
        printf("1. Sumar \n 2. Restar \n 3. Multiplicar \n 4. Dividir \n 5. Raiz Cuadrada \n 6. Potencia \n 7. Seno \n 8. Coseno \n 9. Tangente \n 0. Atras\n");
        scanf("%d", &operacion);

        switch (operacion)           
        {
        case 1: // Sumar
            resultado = pila[0] + pila[1];
            pop();
            pop();
            push(resultado);
            break;
        case 2: // Restar
            resultado = pila[1] - pila[0];
            pop();
            pop();
            push(resultado);
            break;
        case 3: // Multiplicar
            resultado = pila[0] * pila[1];
            pop();
            pop();
            push(resultado);
            break;
        case 4: // Dividir
            if (pila[0] == 0)
            {
                printf("\tError: Division por cero.\n");
            }
            else
            {
                resultado = pila[1] / pila[0];
                pop();
                pop();
                push(resultado);
            }
            break;
        case 5: // Raiz Cuadrada
            if (pila[0] < 0)
            {
                printf("\tError: No se puede calcular la raiz cuadrada de un numero negativo.\n");
            }
            else
            {
                resultado = sqrt(pila[0]);
                pila[0] = resultado;
            }
            break;
        case 6: // Potencia
            if (pila[1] < 0 && pila[0] != (int)pila[0])
            {
                printf("\tError: No se puede calcular la potencia de un numero negativo con exponente no entero.\n");
            }
            else
            {
                resultado = pow(pila[1], pila[0]);
                pop();
                pop();
                push(resultado);
            }
            break;
        case 7: // Seno
            resultado = sin(pila[0] * M_PI / 180.0);
            pila[0] = resultado;
            break;
        case 8: // Coseno
            resultado = cos(pila[0] * M_PI / 180.0);
            pila[0] = resultado;
            break;
        case 9: // Tangente

            // Verificar ángulos que causan tangente indefinida (90°, 270°, etc.)
            if (fmod(pila[0], 180.0) == 90.0)
            {
                printf("\tError: Tangente indefinida para %f grados.\n", pila[0]);
            }
            else
            {
                resultado = tan(pila[0] * M_PI / 180.0);
                pila[0] = resultado;
            }
            break;
        case 0: // Atras
            printf("\tRegresando al menu principal...\n");
            break;
        default:
            printf("\tError: Operacion no reconocida.\n");
            break;
        }
        break;
    case 3:
        if (pila[0] == 0)
        {
            printf("\tNo hay valores en la pila para borrar.\n");
        }
        else
        {
            pop();
        }
        break;
    case 4:
        // Limpiar la pila
        for (int i = 0; i < 5; i++)
        {   
            pila[i] = 0;
        }
    break;
    default:
        if (opcion != 0)
            printf("---------------------\n!!Error: Opcion no valida.\n---------------------\n");

        break;
    }

    } while (opcion != 0);

    printf("Saliendo del programa...\n");
    return 0;

}
