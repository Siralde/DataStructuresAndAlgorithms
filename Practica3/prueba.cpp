/**
*
* @file prueba.cpp
* @brief Fichero que prueba los metodos de la clase pila.
*
* @author Aldemaro Gonzalez, Wilberth Lasso
* @date 19/10/2018
*
*/
#include "error.h"
#include "pila.h"
#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 10;


int main (void)
{
    //1. Crear una Pila con máximo de 10 elementos.
    Pila p1(MAX_ELEMENTOS);
    
    //2. Desapilar 1 elemento.
    try
    {
        p1.desapilar();
    }
    catch (out_of_range &error)
    {
        cout << "Excepcion: " << error.what() << endl;
    }
    
    //3. Introducir los naturales del 1 al 11.
    try
    {
        for (int i = 1; i <= 11; i++)
        {
            p1.apilar(i);
        }
    }
    catch (out_of_range &error)
    {
        cout << "Excepcion: " << error.what() << endl;
    }
    
    //4. Mostrar la pila.
    cout << "\nP1: ";
    p1.Mostrar();
    
    //5. Mostrar el número de accesos realizados
    cout << "\n\tNumero de Accesos Realizados: " << p1.getAccesos();
    
    cout << "\n\n";
    return 0;
    
}
