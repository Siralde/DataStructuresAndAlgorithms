/**
 * @file bomberos.cpp
 *
 * @brief Practica 7 Problema 5. Programa que soluciona el problema planteado en la practica
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 12/12/2017
 */

#include <iostream>
#include <vector>
#include "grafo.h"


/**
 * Constante para los pesos infinitos
 */
const int PESO_INFINITO = 999999;
const int TAM_GRAFO = 10;
/**
 * Distancia entre los nodos 0 y 1 de 50 Km
 */
const int DISTANCIA_FIJA = 50;
/**
 * El resto de distancias entre nodos
 * variara entre 3 Km y 30 Km.
 */
const int DISTANCIA_NODOS_MIN = 3;
const int DISTANCIA_NODOS_MAX = 30;

void CaminoRetenPueblo(int, const vector<float>&, const vector<int>&);
void dijkstra(int, vector<float>&, vector<int>&, const Grafo&);
void SumaDistancias(int, const vector<float>&, const vector<int>&, vector<float>&);

int main(int argc, const char * argv[]) {
    
    vector<int> vecino0(TAM_GRAFO), vecino1(TAM_GRAFO);
    vector<float> pVecino0(TAM_GRAFO), pVecino1(TAM_GRAFO);
    int i;
    
    Grafo g(TAM_GRAFO);

    g.creaGrafoND(DISTANCIA_NODOS_MIN, DISTANCIA_NODOS_MAX);
    
    g(0, 0) = PESO_INFINITO;
    g(1, 1) = PESO_INFINITO;
    g(0, 1) = DISTANCIA_FIJA;
    g(1, 0) = DISTANCIA_FIJA;
    
    cout << "\n***********************************************************************************************\n";
    cout << "Mostramos el grafo aleatorio.\n";
    cout << "***********************************************************************************************\n";
    //mostraremos primero el grafo aleatorio.

        g.mostrar();
    
    /*
     * Calculamos desde el reten 0 el camino minimo hacia todos los pueblos
     */
    dijkstra(0, pVecino0, vecino0, g);
//    cout << endl << "Disktra del reten " << 0 << endl;
//    cout << "Vecino: ";
//    for (j = 0; j < (int)vecino0.size(); ++j)
//    {
//        cout <<  vecino0[j] <<  " | ";
//    }
//    cout << endl << "PVecino: ";
//    for (i = 0; i < (int)vecino0.size(); ++i)
//    {
//        cout << pVecino0[i] << " | ";
//    }
//    cout << endl;
//
    /*
     * Calculamos desde el reten 1 el camino minimo hacia todos los pueblos
     */
    dijkstra(1, pVecino1, vecino1, g);
//    cout << endl << "Disktra del reten " << 1 << endl;
//    cout << "Vecino: ";
//    for (j = 0; j < (int)vecino1.size(); ++j)
//    {
//        cout <<  vecino1[j] <<  " | ";
//    }
//    cout << endl << "PVecino: ";
//    for (i = 0; i < (int)vecino1.size(); ++i)
//    {
//        cout << pVecino1[i] << " | ";
//    }
//    cout << endl << endl;

    
    /*
     * Primero calculamos la distancia maxima entre cada reten y cada uno de los pueblos
     */
    vector<float> distancia_maxima0(pVecino0.size());
    SumaDistancias(0, pVecino0, vecino0, distancia_maxima0);
    vector<float> distancia_maxima1(pVecino1.size());
    SumaDistancias(1, pVecino1, vecino1, distancia_maxima1);
    
    
    /*
     * Mostramos para cada pueblo, qué retén deberá acudir y cuantos kilometros tendra que recorrer.
     */
    cout << "\n***********************************************************************************************\n";
    cout << "Mostramos para cada pueblo, qué retén deberá acudir y cuantos kilometros tendra que recorrer.\n";
    cout << "***********************************************************************************************\n";
    for (i = 2; i < (int) vecino0.size(); i++)
    {
        int pueblo_buscado = i;
        
        if (distancia_maxima0[i] < distancia_maxima1[i])
        {
            if (vecino0[pueblo_buscado] == 0) // Si el reten es vecino del pueblo
            {
                cout << "\nEl pueblo " << pueblo_buscado << " es vecino del reten 0. " ;
                cout << "La distancia que los separa es de: " << distancia_maxima0[i] << " kms."<< endl;
            }
            else // Si no se tienen que recorrer los siguientes pueblos
            {
                cout << "\nPara ir al pueblo " << i << " tienes que salir desde el reten 0 y pasar por los pueblos: ";
                while (pueblo_buscado != 0)
                {
                    cout << pueblo_buscado << ", ";
                    pueblo_buscado = vecino0[pueblo_buscado];
                }
                cout << "la distancia del trayecto es de " << distancia_maxima0[i] << " kms."<< endl;
            }
        }
        else
        {
            if (vecino1[pueblo_buscado] == 1) // Si el reten es vecino del pueblo
            {
                cout << "\nEl pueblo " << pueblo_buscado << " es vecino del reten 1. ";
                cout << "La distancia que los separa es de: " << distancia_maxima1[i] << " kms."<< endl;
            }
            else // Si no se tienen que recorrer los siguientes pueblos
            {
                cout << "\nPara ir al pueblo " << i << " tienes que salir desde el reten 1 y pasar por los pueblos: ";
                while (pueblo_buscado != 1)
                {
                    cout << pueblo_buscado << ", ";
                    pueblo_buscado = vecino1[pueblo_buscado];
                }
                cout << "la distancia del trayecto es de " << distancia_maxima1[i] << " kms." << endl;
            }
        }
    }
    
    cout << endl << endl;
    return 0;
}

/**
 *
 * Como dijkstra solo muestra la distancias a un nodo, esta funcion suma todas las distancias de los vecino
 * para llegar a ese nodo y asi poder comparar cual de los dos retenes llega al pueblo en menos distancia
 *
 * @param reten Reten de bomberos
 * @param pVecino Peso de los vecinos de este reten
 * @param vecino Vecinos de este reten
 * @param distancia_maxima Vector que donde se guarda las distancias maximas
 *
 */
void SumaDistancias(int reten, const vector<float>& pVecino, const vector<int>& vecino, vector<float>& distancia_maxima)
{
    int j;
    
    for (j = 2; j < TAM_GRAFO; ++j)
    {
        int pueblo_buscado = j;
        float distancia_total = 0;
        
        if (vecino[pueblo_buscado] == reten) // Si el reten es vecino la distancia entre los dos sera la maxima
        {
            distancia_maxima[j] = pVecino[pueblo_buscado];
        }
        else
        {
            while (pueblo_buscado != reten)
            {
                distancia_total += pVecino[pueblo_buscado];
                pueblo_buscado = vecino[pueblo_buscado];
            }
            distancia_maxima[j] = distancia_total;
        }
    }
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

