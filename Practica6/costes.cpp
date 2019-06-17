 
/**
 * @file costes.cpp
 *
 * @brief Practica 6 Ejercicio 4 Calculo de coste Temporal, sobre las busquedas en las estructuras Map, ABB, Tabla hash
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 28/11/2017
 */
#include "alumno.h"
#include "tabla.h"
#include "abb.h"
#include <map>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

const int REPETICIONES = 1000;
const int TALLA_INCIAL = 500;
const int TALLA_FINAL = 5000;
const int INCREMENTO = 500;

void calculoCoste (unsigned, unsigned, int, void (*f)(unsigned),ostream &);
void fAuxTabla(unsigned);
void fAuxArbol(unsigned);
void fAuxMap(unsigned);

int main() {
    
    ofstream fichero_coste_tabla, fichero_coste_arbol, fichero_coste_map;
    
    //Fichero a escribir de la Funcion A
    fichero_coste_tabla.open("costemedioTabla.dat");
    if (!fichero_coste_tabla)
    {
        cout << "\nError abriendo el fichero para la escritura del coste de la tabla" << endl;
    }
    else
    {
        calculoCoste(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fAuxTabla, fichero_coste_tabla);
        fichero_coste_tabla.close();
    }
    
    //Fichero a escribir del Arbol
    fichero_coste_arbol.open("costemedioArbol.dat");
    if (!fichero_coste_arbol)
    {
        cout << "\nError abriendo el fichero para la escritura del coste del arbol" << endl;
    }
    else
    {
        calculoCoste(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fAuxArbol, fichero_coste_arbol);
        fichero_coste_arbol.close();
    }
    

    //Fichero a escribir de la funcion Map
    fichero_coste_map.open("costemedioMap.dat");
    if (!fichero_coste_map)
    {
        cout << "\nError abriendo el fichero para la escritura del coste del arbol" << endl;
    }
    else
    {
        calculoCoste(TALLA_INCIAL, TALLA_FINAL, INCREMENTO, fAuxMap, fichero_coste_map);
        fichero_coste_map.close();
    }

    return 0;
}


/**
 *
 * Funcion auxiliar que crea una tabla, del doble de los alumnos
 * pasados como parametro, la llena y hace 100 busquedas a DNI exitosa
 *
 *
 * @param talla numero de alumnos a crear
 *
 */
void fAuxTabla(unsigned talla)
{
    Alumno alum_enc;
    Tabla t(2*talla);
    vector<string> dni(talla);
    
    for(int i = 0; i < (int) talla; i++)
    {
        Alumno alu(2);
        dni.push_back(alu.getDNI());
        t.insertar(alu.getDNI(), alu);
    }
    
    for (int j = 0; j < REPETICIONES; j++)
        for (auto dni_elem : dni)
            t.buscar(dni_elem, alum_enc);
}

/**
 *
 * Funcion auxiliar que crea un ABB, que llena con el numero de alumnos
 * pasado como parametro, y hace 100 busquedas a DNI exitosa
 *
 *
 * @param n numero de alumnos a crear
 *
 */
void fAuxArbol(unsigned n)
{
    ABB arbol;
    Alumno al;
    vector <string> dni(n);

    for(int i = 0; i < (int) n; i++)
    {
        Alumno alu(2);
        dni.push_back(alu.getDNI());
        arbol.insertar(alu.getDNI(), alu);
    }

    for(int j = 0; j < REPETICIONES; j++)
        for(auto dni_elem: dni)
            arbol.buscar(dni_elem, al);
}

/**
 *
 * Funcion auxiliar que crea un mapa, que llena con el numeor de alumnos
 * pasado como parametro, y hace 100 busquedas a DNI exitosa
 *
 *
 * @param n numero de alumnos a crear
 *
 */
void fAuxMap(unsigned n)
{
    map<string, Alumno> mapalu;
    map<string, Alumno>::iterator iter;
    vector <string> dni(n);

    for(int i = 0; i < (int) n; i++)
    {
        Alumno alu(2);
        mapalu[alu.getDNI()] = alu;
        dni.push_back(alu.getDNI());
    }

    for(int j = 0; j < REPETICIONES; j++)
        for(auto dni_elem: dni)
            iter = mapalu.find(dni_elem);
}
/**
 *
 * Funcion que que calcula el tiempo de ejecucion de CPU
 *
 *
 * @param ini Posicion Inicial del Vector
 * @param fin Posicion Final del Vector
 * @param inc Cantidad en la que se incrementa
 * @param t Funcion a utilizar
 * @param file fichero donde se escribiran los datos
 *
 */

void calculoCoste(unsigned ini, unsigned fin, int inc, void(*t)(unsigned), ostream & file)
{
    struct timespec ini_time, fin_time;
    double time;
    
    
    for(int i = (int) ini; i <= (int) fin; i+=INCREMENTO)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);
        
        t(i);
        
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin_time);
        time = (fin_time.tv_sec - ini_time.tv_sec) + (fin_time.tv_nsec * 1.0e-9 - ini_time.tv_nsec * 1.0e-9);
        file << i << " " << (time/REPETICIONES)/i << endl;
        
    }


    /*
    *
    *   ¿Que conclusiones obtienes de las graficas?
    *
    *       Con las graficas obtenidas par la busqueda de un unico elemto según las estructuras determinamos que:
    *           La busqueda con Map es la mas rapida, seguida de el arbol, lo cual tiene sentido ya que un mapa
    *           es un tipo de Arbol Binario de Busqueda, y por ultimo tenemos las tablas hash, teniendo en cuenta
    *           que la eficiencia de las tablas hash vienen influenciadas por la eficiencia de su funcion hash.
    *
    *
    *
    */



}