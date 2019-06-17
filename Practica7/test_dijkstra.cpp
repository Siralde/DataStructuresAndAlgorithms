 
/**
 * @file test_dijkstra.cpp
 *
 * @brief Practica 7 programa que puega la implementacion del algoritmo Disjkstra y la implmentacion de la clase grafo
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 07/10/2017
 */

#include <iostream>
#include <vector>
#include "grafo.h"

/**
 * Constante para los pesos infinitos
 */
const int PESO_INFINITO = 999999;

const int TAM_GRAFO = 6;

void dijkstra(int, vector<float>&, vector<int>&, const Grafo&);


int main(int argc, const char * argv[]) {

    vector<int> vecino(TAM_GRAFO);
    vector<float> pVecino(TAM_GRAFO);

    Grafo g(TAM_GRAFO);
    
    g(0, 1) = 3;
    g(0, 3) = 2;
    g(0, 4) = 5;
    
    g(1, 2) = 1;
    
    g(2, 3) = 3;
    g(2, 4) = 4;
    
    g(3, 1) = 1;
    g(3, 2) = 2;
    
    g(4, 3) = 6;
    g(4, 1) = 10;

    try
    {
        g(8, 1) = 10;
    }
    catch (out_of_range &error)
    {
        cout << endl << "Excepcion: \n  " << error.what() << endl;
    }
    
    g.creaGrafoND(3,30);

    //MOSTRAR EL GRAFO GENERADO ALEATORIAMENTE
    g.mostrar();

    
    dijkstra(0, pVecino, vecino, g);
    
    // MOSTRA LAS SOLUCIONES
    cout<< endl<< endl << "Nodo: ";
    for (int i = 0; i < (int)vecino.size(); ++i)
        cout <<  1 + i <<  " ";

    cout << endl << "Arco: ";

    for (int i = 0; i < (int)vecino.size(); ++i)
        cout <<  vecino[i] + 1<<  " ";

    cout << endl << "Peso: ";

    for (int i = 0; i < (int)vecino.size(); ++i)
        cout << pVecino[i]<< " ";
    
    cout << endl << endl;
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
            sum_arcos = pVecino[nodo_p_minimo] + g(nodo_p_minimo, j); // matriz[nodo_p_minimo][j]
            if ( !(visitados[j]) && (sum_arcos < pVecino[j]) )
            {
                pVecino[j] = sum_arcos;
                vecino[j] = nodo_p_minimo;
            }
        }
    }
}
