//
// Created by Admin on 24/11/2019.
//

#ifndef TP_2_DATATYPES_H
#define TP_2_DATATYPES_H
struct Prods
{
    int CodP;
    char Desc[30];
    float PU;
};

struct TVtas
{
    int CodP;
    int CantV;
};

struct TInfo
{
    float TotFact;
};

struct TNodo
{
    TInfo info;
    TNodo* sig;
};

struct TVP
{
    int CodP;
    char Desc[30];
    float PU;
    TNodo* lista;
};
#endif //TP_2_DATATYPES_H
