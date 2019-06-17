/**
 * @file backtracking.cpp
 *
 * @brief Practica 8 Problema 3
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 19/12/2018
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

void colorearBacktracking(int i, int numeroColores, const Grafo& g, vector<int>& coloresM ,int& nColorM, vector<int>& colores);
void evaluar(unsigned, unsigned, int, float (*t)(unsigned), ostream &);
float fAUX(unsigned);

int main(int argc, const char * argv[]) {
    
    Grafo g(TAM_GRAFO);
    vector<int> colores(TAM_GRAFO);
    vector<int> coloresM(TAM_GRAFO, (int) g.size() + 1);
    int nColorM = (int) g.size() + 1;
    //En la función main se deberá crear un grafo de 8 nodos
    g.creaGrafoND(NO_ARCO, SI_ARCO);
    g.mostrar();
    

    //Ejecutar el algoritmo sobre este grafo, para comprobar si funciona correctamente.
    colorearBacktracking(0, 0, g, coloresM, nColorM, colores);
    
    cout << "\nImprimiremos la combinacion nodo = color asignado\n| ";
    for (int i = 0; i < (int) coloresM.size(); ++i)
    {
        cout << i  << " = " << coloresM[i] <<" | ";
    }
    cout << "\nNúmero total de colores empleados: " << nColorM;


    ofstream fichero_coste_medio;
    
    fichero_coste_medio.open("costemediobt.dat");
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
 *
 */
void colorearBacktracking(int i, int numeroColores, const Grafo& g, vector<int>& coloresM ,int& nColorM, vector<int>& colores)
{
    vector<bool> c(g.size());
    int j;
    
    if (i == (int) g.size())
    {
        coloresM = colores;
        if (numeroColores < nColorM)
        {
            nColorM = numeroColores;
        }
    }
    else
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
        
        for (j = 1; j < (int) g.size(); ++j)
        {
            if ( (c[j] == false) && (j < coloresM[i]))
            {
                colores[i] = j;
                colorearBacktracking(i+1, std::max(numeroColores,j), g, coloresM,nColorM, colores);
            }
        }
        colores[i] = 0;
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
    vector<int> coloresM(n,n + 1);
    int nColorM = n + 1;
    
    for(int i = 0; i < REPETICIONES; i++)
    {
        g.creaGrafoND(NO_ARCO, SI_ARCO);
        colorearBacktracking(0, 0, g, coloresM, nColorM, colores);
    }
    return g.getAccesos()/REPETICIONES;
}
