#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define CORRECTO 0              /*valor que determina si es correcto o no*/
#define NOM_FICHERO "Ronda.txt" /*nombre del fichero donde se escribe los valores*/

/* Función: AsignarMemoria  
 * Asigna memoria para la ronda de tiradas. 
 * Devuelve un puntero a un puntero a entero.  
 * Parámetros de entrada:  
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Puntero a un puntero a entero. Valor devuelto por la función.  */
int **AsignarMemoria(int NumT);
/* Función: LanzarTiradas  
 * Guarda en memoria la ronda de tiradas. 
 * Parámetros de entrada:  
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Ronda de tiradas realizada. Paso del parámetro por referencia.  
 */
void LanzarTiradas(int **pT, int NumT);
/* Función: ImprimirTiradas  
 * Escribe en pantalla la ronda de tiradas. 
 * Parámetros de entrada:  
 * Número de tiradas de la ronda. 
 * Ronda de tiradas. * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * no tiene.  */
void ImprimirTiradas(int *pT, int NumT);
/* Función: CalcularMedia 
 * Calcula la media aritmética de la ronda de tiradas. 
 * Parámetros de entrada: 
 * Ronda de tiradas. 
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Media aritmética. Valor devuelto por la función  */
float CalcularMedia(int *pT, int NumT);
/* Función: CalcularVarianza 
 * Calcula la varianza de la ronda de tiradas. 
 * Parámetros de entrada:  
 * Ronda de tiradas. 
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Varianza. Valor devuelto por la función  
 */
float CalcularVarianza(int *pT, int NumT);
/* Función: CalcularDesviacionTipica 
 * Calcula la desviación típica de la ronda de tiradas. 
 * Parámetros de entrada:  
 * Ronda de tiradas. 
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Desviación típica. Valor devuelto por la función  */
float CalcularDesviacionTipica(int *pT, int NumT);
/* Función: EscribirFichero 
 * Guarda en un fichero la ronda de tiradas. 
 * Parámetros de entrada:  
 * Número de tiradas de la ronda. 
 * Ronda de tiradas. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * no tiene.  */
void EscribirFichero(int *pT, int NumT);

int main(void) /* funcion o programa principal */ {

#define HACER_TIRADA 1
#define ESCRIBIR_RONDA 2
#define ALMACENAR_RONDA_FICHERO 3
#define SALIR 4


    int TipoOperacion;          /*variable que indica qur operacion hacer*/
    int FlgSalir = 0;           /*variable que indica cuando se sale del programa*/
    int FlgTirada = 0;          /*variable que indica si se ha lanzado el dado */
    

    int NumTiradas = 0;         /*cuantas veces se lanza el dado*/
    int **pTiradas = NULL;      /*doble puntero a int, sirve para guardar los valores*/

    setlocale(LC_ALL, "spanish");
   
    while (!FlgSalir) {
        /*menu*/
        printf("\nElija la operación a realizar\n");
        printf("\nRondas tiradas:\t\t%d\n", FlgTirada);
        printf("1. Hacer N tiradas de un dado de 6 caras y almacenar la ronda de tiradas\n");
        printf("2. Obtener y escribir la media aritmética, la varianza y la desviación típica de la última ronda de tiradas\n");
        printf("3. Almacenar las N tiradas de la ronda en un archivo\n");
        printf("4. Salir\n");
        fflush(stdin);
        scanf("%d", &TipoOperacion);

        switch (TipoOperacion) {
            case HACER_TIRADA:
                printf("\nCuantas tiradas va a realizar: ");
                scanf("%d", &NumTiradas);
                while (NumTiradas < 1) {        /*control de errores*/
                    printf("\nAccion no valida, introduzca un valor positivo por favor: ");
                    scanf("%d", &NumTiradas);
                }
                if (pTiradas != NULL) {         /*libero antes dfe asignar*/
                    free(*(pTiradas));
                    free(pTiradas);
                }
                pTiradas = AsignarMemoria(NumTiradas);  /*asigno memoria en funcion de las veces que se lanza*/
                
                if(pTiradas == NULL)                    /*control de errores*/
                    return -1;
               
                LanzarTiradas(pTiradas, NumTiradas);    /*se lanza las tiradas*/
               
                ImprimirTiradas(*pTiradas, NumTiradas); /*se muestran las tiradas*/
                FlgTirada++;                            /*numero de la Ronda*/
                break;

            case ESCRIBIR_RONDA:
                
                if (FlgTirada == 0)                             /*control de errores*/
                    printf("\nNo se ha hecho ninguna tirada");
                  
                else {
                    /*Media aritmetica*/
                    printf("\nMedia:\t\t\t%.2f", CalcularMedia(*pTiradas, NumTiradas));
                    /*Varianza*/
                    printf("\nVarianza:\t\t%.2f", CalcularVarianza(*pTiradas, NumTiradas));
                    /*Desviacion tipica*/
                    printf("\nDesviacion tipica:\t%.2f", CalcularDesviacionTipica(*pTiradas, NumTiradas));
                }
                break;

            case ALMACENAR_RONDA_FICHERO:
                if (FlgTirada == 0) {   /*Control de errores*/
                    printf("\nNo no se ha realizado ninguna tirada");
                } else
                    EscribirFichero(*pTiradas, NumTiradas); /*Se escribee en un fichero*/

                break;

            case SALIR:

                FlgSalir = 1;   
                printf("\nAdios");
                break;
            default:
                printf("\nOpcion no valida");   /*Se introduce un valor no permitido*/
                break;
        }
    }
    if (pTiradas) {
        free(*(pTiradas));
        free(pTiradas);
    }
    return CORRECTO;
}

