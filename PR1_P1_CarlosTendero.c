#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>



#define CORRECTO 0          /*se ejecuta correctamente*/
#define NUMERO_TIRADAS 10   /*dimension de las veces que se tira el dado*/
#define N 10                /*veces que lanzamos el dado*/

/* Función: ObtenerRonda  
 * Devuelve el valor de la ronda de tiradas de un dado de 6 caras.  
 * Parámetros de entrada:  
 * no tiene  
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Array que contiene la ronda de tiradas obtenida.  
 * Paso del parámetro por referencia.  */ 
void ObtenerRonda (int ParRondaTiradas[NUMERO_TIRADAS]);
/* Función: CalcularMedia  
 * Devuelve la media aritmética de la ronda de tiradas dada.  
 * Parámetros de entrada:  
 * Array que contiene la ronda de tiradas de la que se desea.  
 * obtener su media aritmética. Paso del parámetro por referencia.  
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Media aritmética. Valor devuelto por la función.  */
float CalcularMedia (int ParRondaTiradas[NUMERO_TIRADAS]);
/* Función: CalcularVarianza  
 * Devuelve la varianza de la ronda de tiradas dada.  
 * Parámetros de entrada:  
 * Array que contiene la ronda de tiradas de la que se desea.  
 * obtener su varianza. Paso del parámetro por referencia.  
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Varianza. Valor devuelto por la función.  */ 
float CalcularVarianza (int ParRondaTiradas[NUMERO_TIRADAS]);
/* Función: CalcularDesviacionTipica 
 * Devuelve la desviación típica de la ronda de tiradas dada.  
 * Parámetros de entrada:  
 * Array que contiene la ronda de tiradas de la que se desea.  
 * obtener su desviación típica. Paso del parámetro por referencia.  
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Desviación típica. Valor devuelto por la función.*/ 
float CalcularDesviacionTipica (int ParRondaTiradas[NUMERO_TIRADAS]);
	
int main(void)
{
    
    #define HACER_TIRADA 1          
    #define ESCRIBIR_RONDA 2
    #define SALIR 3


    int TipoOperacion;  /*variable que indica que operacion hacer*/
    int RondaTiradas[NUMERO_TIRADAS];   /*variable que guarda los valores*/
    int FlgSalir;       /*varialbe que indica si salimos del programa */
    int Indice;         /*variable para inicializar el dado*/
    int FlgTirada;      /*variable que indica si se ha lanzado el dado*/
    int i = 0;          /*variable auxiliar*/
    
	
	
	setlocale(LC_ALL,"spanish");
	FlgSalir = 0;
        FlgTirada = 0;
        for (Indice=0;Indice<NUMERO_TIRADAS;Indice++)   /*inicializamos*/
           RondaTiradas[Indice]=0;
        
        while(!FlgSalir)
        {
            /*menu*/
          printf("\nElija la operación a realizar\n");
          printf("\nRondas tiradas:\t\t%d\n", FlgTirada);
          printf("1. Hacer N tiradas de un dedo de 6 caras y almacenar la ronda de tiradas\n");
          printf("2. Obtener y escribir la media aritmética, la varianza y la desviación típica de la última ronda de tiradas\n");
          printf("3. Salir del programa\n");
          fflush(stdin);
          scanf("%d",&TipoOperacion);
        
          switch (TipoOperacion)
          {
            case HACER_TIRADA:
                    ObtenerRonda(RondaTiradas);    /*se obtiene y se muestra la ronda por pantalla*/ 
                    FlgTirada++;
              break;
          case ESCRIBIR_RONDA:
              if(FlgTirada == 0)
                  printf("\nNo se ha hecho ninguna tirada");
             /*Media aritmetica*/
              printf("\nMedia:\t\t\t%.2f", CalcularMedia(RondaTiradas));
              /*Varianza*/
              printf("\nVarianza:\t\t%.2f", CalcularVarianza(RondaTiradas));
              /*Desviacion tipica*/
              printf("\nDesviacion tipica:\t%.2f", CalcularDesviacionTipica(RondaTiradas));
            break;
            
          case SALIR:
              FlgSalir = 1;
              printf("\nAdios");    /*salimos del programa*/
            break;
          
          default:
              printf("\nOpción no válida"); /*siempre que el usuario introduce un valor no permitido*/
              break;
         }
       }  
 

   return CORRECTO;
}
/* Función: ObtenerRonda  
 * Devuelve el valor de la ronda de tiradas de un dado de 6 caras.  
 * Parámetros de entrada:  
 * no tiene  
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Array que contiene la ronda de tiradas obtenida.  
 * Paso del parámetro por referencia.  */ 
void ObtenerRonda (int ParRondaTiradas[NUMERO_TIRADAS])
{
    
    int i = 0;
    for(i=0;i<N;i++){
        ParRondaTiradas[i] = 1 +(rand() % 6);  /*Genera numeros entre 1 y 6*/
        printf("\nTirada %d\t%d",i+1, ParRondaTiradas[i]); 
    }
        
}
/* Función: CalcularMedia  
 * Devuelve la media aritmética de la ronda de tiradas dada.  
 * Parámetros de entrada:  
 * Array que contiene la ronda de tiradas de la que se desea.  
 * obtener su media aritmética. Paso del parámetro por referencia.  
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Media aritmética. Valor devuelto por la función.  */
float CalcularMedia (int ParRondaTiradas[NUMERO_TIRADAS])
{
    int i = 0;
    float total = 0.00;
    for(i=0; i < N && ParRondaTiradas[i]!=0; i++)
        total +=(float)ParRondaTiradas[i];  /*sumar el total de elementos*/
    
    return  total/N;
}
/* Función: CalcularVarianza  
 * Devuelve la varianza de la ronda de tiradas dada.  
 * Parámetros de entrada:  
 * Array que contiene la ronda de tiradas de la que se desea.  
 * obtener su varianza. Paso del parámetro por referencia.  
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Varianza. Valor devuelto por la función.  */ 
float CalcularVarianza (int ParRondaTiradas[NUMERO_TIRADAS])
{
    float media = 0.00, total = 0.00;
    int i = 0;
    media = CalcularMedia(ParRondaTiradas); /*media aritmetica*/
    for(i=0; i < N && ParRondaTiradas[i]!=0;i++)
        total +=pow(ParRondaTiradas[i]-media,2);
        
    return total/N;
}
/* Función: CalcularDesviacionTipica 
 * Devuelve la desviación típica de la ronda de tiradas dada.  
 * Parámetros de entrada:  
 * Array que contiene la ronda de tiradas de la que se desea.  
 * obtener su desviación típica. Paso del parámetro por referencia.  
 * Precondiciones:  
 * no tiene  
 * Parámetros de salida:  
 * Desviación típica. Valor devuelto por la función.*/ 
float CalcularDesviacionTipica (int ParRondaTiradas[NUMERO_TIRADAS])
{
    return sqrt(CalcularVarianza(ParRondaTiradas));
}