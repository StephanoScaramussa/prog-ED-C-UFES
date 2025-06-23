#include "registro-de-humor.h"

RegistroDeHumor*criarRegistro(int i_id, char i_data[10], int i_humor, char i_motivo[100], int i_nota){
    RegistroDeHumor*novo=malloc(sizeof(RegistroDeHumor));
    novo->id = i_id;
    novo->data[10] = i_data;
    novo->humor = i_humor;
    novo->motivo[100] = i_motivo;
    novo->notaDoDia = i_nota;
}
void imprimirRegistro(int i_id){
    
}
