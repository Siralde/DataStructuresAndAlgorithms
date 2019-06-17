 
/**
 * Implementación de la clase Alumno
 * @file abb.cpp
 * @brief implementacion de los metodos de la clase abb.h
 */

/**
 * Constante que dice por el numero que debe comenzar el DNI
 */
const unsigned DEBE_COMENZAR = 30;

#include "abb.h"
#include <iostream>

using namespace std;

/**
 * Constructor por defecto del arbol
 *
 */
ABB::ABB()
{
    miRaiz = nullptr;
}

/**
 *Destructor del arbol
 *
 */
ABB::~ABB()
{
    delete miRaiz;
}

/**
 *Destructor del nodo
 *
 */
ABB::NodoBin::~NodoBin()
{
    delete izq;
    delete der;
}

/**
 *
 * Llama a alturaAux que calcula la altura de un arbol.
 *
 * @param elem clave de busqueda
 * @param valor Dato que contiene el nodo
 * 
 * @return buscarAux() boolean que indica si se ha encontrado el elemnto
 *
 */
bool ABB::buscar(const TipoClave & elem, TipoDato& valor) const
{return buscarAux(miRaiz,elem,valor);} 


/**
 *
 * Metodo que llama a insertarAux para insertar un alumno en el arbol
 *
 * @param elem clave del nodo del arbol
 * @param valor Dato que contiene el nodo
 * 
 * @return insetarAux valor a insertar
 *
 */
bool ABB::insertar(const TipoClave & elem, const TipoDato & valor)
{return insertarAux(miRaiz, elem, valor);}

/**
 *
 * Metodo que nos dice si el arbol está vacio
 *
 * @return bool indica si el arbo está vacio o no
 *
 */
bool ABB::vacio() const
{
    if(miRaiz == nullptr)
        return false;
    else 
        return true;
}

/**
 *
 * Llama a inodenAux que calcula la altura de un arbol.
 *
 * @param sal ostream para mostrar los alumnos
 * @return inordenAux fuancion que muestra los elementos del arbo
 *
 */
void ABB::inorden(ostream & sal) const
{return inordenAux(sal, miRaiz);}

/**
 *
 * Llama a alturaAux que calcula la altura de un arbol.
 *
 * @return alturaAux altura del arbol
 *
 */
unsigned ABB::altura() const
{return alturaAux(miRaiz);}
/**
*
* Llama a tamAux que calcula el tamano de un arbol.
*
* @return tamAux tamano del arbol
*
*/ 
unsigned ABB::tam() const
{return tamAux(miRaiz);}


/**
 *
 * Calcula la media de todos las claves de los
 * elementos del ABB
 *
 * @return media de todos los elementos de ABB
 *
 */
long ABB::mediaDNI() const
{
    long media;
    
    media = mediaDNIAux(miRaiz) / tam();
    
    return media;
}

/**
 *
 * Metodo que llama a la uan funcion que devuelve el numero de 
 * DNI que empiezan por 30
 *
 * @return cuentaDNI30Aux cantidad de elemntos que cumplen la condicion
 *
 */
unsigned ABB::cuentaDNI30() const
{return cuentaDNI30Aux(miRaiz);}

/**
 *
 * Metodo auxiliar que busca dentro del arbol la clave que se le pasas
 * como parametro y devuelve un booleano que indica el exito de la busqueda
 *
 * @param raiz Raiz del arbol binario
 * @param elem clave del nodo
 * @param valor dato del nodo, en este caso un alumno
 *
 * @return ok  booleano que indica si la operacion de inseccion tuvo exito
 *
 */
bool ABB::buscarAux(ABB::PtrNodoBin raiz, const TipoClave & elem, TipoDato & valor) const
{
    if(raiz == nullptr)
        return false;
    if(elem < raiz->clave)
        return(buscarAux(raiz->izq, elem, valor) );
    else if(raiz->clave < elem)
        return(buscarAux(raiz->der, elem, valor) );
    else // encontrado
    {
        valor = raiz->dato;
        return true;
    }
}



/**
 *
 * Metodo auxiliar que inserta un elemento es su posicion correspondiente
 * dentro del arbol
 *
 * @param raiz Raiz del arbol binario
 * @param elem clave del nodo
 * @param valor dato del nodo, en este caso un alumno
 *
 * @return ok  booleano que indica si la operacion de inseccion tuvo exito
 *
 */
