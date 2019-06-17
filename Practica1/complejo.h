/**
 * Practica 1.
 *
 * Practicas Estructuras de Datos y Algoritmos
 * Curso 2017 - 2018
 *
 * (c) Departament d'Informatica.
 *     Universitat de Valencia
 *
 * @file complejo.h
 */
 
#ifndef _COMPLEJO_H
#define _COMPLEJO_H

#include <iostream>
#include <math.h>
using namespace std;

/**
 * Complejo.
 * Representacion de numeros complejos en notacion polar
 * 
 */
class Complejo
{
    /**
     * Modulo del complejo
     */
    float mod;

    /**
     * Argumento del complejo.
     * Expresado en radianes.
     */
    float arg;

public:

    /**
    * Crea un complejo inicializandolo a 0 + 0i
    */
    Complejo() {mod = 0; arg = 0;}

    /**
    * Crea un complejo con un valor inicial para el modulo y el argumento.
    * @param m Modulo.
    * @param a Argumento.
    */
    Complejo(float m, float a);

    /**
    * Invariante de clase para complejos en notacion polar.
    * @return Indicador de complejo valido (true) o invalido (false).
    */
    bool inv();

    /**
    * Obtiene la parte real del complejo.
    * @return Parte real del complejo.
    */
    float getReal() const;

    /**
    * Obtiene la parte imaginaria del complejo.
    * @return Parte imaginaria del complejo.
    */
    float getImag() const;

    /**
    * Suma dos complejos.
    * @param c Parametro explicito de la suma.
    * @return Complejo resultado de la suma.
    */
    Complejo operator+(const Complejo c) const;

    /**
    * Multiplica dos complejos.
    * @param c Parametro explicito del producto.
    * @return Complejo resultado del producto.
    */
    Complejo operator*(const Complejo c) const;

    /**
    * Compara dos complejos e indica si son iguales.
    * @param c Parametro explicito de la comparacion.
    * @return Indicador de igualdad.
    */
    bool operator==(const Complejo c) const;

    /**
    * Asigna nuevos valores al modulo y el argumento del complejo.
    * @param m Nuevo modulo.
    * @param a Nuevo argumento.
    */
    void set(float m, float a);

    /**
    * Asigna nuevos valores al modulo y argumento del complejo
    * a partir de nuevas coordenadas polares para el mismo.
    *
    * @param r Coordenada real
    * @param i Coordenada imaginaria
    */
    void setRec(float r, float i);

    /**
    *  Sobrecarga del operador '<<' para sacar la información de un complejo
    *  por un stream (fichero, consola, ...).
    *
    *  @param [in,out] salida  stream por el que vamos a sacar la informacion.
    *  @param [in] num  objeto Complejo que queremos sacar por el stream.
    *  @return  El stream modificado tras su utilizacion
    */
    friend ostream& operator<< (ostream & salida, const Complejo & num);
    
};

#endif
