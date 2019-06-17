/**
 * Arbol Binario de Búsqueda (ABB)
 * Curso 2018/2019
 * @file abb.h
 */

#ifndef _ABB_H
#define _ABB_H

#include<iostream>
#include "alumno.h"

using namespace std;

class ABB
{
public:
    typedef string TipoClave;
    typedef Alumno TipoDato;
        
    ABB(); //listo
    ~ABB();//listo
    bool buscar(const TipoClave &, TipoDato&) const; //listo
    bool insertar(const TipoClave &, const TipoDato&); //listo
    bool vacio() const;//listo
    void inorden(ostream & sal) const;//listo
    unsigned altura() const;//listo
    unsigned tam() const;//listo
    long mediaDNI() const;
    unsigned cuentaDNI30() const;
private:
    class NodoBin
    {
    public:
        TipoClave clave; 
        TipoDato  dato;
        NodoBin * izq;
        NodoBin * der;

        NodoBin(): izq(NULL), der(NULL) {};
        NodoBin(TipoClave c, TipoDato d)
        : clave(c), dato(d), izq(NULL), der(NULL) {};
        ~NodoBin();
    };

    typedef NodoBin * PtrNodoBin;

    bool buscarAux(PtrNodoBin, const TipoClave &, TipoDato&) const; 
    bool insertarAux(PtrNodoBin &, const TipoClave &, const TipoDato&); 
    void inordenAux(ostream & sal, PtrNodoBin) const;
    unsigned tamAux(PtrNodoBin) const;
    unsigned alturaAux(PtrNodoBin) const;
    unsigned cuentaDNI30Aux(PtrNodoBin) const;
    long mediaDNIAux(ABB::PtrNodoBin raiz) const;
	

    PtrNodoBin miRaiz;
};

#endif
