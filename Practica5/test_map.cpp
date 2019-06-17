/**
 * @file test_map.cpp
 *
 * @brief Practica 5. Arboles
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez, Wilberth Lasso
 * @date 07/10/2017
 */ 
const int NUMALUMNOS = 1000;

#include <map>
//#include <iostream>
#include <iterator>
#include <string>
#include "alumno.h"

using namespace std;


/**
 * Funcion principal
 */
 int main(void)
 {
    map <string, Alumno> mapalu;
    map <string, Alumno>::iterator iter;
    string dni, dnal1, dnal2;
    size_t tam_dni;
    long media;
    int dni_num;
    double suma = 0;
    bool mayor= false;

// creacion de los alumnos inserccion en el map
    for(int i = 0; i < NUMALUMNOS; i++)
    {
        Alumno alu(3);
        mapalu[alu.getDNI()] = alu;

        if(i == NUMALUMNOS-3)
            dnal2 = alu.getDNI();
        if(i == NUMALUMNOS-2)
            dnal1 = alu.getDNI();
    }

// mostrar alumnos por consola
    for(iter = mapalu.begin(); iter != mapalu.end(); iter++ )
        cout << iter-> second;

// Mostrar busqueda
cout << endl << endl;
    cout << "Busqueda DNI"<< endl;
    iter = mapalu.find(dnal1);
    if(iter != mapalu.end())
        cout << iter-> second << endl;

    iter = mapalu.find(dnal2);
    if(iter != mapalu.end())
        cout << iter-> second << endl;
    iter = mapalu.find("28848294T");
    if(iter != mapalu.end())
        cout << iter-> second << endl;


// mostrar los que empiecen por 30
    iter = mapalu.begin();
    cout << endl << endl;
    cout << endl << endl;
    cout << "DNI empiezan por 30" << endl;
    while(iter != mapalu.end() && !mayor)
    {
        
        dni_num = stoi(iter-> first.substr(0,2));
        
        if(dni_num == 30)
            cout << iter->second << endl;
        else if(dni_num > 30)
            mayor = true;

        iter++;
    }


// hace la media de todos los DNI
    for(iter = mapalu.begin(); iter != mapalu.end(); iter++ )
    {
        dni = iter-> first;
        tam_dni = dni.length();
        dni.erase(tam_dni-1);
        dni_num = stol(dni);
        suma += dni_num;
    }
    media = suma/NUMALUMNOS;
    
    cout << "Media: " << media << endl;

     return 0;
 }
 