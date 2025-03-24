#include <stdio.h>
#include <stdlib.h>
#define max_char 100
#define qtd_carros 10
    typedef struct {
        char modelo[max_char];
        char marca[max_char];
        int ano;
        char cor[max_char];
        float preco[qtd_carros];
    }Carro;
    void insereCarro(Carro *frota){
        for(int i=0;i<qtd_carros;i++){  
            printf("Digite o modelo do %dº carro: ",i+1);
            scanf("%s", frota[i].modelo);
            printf("Digite a marca do %dº carro: ",i+1);
            scanf("%s", frota[i].marca);
            printf("Digite o ano do %dº carro: ",i+1);
            scanf("%d", &frota[i].ano);
            printf("Digite a cor do %dº carro: ",i+1);
            scanf("%s", frota[i].cor);
            printf("Digite o preço do %dº carro: ",i+1);
            scanf("%f", &frota[i].preco[i]);
        }
    }
    void filtraPreco(Carro *frota){
        float precoM;
        printf("Digite o valor máximo: ");
        scanf("%f",&precoM);
        for(int i=0; i<qtd_carros; i++){
            if(frota[i].preco[i]<precoM){
                printf("%s custa: R$%0.2f\n",frota[i].modelo,frota[i].preco[i]);
            }
        }
    }
void main(){
    Carro frota[qtd_carros];
    int caso;
    do{
        printf("Menu de opções\n");
        printf("1 - Inserir carro\n");
        printf("2 - Filtrar carros por valor\n");
        printf("3 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d",&caso);
        switch (caso){
        case 1:
            insereCarro(frota);
            break;
        case 2:
            filtraPreco(frota);
            break;
        case 0:
            printf("Fechando...");
            break;
        default:
            printf("Digite um valor válido.");
            break;
        }
    }
    while(caso != 0);
}
