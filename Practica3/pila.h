/**
* @file pila.h
*
* Fichero de cabecera de la clase Pila (estatica)
*
* @version 1.0
* @author Aldemaro Gonzalez, Wilberth Lasso
* @date 24/10/2018
*/

#ifndef _PILA_H
#define _PILA_H

#include <iostream>
using namespace std;

/**
 * @brief Clase para el manejo de Pilas
 *
 * Clase para manejar la informacion de Pilas.
 * Estan implementadas las operaciones basicas y se ha añadido la sobrecarga
 * del operador '<<' para poder mostrar el contenido completo de la pila por
 * pantalla
 */
class Pila
{
    public:
        /**
         * Crea una pila.
         *
         * @param tam Tamano maximo de la pila
         */
        Pila(int tam);
    
        /**
        * Constructor de copia de la pila.
        *
        * @param p Pila original
        */
        Pila(const Pila& p);
    
        /**
         * Destruye una pila.
         */
        ~Pila();
    
        /**
        * Apila un entero.
        *
        * @param elemento Elemento a introducir
        */
        void apilar (int elemento);
    
        /**
        * Desapila la cima. No desapila.
        */
        void desapilar ();
    
        /**
        * Devuelve el elemento de la cima.
        */
        const int cimaPila();
    
        /**
        * Indica si la pila está vacía.
        *
        * @retval True Si la pila esta vacia.
        * @retval False Si la pila no esta vacia.
        */
        const bool vacia();
    
        /**
        * @brief Devuelve el número de accesos realizados a la pila.
        *
        * @return  Numero de acceso realizados a la pila.
        */
        const unsigned getAccesos();
    
        /**
        * @brief Pone a cero el número de accesos.
        */
        void resetAccesos();

        /**
        * Muestra todo el contenido de la Pila.
        */
        const void Mostrar();
    
        const Pila& operator= (const Pila& p);
    
    
    private:
        /**
         * Tamano Maximo de la pila
         */
        int tamano_pila;
        /**
        * Vector donde guardaremos los elementos de la Pila
        */
        int *datos;
        /**
         * Indice que indica la posicion donde esta la informacion de la cima
         * de la pila
         */
        int cima;
    
        /**
         * Numero de veces a las que se ha accedido la pila.
         */
        unsigned mutable accesos;
    
};

#endif
