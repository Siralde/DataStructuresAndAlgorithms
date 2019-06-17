/**
 * @file test_tabla.cpp
 *
 * @brief Practica 6, Trabajo de inserccion, busqueda, salida por pantalla, sobre Tablas Hash
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 07/10/2017
 */

const int NUMALUMNOS = 1000;

#include "abb.h"
#include "alumno.h"
#include "tabla.h"

#include <iostream>

using namespace std;

int main()
{
    Alumno al;

// CREACION DE LA TABLA
    Tabla t(2 * NUMALUMNOS);
    string dnal0,dnal1,dnal2;
    
// INSERCCION DE ALUMNOS EN LA TABLA
    for(int i = 0; i < NUMALUMNOS; i++)
    {
        Alumno alu(2);
        t.insertar(alu.getDNI(), alu);
        
        if(i == NUMALUMNOS-3)
            dnal2 = alu.getDNI();
        if(i == NUMALUMNOS-2)
            dnal1 = alu.getDNI();
        if(i == NUMALUMNOS-1)
            dnal0 = alu.getDNI();
    }

// MOSTRAR ALUMNOS DE LA TABLA
    t.mostrar(cout);

// BUSCAR 3 DNI
    if(t.buscar(dnal1,al)){
        cout << "\nDNI 1: " << dnal1 << endl;
        cout << al << endl;
    }
    if(t.buscar(dnal2, al)){
        cout << "\nDNI 2: " << dnal2 << endl;
        cout << al << endl;
    }
    if(t.buscar(dnal0,al))
        cout << al << endl;

// MOSTRAR FATOR DE CARGA DE LA TABLA 
    cout << "Factor de carga de la tabala " << t.factorCarga() << endl;

// MOSTRAR NUMERO DE POSICIONES DE LA TABAL LIBRES
    cout << "Posiciones libres de la tabla " << t.posLibres() << endl;

    return 0;
}




/*
    ¿Están los elementos correctamente distribuidos en la tabla?

    Los elementos Sí están bien distribuidos, ya que el porcentaje de colisiones es 22%
    lo cual está dentro del posentaje normal de colisiones

    calculo porsentaje
    1000 alumnos ---------- 100%
    782 pos acupadas ------ X

    X = 78,2 - 100 = 21,8

*/