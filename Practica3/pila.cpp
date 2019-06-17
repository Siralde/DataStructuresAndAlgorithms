/**
*
* @file pila.cpp
*
* Implementación de los métodos de la clase Pila
*
* @version 1.0
* @author Aldemaro Gonzalez, Wilberth Lasso
* @date 25/10/2018
*
*/

#include "pila.h"
#include "error.h"


Pila::Pila(int tam)
{
    tamano_pila = tam;
    datos = new int[tamano_pila];
    cima = -1;
    accesos = 0;
}

Pila::Pila(const Pila& p)
{
    int i = 0, c_aux = p.cima;
    
    this->tamano_pila = p.tamano_pila;
    this->datos = new int[tamano_pila];
    this->cima = -1;
    this->accesos = 0;
    
    while (c_aux >= 0)
    {
        this->apilar(p.datos[i]);
        c_aux--;
        i++;
    }
//    this->accesos = 0;
}

Pila::~Pila()
{
    delete[] datos;
}

void Pila::apilar(int elemento)
{
    if (cima < tamano_pila - 1)
    {
        cima++;
        datos[cima] = elemento;
        accesos++;
    }
    else
    {
        throw ErrorPilaLlena();
    }
}

void Pila::desapilar()
{
    if (vacia())
    {
        throw ErrorPilaVacia();
    }
    else
    {
        cima--;
        accesos++;
    }
}

const int Pila::cimaPila()
{
    int elemento;
    
    if (cima == -1)
    {
        throw ErrorPilaVacia();
    }
    else
    {
        elemento = datos[cima];
        accesos++;
    }
    return elemento;
}

const bool Pila::vacia()
{
    if (cima == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const unsigned Pila::getAccesos()
{
    return accesos;
}

void Pila::resetAccesos()
{
    accesos = 0;
}

const void Pila::Mostrar()
{
    int i;
    
    for (i = 0; i <= cima; i++)
    {
        cout << datos[i];
        if (i != cima)
            cout << ",";
    }
//    cout << "\tTamano Pila: " << tamano_pila << "\tCima: " << cima;    
}

const Pila& Pila::operator= (const Pila& p)
{
    int i = 0, c_aux = p.cima;

    if (this->tamano_pila != p.tamano_pila)
    {
        delete[] this->datos;
        this->datos = new int[p.tamano_pila];
    }

    this->tamano_pila = p.tamano_pila;

    while (c_aux >= 0)
    {
        this->datos[i] = p.datos[i];
        c_aux--;
        i++;
    }

    this->accesos = p.accesos;
    this->cima = p.cima;

    return (*this);
}
