 
/**
 * @file grafo.h
 *
 * @brief Practica 7 TAD de la clase grafo
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 07/10/2017
 */

#ifndef grafo_hpp
#define grafo_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <iomanip>      // std::setw
using namespace std;

class Grafo
{
public:
    typedef int TipoPeso;
    
    Grafo(unsigned);
    TipoPeso & operator()(unsigned f, unsigned c);
    const TipoPeso & operator()(unsigned f, unsigned c) const;
    unsigned size() const;
    void busquedaProfundidad();
    void busquedaProfundidadAux(unsigned, vector<bool>);
    unsigned getAccesos() const;
    void creaGrafoND(float, float);
    void mostrar() const;
    
private:
    vector<vector<TipoPeso>> matriz;
    mutable unsigned num_accesos; //Cuando quieres que el atributo el objeto se siga considerando constante. Por esos se declara mutable.
    
};


#endif /* grafo_h */
