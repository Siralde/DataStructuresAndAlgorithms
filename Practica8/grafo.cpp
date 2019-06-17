 
/**
 * @file grafo.cpp
 *
 * @brief Practica 7 implementacion del TAD grafo
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 24/12/2018
 */

#include "grafo.h"
#include <iomanip>      // std::setw

/**
 * Constante para los pesos infinitos
 */
const int PESO_INFINITO = 999999;

/**
 *
 * Constructor de la clase Grafo que pone cambia el tamano de los
 * vectores
 * 
 * @param t indice maximo de la matriz
 *
 */
Grafo::Grafo(unsigned t)
{
    matriz.resize(t);
    for (unsigned i = 0; i < matriz.size() ; i++)
    {
        matriz[i].resize(t, PESO_INFINITO);
    }
}

/**
 *
 * Devuelve el peso del arco entre dos nodos
 *
 * @param f indice dentro de la matriz de adyacencia o nodo
 * @param c indice dentro de la matriz de adyacencia o nodo
 *
 * @return devuelve el peso del arco entre los nodos f y c
 *
 */
Grafo::TipoPeso & Grafo::operator()(unsigned f, unsigned c)
{
    num_accesos++;

    return matriz.at(f).at(c);
}

/**
 *
 * Devuelve el peso del arco entre dos nodos
 *
 * @param f indice dentro de la matriz de adyacencia o nodo
 * @param c indice dentro de la matriz de adyacencia o nodo
 *
 * @return devuelve el peso del arco entre los nodos f y c
 *
 */
const Grafo::TipoPeso & Grafo::operator()(unsigned f, unsigned c) const
{
    num_accesos++;
 
    return matriz.at(f).at(c);
   
}

/**
 *
 * Metodo que devulve el tamaño de la matriz
 *
 *
 * @return tamaño matriz
 *
 */
unsigned Grafo::size() const
{
    return (unsigned) matriz.size();
}

/**
 *
 * Metodo que llama a metodo auxiliar busquedaProfundidadAux
 *
 */
void Grafo::busquedaProfundidad()
{
    vector<bool>visitados(size());
    busquedaProfundidadAux(1, visitados);
}

/**
 *
 * Metodo que realiza una busqueda en profundidad 
 * a traves del grafo que lo invoca
 * 
 * @param nodo nodo raiz
 * @param visitados conjunto de nodos visitados
 *
 */

void Grafo::busquedaProfundidadAux(unsigned nodo, vector<bool>visitados)
{
    cout << nodo; //Procesar
    visitados[nodo] = true; //Marcar con visitado
    
    for (unsigned i = 0; i < matriz.size(); i++) // Desde
    {
        for (unsigned j = 0; j < matriz[i].size(); j++) // Hasta
        {
            if(matriz[i][j] != 0) // Si el arco desde i hasta j != 0
            {
                if (visitados[j] == false) // Si el arco no fue visitado
                {
                    busquedaProfundidadAux(j, visitados);
                }
            }
        }
    }
}

/**
 *
 * Devuelve el numero de accesos que se produjo en un grafo
 *
 * @return devuelve el numero de accesos que se produjo
 *
 */
unsigned Grafo::getAccesos() const
{
    return num_accesos;
}

/**
 *
 * Crea un grafo no dirigido aleatorio, totalmente
 * conectado (todos los nodos están conectados con todos)
 *
 * @param pmin Peso mínimo que puede tener un arco
 * @param pmax Peso máximo que puede tener un arco.
 *
 */
void Grafo::creaGrafoND(float pmin, float pmax)
{
    float nuevo_peso;
    
    for (int i = 0; i < (int)matriz.size(); i++)
    {
        for (int j = i; j < (int)matriz.size(); j++)
        {
            nuevo_peso = rand() % 2;
            matriz.at(i).at(j) = nuevo_peso;
            matriz.at(j).at(i) = nuevo_peso;
        }
    }
}


/**
 * 
 *  Metodo que muestra el grafo que lo llama 
 * 
 */
void Grafo::mostrar() const
{
    for(int i = 0; i < (int) matriz.size(); i++)
        for(int j = 0; j < (int) matriz.size(); j++)
        {
            cout << setw(5);
            cout << i << " "  << j;
            cout << setw(5);
            cout << " " << matriz.at(i).at(j);
            if (j == ((int) matriz.size()) - 1 || j == ((int)matriz.size()/2) - 1 /* j == 3 en este caso */)
            {
                cout << endl;
            }
            else
                cout << "\t";
        }

}
