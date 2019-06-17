/**
 * @file merge.cpp
 *
 * @brief Practica 4. Algoritmo MergeSort
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 07/10/2017
 */

#include "VElement.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;


const int REPETICIONES = 1000;
const int TALLA_INCIAL = 50;
const int TALLA_FINAL = 5000;
const int INCREMENTO = 50;

void mergeSort(vector<VElement>&, int, int,vector<VElement>&);
void Mezclar(vector<VElement> &, int, int, int, vector<VElement>& );
void calculoCoste (unsigned, unsigned, int, float (*f)(unsigned),ostream &);
float fAUX(unsigned);
void evaluar(unsigned, unsigned, int, float (*t)(unsigned), ostream &);

/**
 * Funcion principal
 */
int main (void)
{
   
   ofstream fichero_coste_medio, fichero_tiempo;
    
    //Fichero a escribir de la Funcion A
    fichero_coste_medio.open("costemedio.data");
    if (!fichero_coste_medio)
    {
        cout << "\nError abriendo el fichero para la escritura del coste medio" << endl;
    }
    else
    {
        evaluar(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fAUX, fichero_coste_medio);
        
        fichero_coste_medio.close();
    }

    fichero_tiempo.open("costetiempo.data");
    if(!fichero_tiempo)
    {
        cout << "\nError abriendo fichero para escribir coste tiempo" << endl;
    }
    else
    {
        calculoCoste(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fAUX, fichero_tiempo);
        fichero_tiempo.close();
    }

    cout << endl << endl;
    
    return 0;
}


/**
*
* Funcion que que calcula el tiempo de ejecucion de CPU
* 
*
* @param ini Posicion Inicial del Vector
* @param fin Posicion Final del Vector
* @param inc Cantidad en la que se incrementa
* @param *t funcion
* @param file fichero donde se escribiran los datos
*
*/
void calculoCoste(unsigned ini, unsigned fin, int inc, float(*t)(unsigned), ostream & file)
{
    struct timespec ini_time, fin_time;
    double time;

 
    for(int i = (int) ini; i < (int) fin; i+=INCREMENTO)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);

        t(i);
        
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin_time);
        time = (fin_time.tv_sec - ini_time.tv_sec) + (fin_time.tv_nsec * 1.0e-9 - ini_time.tv_nsec * 1.0e-9);
        file << i << time/REPETICIONES << endl;

    }

}

/**
*
* Funcion que escribe en el fichero los resultados obtenidos
* la funcion t
*
* @param ini Posicion Inicial del Vector
* @param fin Posicion Final del Vector
* @param inc Cantidad en la que se incrementa
* @param t funcion
* @param file fichero donde se escribiran los datos
*
*/
void evaluar(unsigned ini, unsigned fin, int inc, float (*t)(unsigned), ostream & file)
{
    while(ini <= fin)
    {
        file << ini << " " << t(ini) << endl;
        ini = ini + inc;
    }
}

/**
*
* Crea vectores aleatorios n posiciones, que se ordenan con 
* mergesort, repitiendo el proceso un numero determinado de veces
*
* @param n Tamaño del vector
* @return pasos cantidad pasos totales
*
*/
float fAUX(unsigned n)
{
    float pasos = 0, asignaciones = 0, comparaciones = 0, x = 0;
    int num;
    vector <VElement> vec(n);
    vector <VElement> aux(n);
    VElement::initNAssign();
    VElement::initNComparison();
    
    
    for(int i = 0; i < REPETICIONES; i++)
    {
        for(unsigned j = 0; j < n; j++)
        {
            num = 1 + rand() % ( 2 * n);
            vec[j].set(num);
        }
        
        mergeSort(vec, 0, n - 1, aux);
        
    }
    
    asignaciones = VElement::getNAssign();
    comparaciones = VElement::getNComparison();
    x = asignaciones + comparaciones;
    pasos = x / REPETICIONES;
    
    return pasos;
}

/**
*
* Implementacion del algoritmo MergeSort que ordena los elementos
* de un Vector de menor a mayor.
*
* @param v Vector con elementos
* @param ini Posicion Inicial del Vector
* @param fin Posicion Final del Vector
* @param aux Vector ordenado de menor a mayor
*
*/
void mergeSort(vector<VElement> &v, int ini, int fin, vector<VElement> & aux)
{
    int i = ini;
    int j = fin;

    if (i < j)
    {
        int m = (i+j)/2;
        mergeSort(v, i, m, aux);
        mergeSort(v, m+1, j, aux);
 
        Mezclar(v, i, m, j,aux);
    }
}

/**
 *
 * Crea un vector con los elementos ordenados a partir de un vector
 * desordenado
 *
 * @param v     Vector con los elementos ordenados
 * @param izq   Indice de la posicon comienzo del vector
 * @param medio Indice de la posicion media del vector
 * @param der   Indice de la posicion derecha del vector
 * @param aux   Vector Ordenado de menor a mayor
 *
 */
void Mezclar(vector<VElement> & v, int izq, int medio, int der, vector<VElement> & aux)
{
    int i = izq;
    int j = medio + 1;
    int k = izq;
    
    while ((i <= medio )&& (j <= der))
    {
        if (v[i] <= v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    
    if (i > medio)
    {
        int cont_v = j;
        
        for (int cont_aux = k; cont_aux <= der; cont_aux++)
        {
            aux[cont_aux] = v[cont_v];
            cont_v++;
        }
    }
    else
    {
        int cont_v = i;
        int cont_aux = k;
        
        while ((cont_aux <= der )&& (cont_v <= medio))
        {
            aux[cont_aux] = v[cont_v];
            cont_v++;
            cont_aux++;
        }
    }
    
    for (int i = izq; i <= der; i++)
    {
        v[i] = aux[i];
    }
}
