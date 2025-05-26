#include <stdio.h>
#include <stdlib.h>

#define qtd_elementos 6

typedef struct{
    int menor;
    int maior;
    int soma;
}Resultados;

void leituraVetor(int *vet_numeros, Resultados *vet_resultados){
    int _menor=vet_numeros[0], _maior=vet_numeros[0], _soma=0;
    for(int i=0;i<qtd_elementos;i++){
        if(vet_numeros[i]<_menor){
            _menor = vet_numeros[i];
        }
        if(vet_numeros[i]>_maior){
            _maior = vet_numeros[i];
        }
        _soma += vet_numeros[i];
    }
    vet_resultados->menor = _menor;
    vet_resultados->maior = _maior;
    vet_resultados->soma = _soma;
}

void main(){
    int vet_numeros[qtd_elementos]={
        82,4,2,49,0,100
    };
    Resultados vet_resultados;
    leituraVetor(vet_numeros, &vet_resultados);
    printf("Menor: %d\n", vet_resultados.menor);
    printf("Maior: %d\n", vet_resultados.maior);
    printf("Soma: %d", vet_resultados.soma);
}