/* Función: AsignarMemoria  
 * Asigna memoria para la ronda de tiradas. 
 * Devuelve un puntero a un puntero a entero.  
 * Parámetros de entrada:  
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Puntero a un puntero a entero. Valor devuelto por la función.  */
int **AsignarMemoria(int NumT) {
    int **aux = NULL;                                   /*variable auxiliar */

    aux = (int**) malloc((sizeof (int*)));              /*asigna memoria para el puntero de fuera*/
    *(aux) = (int*) malloc(NumT * (sizeof (int)));      /*asigna memoria para los punteros de dentro*/
    if (!aux)                                           /*control de errores*/
        return NULL;

    return aux;                                         /*devuelvo la reserva de memoria*/
}

/* Función: LanzarTiradas  
 * Guarda en memoria la ronda de tiradas. 
 * Parámetros de entrada:  
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Ronda de tiradas realizada. Paso del parámetro por referencia.  
 */
void LanzarTiradas(int **pT, int NumT) {
    int i = 0;                                          /*variable auxilar*/
    int aux;                                            /*variable auxiliar*/
    if(pT == NULL)                                      /*control de errores*/
        return ;
    
    for (i = 0; i < NumT; i++) {
        aux = (1 + (rand() % 6));
        *(*(pT) + i) = aux;                     /*se asignan valores*/
    }
}

/* Función: ImprimirTiradas  
 * Escribe en pantalla la ronda de tiradas. 
 * Parámetros de entrada:  
 * Número de tiradas de la ronda. 
 * Ronda de tiradas. * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * no tiene.  */
void ImprimirTiradas(int *pT, int NumT) {
    int i = 0;                              /*variablr auxiliar*/
    if (!pT)                                /*control de errores*/
        return;

    for (i = 0; i < NumT; i++, pT++)
        printf("\nTirada %d \t%d", i+1, *(pT)); /*se van mostrando los valroes por pantalla*/
}

/* Función: CalcularMedia 
 * Calcula la media aritmética de la ronda de tiradas. 
 * Parámetros de entrada: 
 * Ronda de tiradas. 
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Media aritmética. Valor devuelto por la función  */
float CalcularMedia(int *pT, int NumT) {
    float total = 0.00;             /*variable auxiliar*/
    int i = 0;

    if (pT == NULL)                 /*control de errores*/
        return 0.00;


    for (i = 0; i < NumT; i++, pT++)
        total += (float) *(pT);     /*se suman los valores*/

    return total / i;               /*se devuelve la media aritmetica*/

}

/* Función: CalcularVarianza 
 * Calcula la varianza de la ronda de tiradas. 
 * Parámetros de entrada:  
 * Ronda de tiradas. 
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Varianza. Valor devuelto por la función  
 */
float CalcularVarianza(int *pT, int NumT) {

    int i = 0;
    float media = 0.00, total = 0.00;           /*variable auxiliar*/

    if (pT == NULL)
        return 0.00;

    media = CalcularMedia(pT, NumT);            /*calculo la media*/
    for (i = 0; i < NumT; i++, pT++)
        total += pow(*(pT) - media, 2);         /*se suman los valores*/

    return total / i;                           /*se devuelve el valor*/
}

/* Función: CalcularDesviacionTipica 
 * Calcula la desviación típica de la ronda de tiradas. 
 * Parámetros de entrada:  
 * Ronda de tiradas. 
 * Número de tiradas de la ronda. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Desviación típica. Valor devuelto por la función  */
float CalcularDesviacionTipica(int *pT, int NumT) {

    if (!pT)                            /*control de errores*/
        return 0.00;

    return sqrt(CalcularVarianza(pT, NumT));        /*se devuelve el resultado*/
}

/* Función: EscribirFichero 
 * Guarda en un fichero la ronda de tiradas. 
 * Parámetros de entrada:  
 * Número de tiradas de la ronda. 
 * Ronda de tiradas. 
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * no tiene.  */
void EscribirFichero(int *pT, int NumT) {
    int i = 0;
    FILE* fichero = NULL;

    fichero = fopen(NOM_FICHERO, "w");          /*abrimos el fichero*/

    if(fichero == NULL)                         /*no se ha podido abrir el fichero*/
        return ;
    
    for (i = 0; i < NumT; i++, pT++)
        fprintf(fichero, "Tirada %d \t%d\n",i+1, *(pT));        /*escribimos en el fichero*/

    fclose(fichero);                            /*se cierra el fichero*/
    printf("\nSe ha escrito en el fichero correctamente");
}

