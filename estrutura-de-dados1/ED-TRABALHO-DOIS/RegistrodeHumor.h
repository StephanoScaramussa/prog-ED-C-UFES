#ifndef REGISTRODEHUMOR_H
#define REGISTRODEHUMOR_H

typedef enum
{
    FELIZ,
    TRISTE,
    ANSIOSO,
    CANSADO,
    MOTIVADO,
    ESTRESSADO,
    NEUTRO
} Humor;

typedef struct humor
{
    int id;
    char data[12];
    Humor humor;
    char motivo[100];
    int notadoDia;
} RegistroHumor;

RegistroHumor *criarRegistro();

void imprimeRegistro(RegistroHumor *r);

void liberarRegistro(RegistroHumor *r);

void limparBuffer();

#endif