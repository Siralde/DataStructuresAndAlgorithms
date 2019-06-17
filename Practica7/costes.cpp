 
/**
 * @file coste.cpp
 *
 * @brief Practica 7 coste medio algoritmo Dijkstra 
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 07/10/2017
 */


#include <vector>
#include <iostream>
#include <fstream>

#include "grafo.h"


using namespace std;


const int REPETICIONES = 1000;
const int TALLA_INCIAL = 5;
const int TALLA_FINAL = 100;
const int INCREMENTO = 5;

const int PESO_INFINITO = 999999;

void dijkstra(int, vector<float>&, vector<int>&, const Grafo&);
float fAUX(unsigned);
void evaluar(unsigned, unsigned, int, float (*t)(unsigned), ostream &);


int main(void)
{

    ofstream fichero_coste_medio;

    fichero_coste_medio.open("costemedio.dat");
    if(!fichero_coste_medio)
    {
        cout << "\nError abriendo el fichero para la escritura del coste medio" << endl;
    }
    else
    {
        evaluar(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fAUX, fichero_coste_medio);
        
        fichero_coste_medio.close();
    }

    return 0;
}

/**
 *
 * Funcion que implementa el algoritmo Dijkstra el cual nos calcula el camino minimo desde
 * cualquier nodo a el resto de los nodos del grafo
 *
 * @param nodoInicial nodo de inicio del camino
 * @param pVecino vector que contiene el peso del arco de un nodo a otro
 * @param vecino vector que contiene los arcos del camino mas corto a otro
 * @param g grafo al cual se le va aplicar el algoritmo
 *
 */
void dijkstra(int nodoInicial, vector<float>& pVecino, vector<int>& vecino, const Grafo& g)
{
    vector<bool> visitados(vecino.size());
    int p_min; // Peso Minimo entre dos nodos
    int nodo_p_minimo = nodoInicial; // Nodo que tiene el peso minimo
    int sum_arcos;

    for(int i = 0; i < (int)vecino.size(); ++i)
    {
        visitados[i] = false;
        vecino[i] = nodoInicial;
        pVecino[i] = g(nodoInicial, i);
    }

    visitados[nodoInicial] = true;

    for(int i = 1; i < (int)vecino.size(); ++i)
    {
        p_min = PESO_INFINITO;

        // Busqueda del Arco Minimo
         
        for (int j = 0; j < (int)vecino.size(); ++j)
        {
            if ( !(visitados[j]) && ((0 < pVecino[j]) && (pVecino[j] < p_min)) )
            {
                p_min = pVecino[j];
                nodo_p_minimo = j;
            }
        }


         visitados[nodo_p_minimo] = true;
        
        
         // Actualizacion del peso de los Arcos
         
        for (int j = 0; j < (int)vecino.size(); ++j)
        {
            sum_arcos = pVecino[nodo_p_minimo] + g(nodo_p_minimo, j); // Suma del peso del camino con el peso del nodo al que se puede dirijir
            if ( !(visitados[j]) && (sum_arcos < pVecino[j]) )
            {
                pVecino[j] = sum_arcos;
                vecino[j] = nodo_p_minimo;
            }
        }
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
* Funcion que genera los pesos de un grafo de tamaño n con los pesos aleatorios entro
* los parametros enviados, aplicandole depues el algorimo Dijkstra para encontrar el 
* camino con el menor peso posible desde el nodo inicial a todos los demas nodos del grafo
*
* @param n Tamaño del vector
* @return numero de accesos al grafo
*
*/
float fAUX(unsigned n)
{   
    
    Grafo g(n);

    vector<int> vecino(n);
    vector<float> pVecino(n);

    for(int i = 0; i < REPETICIONES; i++)
    {            
        g.creaGrafoND(3, 30);

        dijkstra(0, pVecino, vecino, g);
    }
    
    return g.getAccesos()/REPETICIONES;
    
}

/**
 * 
 * La grafica nos muestra como es coste peor y medio son iguales, debido a que hemos optimizado el algoritmos de 
 * Dijkstra a la hora de actualizar el peso, haciendo la suma de peso que tiene el camino y el peso de 
 * el nodo al que se puede dirijir en ese momento. reduciendo el numero de accesos al grafo.
 * El coste peor y mejor es el mismo.
 * 
 */