bool ABB::insertarAux(ABB::PtrNodoBin & raiz, const TipoClave & elem, const TipoDato & valor)
{ 
    bool ok = true;
    if(raiz == nullptr)
        raiz = new ABB::NodoBin(elem, valor);
    else if(elem < raiz->clave)
        return(insertarAux(raiz->izq, elem, valor) );
    else if(raiz->clave < elem)
        return(insertarAux(raiz->der, elem, valor) );
    else // ya existe !
        ok = false;

    return ok;
    
}


/**
 *
 * Metodo auxiliar que muestra los elementos del arbol
 * 
 *
 * @param sal ostream para mostrar los elemntos del arbol
 * @param raiz Raiz del arbol binario
 *
 */
void ABB::inordenAux(ostream & sal, ABB::PtrNodoBin raiz) const
{
    if(raiz != nullptr)
    {
        inordenAux(sal, raiz->izq);
        sal << raiz->clave << "-" << raiz->dato << " ";
        inordenAux(sal, raiz->der);
    }
}
/**
 *
 * Metodo auxiliar que calcula el tamano del arbol binario de busqueda
 * 
 * @param raiz Raiz del arbol
 *
 * @return tamano cantidad de elemntos del arbol
 *
 */
unsigned ABB::tamAux(ABB::PtrNodoBin raiz) const
{
    if(raiz != nullptr)
    {
        return 1 + tamAux(raiz->izq) + tamAux(raiz->der);
    }
    else
        return 0;
}

/**
 *
 * Metodo auxiliar que calcula la altura del arbol binario de busqueda
 *
 * @param raiz Raiz del arbol
 * 
 * @return altura del arbol
 *
 */
unsigned ABB::alturaAux(ABB::PtrNodoBin raiz) const
{
    if(raiz != nullptr)
    {
        unsigned alt_izq = alturaAux(raiz->izq);
        unsigned alt_der = alturaAux(raiz->der);
        if(alt_izq >= alt_der)
            return 1 + alt_izq;
        else
            return 1 + alt_der;
    }
    else
        return 0;
}

/**
 *
 * Metodo auxiliar que cuenta cuantos dni comienzan por 30
 *
 * @param raiz Raiz del arbol
 *
 * @return cant_dni Numero de DNI que empiezan por 30
 *
 */
unsigned ABB::cuentaDNI30Aux(ABB::PtrNodoBin raiz) const
{
    unsigned cant_dni = 0;
    unsigned primeros_digitos_raiz;
    
    
    if(raiz == nullptr)
    {
        cant_dni = 0;
    }
    else
    {
        primeros_digitos_raiz = stoi(raiz->clave.substr(0,2));
        
        if(DEBE_COMENZAR == primeros_digitos_raiz) // Si la raiz es empieza por 30 sumar 1 y ver los dos hijos
        {
            cant_dni = 1 + cuentaDNI30Aux(raiz->der) + cuentaDNI30Aux(raiz->izq);
        }
        else if(primeros_digitos_raiz > DEBE_COMENZAR)
        {
            cant_dni = cuentaDNI30Aux(raiz->izq);
        }
        else if(primeros_digitos_raiz < DEBE_COMENZAR)
        {
            cant_dni = cuentaDNI30Aux(raiz->der);
        }
    }
    
    return cant_dni;
}


/**
 *
 * Metodo auxiliar que calcula la media de todos las claves de los
 * elementos del ABB
 *
 * @param raiz Raiz del arbol binario
 *
 * @return suma  Suma de todos los DNI del ABB
 *
 */
long ABB::mediaDNIAux(ABB::PtrNodoBin raiz) const
{
    string dni;
    size_t tam_dni;
    long valor;
    double suma = 0;
    
    if (raiz == nullptr)
    {
        suma = 0;
    }
    else
    {
        dni = raiz->clave;
        tam_dni = dni.length();
        dni.erase(tam_dni - 1);
        valor = stol(dni);
        suma = valor + mediaDNIAux(raiz->izq) + mediaDNIAux(raiz->der);
    }
    
    return suma;
}