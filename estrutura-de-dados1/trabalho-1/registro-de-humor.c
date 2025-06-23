#include <stdio.h>
#include <stdlib.h>

typedef struct registrodehumor{
    int id;
    char data[10];
    int humor;
    char motivo[100];
    int notaDoDia;
}RegistroDeHumor;

RegistroDeHumor*criarRegistro(int i_id, char i_data[10], int i_humor, char i_motivo[100], int i_nota);
void imprimirRegistro(int i_id);
void liberarRegistro(int i_id);
