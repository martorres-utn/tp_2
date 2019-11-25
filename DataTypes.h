//
// Created by Admin on 24/11/2019.
//

#ifndef TP_2_DATATYPES_H
#define TP_2_DATATYPES_H
struct tProducto
{
    int CodP;
    char Desc[30];
    float PU;
};

struct tVenta
{
    int CodP;
    int CantV;
};

struct tNodo
{
    float totalFacturado;
    tNodo* sig;
};

struct tProductoVenta
{
    tProducto info;
    tNodo* lista;
};
#endif //TP_2_DATATYPES_H
