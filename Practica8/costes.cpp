/**
 * @file coste.cpp
 *
 * @brief Practica 8 Comparación de los algoritmos de coloreado de un grafo de backtracking y voraz
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 24/12/2018
 */


#include <vector>
#include <iostream>
#include <fstream>

#include "grafo.h"


using namespace std;


const int REPETICIONES = 1000;
const int TALLA_INCIAL = 5;
const int TALLA_FINAL = 40;
const int INCREMENTO = 1;
const int NO_ARCO = 0;
const int SI_ARCO = 1;

int colorearVoraz(vector<int>&, const Grafo&);
void colorearBacktracking(int i, int numeroColores, const Grafo& g, vector<int>& coloresM ,int& nColorM, vector<int>& colores);
float fVAUX(unsigned, float&);
float fBAUX(unsigned, float&);
void evaluar(unsigned, unsigned, int, float (*t)(unsigned, float&), ostream &, ostream &);
float maxColor(const vector<int>&);

int main(void)
{

    ofstream fichero_coste_medio_voraz, fichero_voraz_sol, fichero_coste_medio_bt, fichero_bt_sol;

    // Algoritmo Voraz
    fichero_coste_medio_voraz.open("voraz.dat");
    fichero_voraz_sol.open("voraz_sol.dat");
    if(!fichero_coste_medio_voraz || !fichero_voraz_sol)
    {
        cout << "\nError abriendo el fichero para la escritura del coste medio voraz o media de colores" << endl;
    }
    else
    {
        srand(1);
        evaluar(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fVAUX, fichero_coste_medio_voraz, fichero_voraz_sol);
        fichero_voraz_sol.close();
        fichero_coste_medio_voraz.close();
    }
    
    // Backtracking
    fichero_coste_medio_bt.open("bt.dat");
    fichero_bt_sol.open("bt_sol.dat");
    if(!fichero_coste_medio_bt || !fichero_bt_sol)
    {
        cout << "\nError abriendo el fichero para la escritura del coste medio backtracking o media de colores" << endl;
    }
    else
    {
        srand(1);
        evaluar(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fBAUX, fichero_coste_medio_bt, fichero_bt_sol);
        fichero_bt_sol.close();
        fichero_coste_medio_bt.close();
    }

    return 0;
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
void evaluar(unsigned ini, unsigned fin, int inc, float (*t)(unsigned, float&), ostream & file, ostream & fileMediaColores)
{
    while(ini <= fin)
    {
        float media_colores = 0;
        file << ini << " " << t(ini, media_colores) << endl;
        fileMediaColores << ini << " " << media_colores << endl;
        ini = ini + inc;
    }
}

/**
 *
 * Funcion que genera los pesos de un grafo de tamaño n con los pesos aleatorios entro
 * los parametros enviados, aplicandole depues el algorimo voraz para colorear el grafo
 *
 * @param n Tamaño del vector
 * @return numero de accesos al grafo
 *
 */
float fVAUX(unsigned n, float& media_colores)
{
    Grafo g(n);
    vector<int> colores(n);
    
    for(int i = 0; i < REPETICIONES; i++)
    {
        g.creaGrafoND(NO_ARCO, SI_ARCO);
        colorearVoraz(colores, g);
        
        media_colores += maxColor(colores);
    }
    media_colores = media_colores/REPETICIONES;

    return g.getAccesos()/REPETICIONES;
}


/**
 *
 * Funcion que genera los pesos de un grafo de tamaño n con los pesos aleatorios entro
 * los parametros enviados, aplicandole backtracking para colorear el grafo
 *
 * @param n Tamaño del vector
 * @return numero de accesos al grafo
 *
 */
float fBAUX(unsigned n, float& media_colores)
{
    Grafo g(n);
    vector<int> colores(n);
    vector<int> coloresM(n,n + 1);
    int nColorM = n + 1;
    
    for(int i = 0; i < REPETICIONES; i++)
    {
        g.creaGrafoND(NO_ARCO, SI_ARCO);
        colorearBacktracking(0, 0, g, coloresM, nColorM, colores);

        media_colores += maxColor(coloresM);
    }
    media_colores = media_colores/REPETICIONES;
    
    return g.getAccesos()/REPETICIONES;
}

/**
 *
 * Calcula la media de colores utilizados para colorear un grafo
 *
 * @param colores Vector de colores utilizados
 *
 * @return Media de colores utilizados
 *
 */
float maxColor(const vector<int>& colores)
{
    int sumatorio = 0;
    for (auto color : colores)
    {
        if(sumatorio < color)
            sumatorio = color;
    }
    
    return sumatorio;
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
int colorearVoraz(vector<int>& colores, const Grafo& g)
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
 * 
 * Viendo los graficos generados, podemos observar como el algoritmos de backtracking, realiza
 * menos accesos al grafo, y utiliza menos colores para pintarlos.
 * 
 * El número de accesos está directamente relacionado con la poda del algaritmo, la cual permite en muchos 
 * casos realizar dicho acceso.
 * 
 * En cuanto a la cantidad de colores, vemos como es coherente, ya que el backtrackin nos ofrece
 * siempre la mejor solucion, a diferencia del voraz que nos asegura una solución pero no la más
 * optima.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * **/