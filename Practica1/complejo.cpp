/*
 * Practica 1.
 *
 * Practicas Estructuras de Datos y Algoritmos
 * Curso 2012 - 2013
 *
 * (c) Departament d'Informatica.
 *     Universitat de Valencia
 *
 * @file complejo.cpp
 */

#include <stdlib.h>
#include <iostream>
#include <assert.h>

#include "complejo.h"

using namespace std;

/** 
 * Diferencia maxima que se considera cero al comparar dos reales
 */
const float CERO = 0.0001;

Complejo::Complejo(float m, float a) 
{
    mod = m;
    arg = a;
    
    assert(inv());
} 

bool Complejo::inv()
{
    if(arg <= M_PI && arg >= -M_PI)
    {
        return true;
    }
    else
        return false;
}

float Complejo::getReal() const 
{
    return mod * cos(arg);
}

float Complejo::getImag() const 
{
    return mod * sin(arg);
}

Complejo Complejo::operator+(const Complejo c) const 
{
    Complejo resultado;
    float num1_real, num1_img, num2_real, num2_img, res_real, res_img;
    
    num1_real = this->getReal();
    num1_img = this->getImag();
    
    num2_real = c.getReal();
    num2_img = c.getImag();
    
    res_real = num1_real + num2_real;
    res_img = num1_img + num2_img;
    
    resultado.setRec(res_real, res_img);
    
    return resultado;
}

Complejo Complejo::operator*(const Complejo c) const 
{
    Complejo resultado;
    
    resultado.mod = this->mod * c.mod;
    resultado.arg = this->arg + c.arg;
    
    return resultado;
}

bool Complejo::operator==(const Complejo c) const 
{
    if(mod == 0 && c.mod == 0)
        return true;
    else
        return (fabs(mod - c.mod) < CERO && fabs(arg - c.arg) < CERO);
}

void Complejo::set(float m, float a)
{
    mod = m; 
    arg = a;
    
    assert(inv());
}

void Complejo::setRec(float re, float im) 
{
    mod = sqrt(re*re + im*im);
    if(re == 0 && im == 0)
        arg = 0;
    else
        arg = atan2(im, re);

    assert(inv());
}

ostream& operator<< (ostream & salida, const Complejo & num)
{
    salida << "|";
    salida << num.mod;
    salida << "|";
    salida << num.arg;
    salida << "\n";
    
    return salida;
}
