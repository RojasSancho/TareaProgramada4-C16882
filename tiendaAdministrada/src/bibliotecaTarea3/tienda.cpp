#include "tienda.h"
#include <iostream>
#include <fstream>

#include <exception>
#include "excepcionNumeroNegativo.h"

using namespace std;

Tienda::Tienda(string nombre, string direccionInternet, string direccionFisica, string telefono)
{
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->direccionInternet, direccionInternet.c_str());
    strcpy(this->direccionFisica, direccionFisica.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Tienda::Tienda()
{
    strcpy(this->nombre, "");
    strcpy(this->direccionInternet, "");
    strcpy(this->direccionFisica, "");
    strcpy(this->telefono, "");
}

void Tienda::CambiarNombre(string nuevoNombre) 
{
    strcpy(this->nombre, nuevoNombre.c_str());
}

void Tienda::CambiarDireccionInternet(string nuevaDireccionInternet) 
{
    strcpy(this->direccionInternet, nuevaDireccionInternet.c_str());
}

void Tienda::CambiarDireccionFisica(string nuevaDireccionFisica) 
{
    strcpy(this->direccionFisica, nuevaDireccionFisica.c_str());
}

void Tienda::CambiarTelefono(string nuevoTelefono) 
{
    strcpy(this->telefono, nuevoTelefono.c_str());
}

void Tienda::InsertarProducto(Producto *productoNuevo)
{
    this->productos.push_back(productoNuevo);
}

void Tienda::EliminarProducto(int posicionProductoAEliminar)
{
    if(posicionProductoAEliminar < 0)
    {
        throw ExcepcionNumeroNegativo();
    }

    this->iterador = productos.begin();
    int contador = 0;
    for(Producto *producto : this->productos)
    {
        if(contador == posicionProductoAEliminar)
        {
            productos.erase(this->iterador);
            delete producto;
        }
        iterador++;
        contador++;
    }

}

string Tienda::ConsultarTodosLosProductos()
{
    string productosTodos;
    
    productosTodos += "\nPRODUCTOS ACTUALES DE LA TIENDA: \n";
    for(Producto *producto : this->productos)
    {
        productosTodos += "[" + to_string(producto->ConsultarID()) += "] - " + producto->ConsultarNombre() + " - Existencias: " + to_string(producto->ConsultarNumeroDeExistencias()) + "\n";
    }

    return productosTodos;

}

Producto Tienda::BuscarProductoPorNombre(string nombre)
{
    for(Producto *producto : this->productos)
    {
        if (producto->ConsultarNombre() == nombre)
        {
            return *producto;
        }
    }
}

Producto* Tienda::BuscarProductoPorPosicion(int posicionProducto)
{
    int contador = 0;
    for(Producto *producto : this->productos)
    {
        if (contador == posicionProducto)
        {
            return producto;
        }
        contador++;
    }
}

void Tienda::GuardarEnStreamBinario(ostream *streamSalida)
{
    streamSalida->write(this->nombre, 15);
    streamSalida->write(this->direccionInternet, 24);
    streamSalida->write(this->direccionFisica, 24);
    streamSalida->write(this->telefono, 8);

    for(Producto *producto : this->productos) 
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }  
}

void Tienda::CargarDesdeStreamBinario(istream *streamEntrada)
{
    //Calcular cantidad de registros
    streamEntrada->seekg(0, std::ios::end);
    int cantidadDeBytesEnArchivo = streamEntrada->tellg();
    int cantidadDeProductos = (cantidadDeBytesEnArchivo - 71) / sizeof(Producto);

    //Leer informacion general de la tienda
    streamEntrada->seekg(0, std::ios::beg);

    streamEntrada->read(this->nombre, 15);
    streamEntrada->read(this->direccionInternet, 24);
    streamEntrada->read(this->direccionFisica, 24);
    streamEntrada->read(this->telefono, 8);

    //Leer cada producto
    streamEntrada->seekg(71, std::ios::beg);
    for(int i = 0; i < cantidadDeProductos; i++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto));

        this->InsertarProducto(producto);
    }
}

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << "\nINFORMACION DE LA TIENDA" << endl << "Nombre: " << tienda->nombre << endl << "Direccion de Internet: " << tienda->direccionInternet << endl << "Direccion Fisica: " << tienda->direccionFisica << endl << "Telefono: " << tienda->telefono << endl << endl;
    o << "PRODUCTOS DE LA TIENDA" << endl;

    for(Producto *producto : tienda->productos)
    {
        o << producto;
    }

    return o;
}
