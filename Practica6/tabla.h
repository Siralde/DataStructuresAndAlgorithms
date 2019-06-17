/**
 * Tabla hash
 * Curso 2018/2019
 * @file tabla.h
 */

#ifndef _TABLA_H
#define _TABLA_H

#include <string>
#include <vector>
#include <iostream>
#include <list>
#include "alumno.h"

using namespace std;

class Tabla
{
public:
    typedef string TipoClave;
    typedef Alumno TipoDato;
        
    Tabla(unsigned); 
    bool buscar(TipoClave, TipoDato&) const; 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(ostream & sal) const;
    float factorCarga() const;
    unsigned posLibres() const;

private:
    typedef list<TipoDato> ListaDatos;    
    vector<ListaDatos> t;
};

#endif
