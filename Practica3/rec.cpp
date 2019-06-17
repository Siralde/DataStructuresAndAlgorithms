/**
 *
 * @file rec.cpp
 * @brief Fichero que prueba las funciones recursivas sobre la pila.
 *
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 19/10/2018
 *
 */

#include <stdio.h>
#include "error.h"
#include "pila.h"
#include <iostream>
using namespace std;

const int MAX_ELEMENTOS = 10;

int altura(Pila);
int altura2(Pila&);
int suma(Pila &);
int sumaPares(Pila &);
Pila borrar(Pila, int, unsigned);

int main (void)
{
    Pila p1(MAX_ELEMENTOS);

    try
    {
        for (int i = 1; i < MAX_ELEMENTOS; i++)
        {
            p1.apilar(i);
        }
        p1.apilar(1);
    }
    catch (out_of_range &error)
    {
        cout << "Excepcion: " << error.what() << endl;
    }
    

    cout << "***************************************************************";
    cout << "\nFUNCION QUE INDICA LA ALTURA DE UNA PILA\n";
    int altura_pila = altura(p1);
    cout << "\nAltura de P1 = " << altura_pila << endl;
    
    cout << "***************************************************************";
    cout << "\nFUNCION QUE INDICA LA ALTURA DE UNA PILA POR REFERENCIA\n";
    Pila p2(p1);
    int altura_pila2 = altura2(p2);
    cout << "\nAltura de P2 = " << altura_pila2 << endl;
    
    cout << "***************************************************************";
    cout << "\nFUNCION QUE SUMA TODOS LOS ELEMENTOS DE UNA PILA\n";
    Pila p3(p1);
    int suma_todos_elem = suma(p3);
    cout << "\nSuma de todos los elementos de P3 = " << suma_todos_elem;
    
    cout << "\n\n***************************************************************";
    cout << "\nFUNCION QUE SUMA LOS ELEMENTOS EN POSICIONES PARES DE UNA PILA\n";
    Pila p4(p1);
    int suma_pares_elem = sumaPares(p4);
    cout << "\nSuma de los elementos en las posiciones pares de P1 = " << suma_pares_elem;
    
    cout << "\n\n***************************************************************\n";
    cout << "FUNCION QUE BORRA LOS ELEMENTOS INDICADOS DE UNA PILA\n";
    Pila p5(p1);
    cout << "\nAntes de la Funcion   - P1: ";
    p1.Mostrar();
    p5 = borrar(p5, 1, 3);
    cout << "\nDespues de la Funcion - P2: ";
    p5.Mostrar();
    
    cout << "\n\n\n";
    return 0;
}
/**
 * Devuelve la altura de una pila.
 *
 * @param p Pila de elementos
 *
 * @return al Altura de la pila
 */
int altura(Pila p)
{
	int al;
	
	if(p.vacia())
		al = 0;
	else
	{	
		p.desapilar();
		al = altura(p);
		al+=1;
	}
	
	return al;
}

/**
 * Devuelve la altura de una pila pasada por parametro.
 *
 * @param p Pila de elementos
 *
 * @return al Altura de la pila
 */
int altura2(Pila& p)
{
	int al;
	
	if(p.vacia())
		al = 0;
	else
	{	
		p.desapilar();
		al = altura2(p);
		al+=1;
	}
	
	return al;
}

/**
 * Devuelve la suma de todos los elementos de la pila.
 *
 * @param p Pila llena de elementos
 *
 * @return Suma de todos los elementos de la cima
 */
int suma(Pila & p)
{
    int sum = 0;
    
    if (p.vacia())
    {
        sum = 0;
    }
    else
    {
        sum += p.cimaPila();
        p.desapilar();
        sum += suma(p);
    }
    
    return sum;
}

/**
 * Suma los elementos en posiciones pares de la pila, teniendo en cuenta
 * que la cima es el primer elemento (posición impar).
 *
 * @param p Pila llena de elementos
 *
 * @return Suma de las posiciones pares
 */
int sumaPares(Pila & p)
{
    int sum = 0;
    
    if (p.vacia())
    {
        sum = 0;
    }
    else
    {
        p.desapilar();
        if(p.vacia())
        {
            sum = 0;
        }
        else
        {
            sum += p.cimaPila();
            p.desapilar();
            sum += sumaPares(p);
        }
    }
    return sum;
}

/**
 * Esta función devuelve una pila donde se han borrado las n primeras
 * apariciones del elemento en la pila.
 *
 * @param p Pila
 * @param elem Elemento a eliminar
 * @param n Numero de veces a eliminar el elemento
 *
 * @return p Pila con los elementos elimanados
 */
Pila borrar(Pila p, int elem, unsigned n)
{
    int elem_reapilar = 0;
    
    if (p.vacia() == true || n == 0)
    {
        return p;
    }
    else
    {
        if (p.cimaPila() == elem)
        {
            p.desapilar();
            p = borrar(p, elem, n - 1);
        }
        else
        {
            elem_reapilar = p.cimaPila();
            p.desapilar();
            p = borrar(p, elem, n);
            p.apilar(elem_reapilar);
        }
        return p;
    }



    /*
        PREGUNTAS FINAL DEL GION DE LA PRACTCA
        
            -¿Qué función es más eficiente, altura o altura 2?
                
                Es más eficiente la función altura.

            -¿Por qué?

                Porque al no pasar la pila por referencia, puedo trabajar con la pila directamente, sin temor a que se pierdan los datos.

            -¿En cuál se realizan más accesos?

                Se realizan más accesos en Altura2, ya que necesito crear una pila auxiliar igual a la recibida.
    
    */
}
