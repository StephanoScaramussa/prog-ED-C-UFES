#include "registro-de-humor.h"

int id_global = 0;

RegistroDeHumor*criarRegistro(){
    RegistroDeHumor*novo=(RegistroDeHumor*)malloc(sizeof(RegistroDeHumor));
    if(novo!=NULL){
        novo->id = id_global; //id
        id_global++;
        getchar();
        printf("\n\033[0;34mDigite a data de hoje, formato DD/MM/AAAA: \033[0m");
        fgets(novo->data, Mdata, stdin); //data
        printf("\n\033[0;34m0-Feliz\n1-Triste\n2-Ansioso\n3-Cansado\n4-Motivado\n5-Estressado\n6-Neutro\nDigite seu humor de hoje: \033[0m");
        scanf("%d", (int *)&novo->humor); //humor
        getchar();
        printf("\n\033[0;34mDigite o motivo do seu humor: \033[0m");
        fgets(novo->motivo, Mmotivo, stdin); //motivo
        printf("\n\033[0;34mDe uma nota pro seu dia(0 a 10): \033[0m");
        scanf("%d", &novo->notaDoDia); //nota
        printf("\n\033[0;32mHumor registrado com sucesso!\033[0m\n");
        return novo;
    }
    else{
        printf("\nNao foi possivel alocar memoria para o registro.\n");
        return NULL;
    }
}

void imprimirRegistro(RegistroDeHumor*v, int n){
    char* nomesHumor[] = {
        "FELIZ", "TRISTE", "ANSIOSO", "CANSADO", "MOTIVADO", "ESTRESSADO", "NEUTRO"
    };
    printf("\n\033[0;33mRegistro %d:\033[0m\n",n);
    printf("\nID: %d", v->id);
    printf("\nDATA: %s", v->data);
    printf("\nHUMOR: %s", nomesHumor[v->humor]);
    printf("\nMOTIVO: %s", v->motivo);
    printf("NOTA: %d\n", v->notaDoDia);
}

void liberarRegistro(RegistroDeHumor*v){
    free(v);
}

void imprimirMotivo(RegistroDeHumor*v, int n){
    printf("\n\033[0;33mMotivo %d:\033[0m\n",n);
    printf("DATA: %s\n", v->data);
    printf("MOTIVO: %s\n", v->motivo);
}