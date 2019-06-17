#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

/**
 * Numero de veces que se repetira la funcion B para calcular su coste medio
 */
const int MAX = 100000;

void fa(unsigned, float&);
void fb(vector <int>, float&);
float faAUX(unsigned);
float fbPAUX(unsigned);
float fbMAUX(unsigned);
float fbMDAUX(unsigned n);
void evaluar(unsigned, unsigned, int, float (*t)(unsigned), ostream &);

int main(void)
{
    ofstream fichero_funcA, fichero_funcB_mejor, fichero_funcB_peor, fichero_funcB_medio ;
    
    //Fichero a escribir de la Funcion A
    fichero_funcA.open("at.data");
    if (!fichero_funcA)
    {
        cout << "Error abriendo el fichero de escritura FUNCION A" << endl;
    }
    else
    {
        evaluar(4, 100, 4, faAUX, fichero_funcA);
        
        fichero_funcA.close();
    }
    
    //Fichero a escribir de la Funcion B ( MEJOR CASO )
    fichero_funcB_mejor.open("bt.data");
    if (!fichero_funcB_mejor)
    {
        cout << "Error abriendo el fichero de escritura FUNCION B MEJOR CASO" << endl;
    }
    else
    {
        evaluar(4, 100, 4, fbMAUX, fichero_funcB_mejor);
        
        fichero_funcB_mejor.close();
    }
    
    //Fichero a escribir de la Funcion B ( PEOR CASO )
    fichero_funcB_peor.open("bt2.data");
    if (!fichero_funcB_peor)
    {
        cout << "Error abriendo el fichero de escritura FUNCION B PEOR CASO" << endl;
    }
    else
    {
        evaluar(4, 100, 4, fbPAUX, fichero_funcB_peor);
        
        fichero_funcB_peor.close();
    }
    
    //Fichero a escribir el coste medio Funcion B 
    fichero_funcB_medio.open("medio.data");
    if (!fichero_funcB_medio)
    {
        cout << "Error abriendo el fichero de escritura FUNCION B COSTE MEDIO" << endl;
    }
    else
    {
        evaluar(4, 100, 4, fbMDAUX, fichero_funcB_medio);
        
        fichero_funcB_medio.close();
    }
    
    
    return 0;
}

/**
 *
 * Cuenta el numero de pasos de la Funcion A
 *
 * @param n Talla de la funcion
 * 
 * @return Numero de pasos
 * 
 */
float faAUX(unsigned n)
{
    float pasos = 0;
    fa(n, pasos);
    
    return pasos;
}

/**
 *
 * Cuenta el numero de pasos de la Funcion B en el mejor caso
 *
 * @param n Talla de la funcion
 * 
 * @return Numero de pasos
 * 
 */
float fbMAUX(unsigned n)
{
    float pasos = 0;
    
    vector <int> vec(n);
    vec[0] = 1;
    vec[n-1] = 0;
    
    fb(vec, pasos);
    
    return pasos;
}

/**
 *
 * Cuenta el numero de pasos de la Funcion B en el peor caso
 *
 * @param n Talla de la funcion
 * 
 * @return Numero de pasos
 * 
 */
float fbPAUX(unsigned n)
{
    float pasos = 0;
    
    vector <int> vec(n);
    for(int i = 0; i < n; i++)
    {
        vec[i] = 1;
    }
    
    fb(vec, pasos);
    
    return pasos;
}

/**
 *
 * Cuenta el numero de pasos de la Funcion B en el caso medio
 *
 * @param n Talla de la funcion
 * 
 * @return Numero de pasos
 * 
 */
float fbMDAUX(unsigned n)
{
    float pasos;
    int num;
    
    pasos = 0;
    
    for(int i = 0; i < MAX; i++)
    {
        
        vector <int> vec(n);
        for(int j = 0; j <= n; j++)
        {
            num = rand()%2;
            vec[j] = num;
        }
        
        fb(vec, pasos);
    }
    
    pasos = pasos/MAX;
    
    return pasos;
}

/**
 *
 * Implementacion de la Funcion A
 *
 * @param n Talla de la funcion
 * @param pasos Contador de pasos
 * 
 * @return Numero de pasos
 * 
 */
void fa (unsigned n, float & pasos)
{
    int k = 0;
    pasos = 0;
    
    
    pasos++;
    for(int i = 0; i < n-1; i++)
    {
        pasos++;
        for(int j = 0; j <= i-1; j++)
        {
            pasos++;
            k+=j;
            pasos++;
        }
        pasos++;
    }
    pasos++;
    
    // cout << "Pasos: " << pasos;
    
}

/**
 *
 * Implementacion de la Funcion B
 *
 * @param vec Vector a utilizar por la funcion b
 * @param pasos Contador de pasos
 * 
 * @return Numero de pasos
 * 
 */
void fb (vector <int> vec, float & pasos)
{
    int a, b;
    bool cic;
    
    
    a = 0;
    pasos++;
    b = vec.size()-1;
    pasos++;
    
    while ((a<b) && (vec[a] = vec[b]))
    {
        pasos++;
        a++;
        pasos++;
        b--;
        pasos++;
    }
    pasos++;
    if(a>=b)
    {
        pasos++;
        cic = true;
        pasos++;
    }
    else
    {
        pasos++;
        cic = false;
        pasos++;
    }
    //cout << "Pasos: " << pasos << endl;
    //cout << "Valor: " << 5+3*floor(n/2)<< "----- " << n/2;
}

/**
 *
 * Evaluara diferentes tallas para diferentes funciones
 *
 * @param ini   Primera talla del problema
 * @param fin   Ultima talla del problema
 * @param inc   Incremeto de la talla
 * @param t     Funcion a utilizar
 * @param file  Fichero en el cual depositar la informacion
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
