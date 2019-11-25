#include <iostream>
#include "DataTypes.h"
#include <bits/stdc++.h>

/*void CargaProdsaVec(Prods RegP, TVP Vec[], int& top);
void BuscaProdenVec ();
TNodo* InsertaNodo ();
TInfo Elimina1erNodo ();
void ImprimeVecLista ();*/

void CargaProdsaVec(tProductoVenta vecProductoVenta[], int &tope) {

    for (tope = 0; tope < 100; tope++) {
        tProducto nuevoProducto;

        std::cout << "Ingrese un codigo de producto (0 para finalizar la ejecucion): " << std::endl;
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

    return 0;
}
