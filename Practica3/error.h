/**
*
* @file error.h
*
* Fichero de cabecera/interfaz de la clase Error
*
* @version 1.0
* @author Aldemaro Gonzalez, Wilberth Lasso
* @date 19/10/2018
*
*/
#ifndef _ERROR_H
#define _ERROR_H

#include <stdexcept>
using namespace std;

/**
*
*	@brief Clase para el contro de excepciones (Fuera de rango).
*
*/
class ErrorPilaVacia : public out_of_range
{
    public:
        /**
         * Constructor de la Excepcion en caso de la pila Vacia
         */
        ErrorPilaVacia() : out_of_range("Pila Vacia")
        {}
};

/**
*
*	@brief Clase para el contro de excepciones (sobrepasar tamaño de pila).
*
*/
class ErrorPilaLlena : public out_of_range
{
    public:
        /**
         * Constructor de la Excepcion en caso de la pila Llena
         */
        ErrorPilaLlena() : out_of_range("Pila Llena")
        {}
};

#endif /* Error_h */
