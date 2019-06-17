/**
 * @file complejoMain.cpp
 * @brief Practica Estructura de Datos y Algoritmos. Práctica 1.
 * @brief Clase main del programa.
 * 
 * @version 1.0
 * @author Aldemaro Gonzalez y Wilberth Lasso
 * @date 03/10/2018
 * 
 */

#include "complejo.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<Complejo> genVector(Complejo, int);

int main ()
{
    
//     Complejo resultado, resultado2 , a(6, 45), b(3,15);
    
//     resultado = a * b;
    
//     a.setRec(3, 5);
//     b.setRec(3, 5);

//     resultado2 = a + b;
    
//     cout <<  resultado2.getReal() << " " << resultado2.getImag() << "i" << "\n";
    
    Complejo c (2,M_PI/3);
    vector <Complejo> v;

    int n = 10;

    v = genVector(c, n);

    for(int i = 0; i < n; i++)
    {
        cout << v[i];
    }

    return 0;
}


vector<Complejo> genVector(Complejo c, int n)
{
    vector <Complejo> vec(n);

    vec[0] = Complejo(1,0);
    
    for(int i = 1; i < n; i++)
    {
        vec[i] = vec[i-1] * c;
    }

    return vec;
}
