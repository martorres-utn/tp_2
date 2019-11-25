#include <iostream>
#include "DataTypes.h"
#include <bits/stdc++.h>

void CargaProdsaVec(tProductoVenta vecProductoVenta[], int &tope) {

    for (tope = 0; tope < 100; tope++) {
        tProducto nuevoProducto;// (salta como error)

        std::cout << "[Ingreso de productos] : ingrese un codigo de producto (0 para finalizar la ejecucion): " << std::endl;
        std::cin >> nuevoProducto.CodP;

        if(nuevoProducto.CodP > 0)
        {
            std::cout << "Ingrese una descripcion: " << std::endl;
            std::cin >> nuevoProducto.Desc;

            std::cout << "Ingrese el precio unitario del producto: " << std::endl;
            std::cin >> nuevoProducto.PU;

            vecProductoVenta[tope].info = nuevoProducto;
        }
        else
        {
            break;
        }
    }
}

int BuscaProdEnVec(tProductoVenta vecProductoVenta[], int tope, int codigoProducto)
{
    for(int index = 0; index < tope; index++)
    {
        if(vecProductoVenta[index].info.CodP == codigoProducto)
            return index;
    }
    return -1;
}

tNodo * InsertaNodo(tNodo * &lista, float totalFacturado)
{
    tNodo * nuevo = new tNodo();
    nuevo->totalFacturado = totalFacturado;

    if(lista == nullptr || (lista != nullptr && nuevo->totalFacturado < lista->totalFacturado))
    {
        nuevo->sig = lista;
        lista = nuevo;
    }
    else
    {
        tNodo * ptr = lista->sig;
        tNodo * ant = nullptr;

        while(ptr != nullptr && (nuevo->totalFacturado >= ptr->totalFacturado))
        {
            ant = ptr;
            ptr = ptr->sig;
        }

        nuevo->sig = ptr;
        if(ant != nullptr)
            ant->sig = nuevo;
    }

    return nuevo;
}

float Elimina1erNodo(tNodo *&lista)
{
    if(lista != nullptr)
    {
        float info = lista->totalFacturado;
        tNodo * ptr = lista;
        lista = lista->sig;
        delete ptr;
        return info;
    }
    return -1.0f;
}

void ImprimeVecLista(tProductoVenta vecProductoVenta[], int tope)
{
    for(int index = 0; index < tope; index++)
    {
        std::cout << "CodP: " << vecProductoVenta[index].info.CodP << " - Descripcion: " << vecProductoVenta[index].info.Desc << " - Precio Unitario: " << vecProductoVenta[index].info.PU << std::endl;

        while(vecProductoVenta[index].lista != nullptr)
        {
            float facturacion = Elimina1erNodo(vecProductoVenta[index].lista);
            std::cout << "Facturacion: " << facturacion << std::endl;
        }
    }
}

int main() {
    tProductoVenta vecProductoVenta[100];
    int tope = 0;
    CargaProdsaVec(vecProductoVenta, tope);

    std::cout << "Se cargaron esta cantidad de productos: " << tope << std::endl;

    for(int index = 0; index < tope; index++)
    {
        std::cout << "CodP: " << vecProductoVenta[index].info.CodP << std::endl;
        std::cout << "Descripcion: " << vecProductoVenta[index].info.Desc << std::endl;
        std::cout << "Precio Unitario: " << vecProductoVenta[index].info.PU << std::endl;
    }


    std::cout << "[Ingreso de ventas] : ingrese un codigo de producto 0 para finalizar la ejecucion." << std::endl;

    int codigoProducto = -1;
    int cantidadVentas = 0;

    while(codigoProducto != 0)
    {
        std::cout << "Ingrese Codigo de Producto: " << std::endl;
        std::cin >> codigoProducto;

        int posProducto = BuscaProdEnVec(vecProductoVenta, tope, codigoProducto);
        if(posProducto > -1)
        {
            std::cout << "Ingrese una cantidad de ventas: " << std::endl;
            std::cin >> cantidadVentas;

            //Producto encontrado
            float totalFacturado = vecProductoVenta[posProducto].info.PU * cantidadVentas;
            tNodo * nodoVenta = InsertaNodo(vecProductoVenta[posProducto].lista, totalFacturado);
        }
        else
        {
            std::cout << "Codigo de Producto invalido, ingrese un codigo existente " << std::endl;
        }
    }

    std::cout << "[Informe de ventas]" << std::endl;
    ImprimeVecLista(vecProductoVenta, tope);

    return 0;
}
