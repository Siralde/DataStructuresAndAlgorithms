/**
 * @file test_arbol.cpp
 *
 * @brief Practica 5. Arboles
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 07/10/2017
 */
const int NUMALUMNOS = 1000;

#include "alumno.h"
#include "abb.h"

using namespace std;


/**
 * Funcion principal
 */
int main (void)
{
    ABB arbol;
    Alumno al;
   string dni,dnal1,dnal2;

   
   for(int i = 0; i < NUMALUMNOS; i++)
    {
        Alumno alu(2);
        arbol.insertar(alu.getDNI(), alu);

        if(i == NUMALUMNOS-3)
            dnal2 = alu.getDNI();
        if(i == NUMALUMNOS-2)
            dnal1 = alu.getDNI();
    }
//  1. Mostrar alrbol completo
    arbol.inorden(cout);

//  2. Buscar 3 alumnos y mostrar los que se encuentren
    cout << "\n//////////////////////////////////////////////////" << endl;
    cout << "Busqueda alumnos" << endl;

    if(arbol.buscar(dnal1,al)){
        cout << "\nDNI 1: " << dnal1 << endl;
        cout << al << endl;
    }
    if(arbol.buscar(dnal2, al)){
        cout << "\nDNI 2: " << dnal2 << endl;
        cout << al << endl;
    }
    if(arbol.buscar("26646889H",al))
        cout << al << endl;

//  3. Mostrar altura y tamaño
    cout << "Altura " << arbol.altura();
    cout << "\nTamaño " << arbol.tam() << endl;

//  4. Mostrar cuantos DNI empiezan por 30 y la media de los DNI
    cout << "Empiezan por 30: " << arbol.cuentaDNI30() << endl;
    cout << "Media de los DNI: " << arbol.mediaDNI() << endl;
    
    cout << "\n////////////////////////////////////////////" << endl;
    return 0;
}
 /*
    El arbol, no es equilibrado porque la altura es 18, por lo tanto sabemos que el numero de nodos es
    2^(altura), significa que para que fuera equilibrado, con 1000 alumnos tendria que tener una altura 
    maxima de 10.
 */
 
