/**
 * @file voraz.cpp
 *
 * @brief Practica 8 Problema 2, Programa que soluciona el problema planteado en la practica
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 24/12/2018
 */

#include <iostream>
#include <vector>
#include "grafo.h"
#include <fstream>
using namespace std;

const int REPETICIONES = 10;
const int TALLA_INCIAL = 5;
const int TALLA_FINAL = 100;
const int INCREMENTO = 5;
const int TAM_GRAFO = 8;
const int NO_ARCO = 0;
const int SI_ARCO = 1;

int colorear(vector<int>&, const Grafo&);
void evaluar(unsigned, unsigned, int, float (*t)(unsigned), ostream &);
float fAUX(unsigned);

int main(int argc, const char * argv[]) {
    
    vector<int> colores(TAM_GRAFO);
    //En la función main se deberá crear un grafo de 8 nodos
    Grafo g(TAM_GRAFO);
    g.creaGrafoND(NO_ARCO, SI_ARCO);
    g.mostrar();
    
    //Ejecutar el algoritmo sobre este grafo, para comprobar si funciona correctamente.
    int num_colores = colorear(colores, g);
    
    cout << "\nImprimiremos la combinacion nodo = color asignado\n| ";
    for (int i = 0; i < (int) colores.size(); ++i)
    {
        cout << i  << " = " << colores[i] <<" | ";
    }
    cout << "\nNúmero total de colores empleados: " << num_colores;
    
    /*
     * Calcular el coste medio del algoritmo para grafos de 5
     * a 100 nodos en incrementos de 5.
     */
    ofstream fichero_coste_medio;
    
    fichero_coste_medio.open("costemediovoraz.dat");
    if(!fichero_coste_medio)
    {
        cout << "\nError abriendo el fichero para la escritura del coste medio" << endl;
    }
    else
    {
        evaluar(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fAUX, fichero_coste_medio);
        fichero_coste_medio.close();
    }
    
    cout << endl << endl;
    return 0;
}

/**
 *
 * Determina los colores de cada nodo de un grafo
 *
 * @param colores El indice representa el nodo y el contenido su color
 * @param g Grafo a colorear
 *
 * @return numero total de colores empleados
 *
 */
int colorear(vector<int>& colores, const Grafo& g)
{
    vector<bool> c(g.size());
    int i, j;
    
    for (i = 0; i < (int) g.size(); ++i)
    {
        // c es igual conjunto vacio
        for (auto item : c)
        {
            item = false;
        }
        
        for (j = 0; j < (int) g.size(); ++j)
        {
            if (g(i,j) != 0)
            {
                c[colores[j]] = true; // Como hacer la union si colores es de int y c es de bool
            }
        }
        
        j = 0;
        while (c[j] == true)
        {
            j += 1;
        }
        colores[i] = j;
    }
    
    // Calculamos el número total de colores empleados
    int num_color_max = -1;
    for (auto num_color : colores) {
        if ( num_color_max < num_color)
        {
            num_color_max = num_color;
        }
    }
    
    return num_color_max;
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
* los parametros enviados, aplicandole depues el algorimo voraz o backtracking para
* colorear el grafo
*
* @param n Tamaño del vector
*
* @return numero de accesos al grafo
*
*/
float fAUX(unsigned n)
{
    Grafo g(n);
    vector<int> colores(n);
    
    for(int i = 0; i < REPETICIONES; i++)
    {
        g.creaGrafoND(NO_ARCO, SI_ARCO);
        colorear(colores, g);
    }
    return g.getAccesos()/REPETICIONES;
}
