#include "producto.h"
#include <iostream>
#include <fstream>

#include <exception>

using namespace std;

Producto::Producto(int id, string nombre, int existenciasDeProducto)
{
    if(id < 0 || existenciasDeProducto < 0)
    {
        throw ExcepcionNumeroNegativo();
    }

    if(nombre.empty())
    {
        throw ExcepcionDatosVacios();
    }

    if(nombre.length() > 20)
    {
        throw ExcepcionDatoMuyGrande();
    }

    this->id = id;
    strcpy(this->nombre, nombre.c_str());
    this->existenciasDeProducto = existenciasDeProducto;
}

Producto::Producto()
{
    this->id = 0;
    strcpy(this->nombre, "");
    this->existenciasDeProducto = 0;   
}

void Producto::CambiarNombre(string nuevoNombre)
{
    if(nuevoNombre.empty())
    {
        throw ExcepcionDatosVacios();
    }
    if(nuevoNombre.length() > 20)
    {
        throw ExcepcionDatoMuyGrande();
    }
    strcpy(this->nombre, nuevoNombre.c_str());
}

void Producto::CambiarNumeroDeExistencias(int nuevasExistencias)
{
    if(nuevasExistencias < 0)
    {
        throw ExcepcionNumeroNegativo();
    }
    
    this->existenciasDeProducto = nuevasExistencias; 
}

int Producto::ConsultarID()
{
    return this->id;
}

string Producto::ConsultarNombre()
{
    return this->nombre;
}

int Producto::ConsultarNumeroDeExistencias()
{
    return this->existenciasDeProducto;
}

ostream& operator << (ostream &o, const Producto *producto)
{
    o << "[" << producto->id << "] - " << producto->nombre << " - Existencias: " << producto->existenciasDeProducto << endl;
    return o;
}
