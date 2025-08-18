#ifndef REGISTRO_DE_HUMOR_H
#define REGISTRO_DE_HUMOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Mdata 11
#define Mmotivo 101
extern int id_global;

typedef enum{
    FELIZ,
    TRISTE,
    ANSIOSO,
    CANSADO,
    MOTIVADO,
    ESTRESSADO,
    NEUTRO
}Humor;

typedef struct registrodehumor{
    int id;
    char data[Mdata];
    Humor humor;
    char motivo[Mmotivo];
    int notaDoDia;
}RegistroDeHumor;

RegistroDeHumor*criarRegistro();
void imprimirRegistro(RegistroDeHumor*v, int n);
void liberarRegistro(RegistroDeHumor*v);
void imprimirMotivo(RegistroDeHumor v, int n);
#endif