#include <iostream>
#include "DataTypes.h"
#include <bits/stdc++.h>

void CargaProdsaVec(Prods RegP, TVP Vec[], int& top);
void BuscaProdenVec ();
TNodo* InsertaNodo ();
TInfo Elimina1erNodo ();
void ImprimeVecLista ();

int main() {
    TVP VP[100];
    Prods RP;
    TInfo RV;
    int tope = 0;

    std::cout << "Ingrese un codigo de producto (0 para finalizar la ejecucion): ";
    std::cin >> RP.CodP;

    while (RP.CodP != 0){
        std::cout << "Ingrese una descripcion: ";
        std::cin >> RP.Desc;
        std::cout << "Ingrese el precio unitario del producto: ";
        std::cin >> RP.PU;
        CargaProdsaVec(RP, VP, tope);
    }


    return 0;
}

void CargaProdsaVec(Prods RegP, TVP Vec[100], int &top) {
    int i = 0;
    for (i=0; i < 100; i++) {
        Vec[i].CodP = RegP.CodP;
        Vec[i].PU = RegP.PU;
        Vec[i].lista = NULL;
        //Vec[i].Desc = RegP.Desc; (lo comento ya que no me lo permite hacer el programa)
    }
    return;
}