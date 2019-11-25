//
// Created by Admin on 24/11/2019.
//

#ifndef TP_2_DATATYPES_H
#define TP_2_DATATYPES_H
struct tProducto
{
    tProducto() : CodP(0), Desc(""), PU(0.0f)
    {
    }
    int CodP;
    char Desc[30];
    float PU;
};

struct tNodo
{
    tNodo() : totalFacturado(0.0f), sig(nullptr)
    {
    }
    float totalFacturado;
    tNodo* sig;
};

struct tProductoVenta
{
    tProductoVenta() : lista(nullptr)
    {
    }
    tProducto info;
    tNodo* lista;
};
#endif //TP_2_DATATYPES_H
