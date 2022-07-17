#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include <iostream>
#include "producto.h"
#include "excepcionCaracterNoEsNumero.h"
#include "excepcionNumeroNegativo.h"
#include "excepcionDatosVacios.h"
#include "excepcionDatoMuyGrande.h"

using namespace std;

class Tienda {

    char nombre[15]{};
    char direccionInternet[24]{}; 
    char direccionFisica[24]{};
    char telefono[8]{};

    vector<Producto *> productos;
    vector<Producto *> :: iterator iterador;

    public:
    Tienda(string nombre, string direccionInternet, string direccionFisica, string telefono);
    Tienda();
   
    void InsertarProducto(Producto *productoNuevo);
    void EliminarProducto(int posicionProductoAEliminar);
    string ConsultarTodosLosProductos();
    Producto BuscarProductoPorNombre(string nombre);
    Producto* BuscarProductoPorPosicion(int posicionProducto);
    void CambiarNombre(string nuevoNombre);
    void CambiarDireccionInternet(string nuevaDireccionInternet);
    void CambiarDireccionFisica(string nuevaDireccionFisica);
    void CambiarTelefono(string nuevoTelefono);


    void GuardarEnStreamBinario(ostream *streamSalida);
    void CargarDesdeStreamBinario(istream *streamEntrada);
    
    friend ostream& operator << (ostream &o, const Tienda *tienda);
};
















#endif
