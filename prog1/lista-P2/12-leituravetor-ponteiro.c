#include <stdio.h>
#include <stdlib.h>

#define qtd_elementos 6

int* leituraVetor(int *vet_numeros, int *menor, int *maior, int *soma){
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
    *menor = _menor;
    *maior = _maior;
    *soma = _soma;
}

void main(){
    int vet_numeros[qtd_elementos]={
        82,4,2,49,0,100
    }, menor, maior, soma;
    leituraVetor(vet_numeros, &menor, &maior, &soma);
    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);
    printf("Soma: %d", soma);
}
