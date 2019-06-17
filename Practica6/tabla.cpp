/**
 * @file tabla.cpp
 *
 * @brief Implementacion del TAD Tabla Hash
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 07/10/2017
 */

#include "tabla.h" 
#include "alumno.h"
using namespace std;

/**
 *
 * Constructor de la clase tabla hash que recibe
 * el tamaño como parametro
 *
 * @param tam tamaño de la tabal hash
 *
 */
Tabla::Tabla(unsigned tam)
{
    t.resize(tam);
}

/**
 *
 * Busca un elemento en la tabla
 *
 * @param elem Clave del elemento a buscar
 * @param valor Datos del Elemento a buscar
 *
 *
 * @return encontrado Encontrado o no el elemneto buscada
 */
bool Tabla::buscar(TipoClave elem, TipoDato & valor) const
{
    bool encontrado;
    unsigned i;
    list<TipoDato>::const_iterator it;

    i = hash(elem);
    it = t[i].begin();
    
    
    while ((it != t[i].end()) && (it->getDNI() != elem))
    {
        ++it;
    }
    
    if (it == t[i].end())
    {
        encontrado = false;
    }
    else
    {
        valor = *it;
        encontrado = true;
    }
    
    return encontrado;
}


/**
*
* Metodo de la clase que inserta un elemento dentro de la tabla 
*
* @param elem clave del elemento a insertar
* @param valor contenido del elemento
*
*/
void Tabla::insertar(TipoClave elem, const TipoDato& valor)
{
    unsigned i;

    i = hash(elem);
    t[i].push_back(valor);
}

/**
*
* Funcion Hash que determina la posicion del elemento de un vector
*
* @param elem Elemento al que hay que encontrarle un indice
*
* @return indice dentro del vector t
*/
unsigned Tabla::hash(TipoClave elem) const
{
    unsigned hash = 5381;
    unsigned indice;
    size_t n = elem.length();

    for (size_t i = 0; i < n; i++)
    {
        hash = (hash * 33) + elem[i];
        //cout << hash << endl;
    }

    indice = hash % t.size();
    //cout << indice << endl;
    return indice;
}

/**
 *
 * Muestra todos los elementos de la tabla
 *
 * @param sal Output donde mostraremos cada elemento de la tabla
 *
 */
void Tabla::mostrar(ostream & sal) const
{
    for (auto & t_elem : t)
    {
        for (auto & l_elem : t_elem)
        {
            sal << l_elem;
        }
    }
}

/**
 *
 * Metodo que calcual el factor de carga de la tabla hash
 *
 * 
 * @return faca factor de carga de la tabla
 *
 */
float Tabla::factorCarga() const
{
    float faca = 0;
    float numele = 0;

    for(int i = 0; i < t.size(); i++)
        numele += t[i].size();

    faca = numele/t.size();

    return faca;
}

/**
 *
 * Suma las posiciones libres de la tabla
 *
 * @return Posiciones libres de la tabla
 *
 */
unsigned Tabla::posLibres() const
{
    unsigned libres = 0;
    
    for (auto & t_elem : t) {
        if (t_elem.empty())
            libres++;
    }
    
    return libres;
}