#include "lista-dupla-enc.h"
#include "registro-de-humor.h"

NoLista* criarLista(){
    return NULL;
}

int estaVazia(NoLista**l){
    return *l==NULL;
}

void inserirNoFinalLista(NoLista**l, RegistroDeHumor v){ //1
    NoLista*novo;
    novo = (NoLista*)malloc(sizeof(NoLista));
    if(novo!=NULL){
        novo->info = v;
        novo->prox = NULL;
        if(!estaVazia(l)){
            NoLista*ult;
            for(ult = *l; ult->prox!=NULL; ult=ult->prox);
            ult->prox = novo;
            novo->ant = ult;
        }
        else{
            *l = novo;
            novo->ant = NULL;
        }
    }
    else{
        printf("\n\033[0;33mErro ao alocar memoria!\033[0m\n");
    }
}

void removerPorId(NoLista**l){ //2
    if(!estaVazia(l)){
        int _id;
        printf("\033[0;31mDigite o ID do registro a ser excluido: \033[0m");
        scanf("%d",&_id);
        NoLista*p;
        for(p=*l;p!=NULL && p->info.id!=_id;p=p->prox);
        if(p!=NULL){
            if(p->ant==NULL&&p->prox==NULL){ //primeiro e único
                //liberarRegistro(p->info);
                free(p);
                p=NULL;
                *l=p;
                printf("\n\033[0;32mRegistro removido com sucesso!\033[0m\n");
            }
            else if(p->ant==NULL){ //primeiro mas não o único
                *l=p->prox;
                p->prox->ant=NULL;
                //liberarRegistro(p->info);
                free(p);
                printf("\n\033[0;32mRegistro removido com sucesso!\033[0m\n");
            }
            else if(p->prox==NULL){ //último mas não o único
                p->ant->prox = NULL;
                //liberarRegistro(p->info);
                free(p);
                printf("\n\033[0;32mRegistro removido com sucesso!\033[0m\n");
            }
            else{ //nem primeiro nem ultimo
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                //liberarRegistro(p->info);
                free(p);
                printf("\n\033[0;32mRegistro removido com sucesso!\033[0m\n");
            }
        }
        else{
            printf("\n\033[0;33mRegistro nao foi encontrado!\033[0m\n");
        }
    }
    else{
        printf("\n\033[0;33mLista vazia!\033[0m\n");
    }
}

void imprimirRegistroSimples(NoLista*p,int n){
    char* nomesHumor[] = {
        "FELIZ", "TRISTE", "ANSIOSO", "CANSADO", "MOTIVADO", "ESTRESSADO", "NEUTRO"
    };
    printf("\n\033[0;33mRegistro %d:\033[0m\n",n);
    printf("\nID: %d", p->info.id);
    printf("\nDATA: %s", p->info.data);
    printf("\nHUMOR: %s", nomesHumor[p->info.humor]);
    printf("\nMOTIVO: %s", p->info.motivo);
    printf("\nNOTA: %d\n", p->info.notaDoDia);
}

void buscarPorHumor(NoLista**l, int n){ //3
    if(!estaVazia(l)){
        int _h;
        printf("\n\033[0;34m0-Feliz\n1-Triste\n2-Ansioso\n3-Cansado\n4-Motivado\n5-Estressado\n6-Neutro\nDigite o humor a ser buscado: \033[0m");
        scanf("%d",&_h);
        NoLista*p;
        for(p=*l;p!=NULL&&p->info.humor!=_h;p=p->prox);
        if(p!=NULL){
            printf("\n\033[0;35mRegistros existentes: \033[0m\n");
            for(p=*l;p!=NULL;p=p->prox){
                if(p->info.humor==_h){
                    imprimirRegistroSimples(p,n);
                    n++;
                }
            }
            printf("\n\033[0;35mFim dos registros\033[0m\n\n");
        }
        else{
            printf("\n\033[0;33mNenhum registro com esse humor!\033[0m\n");   
        }
    }
    else{
        printf("\n\033[0;33mLista vazia!\033[0m\n");   
    }
}

void imprimirTodosRegistros(NoLista**l, int n){ //4
    if(!estaVazia(l)){
        printf("\n\033[0;35mRegistros existentes: \033[0m\n");
        NoLista* p;
        for(p=*l;p!=NULL;p=p->prox){
            imprimirRegistroSimples(p,n);
            n++;
        }
        printf("\n\033[0;35mFim dos registros\033[0m\n\n");
    }
    else{
        printf("\n\033[0;33mLista vazia!\033[0m\n");
    }
}

void mediaNota(NoLista**l){ //5
    if(!estaVazia(l)){
        float media, pos=0, soma=0;
        NoLista*p;
        int d, _d=0;
        printf("\n\033[0;34m Media dos ultimos x dias, digite valor para x: \033[0m");
        scanf("%d",&d);
        for(p=*l;p->prox!=NULL;p=p->prox);
        for(;p!=NULL&&_d<d;p=p->ant,_d++){
            soma+=p->info.notaDoDia;
            pos++;
        }
        if(pos>0){
            media = soma/pos;
            printf("\n\033[0;35mMedia: %.2f\033[0m\n",media);
        }
    }
    else{
            printf("\n\033[0;33mNao ha nenhum registro!\033[0m\n");    
    }
}

void mostrarHumorMaisFreq(NoLista**l){ //6
    if(!estaVazia(l)){
        NoLista*p;
        int d,_d=0,_fel=0,_tri=0,_ans=0,_can=0,_mot=0,_est=0,_neu=0;
        printf("\n\033[0;34m Humor mais frequente nos ultimos x dias, digite valor para x: \033[0m");
        scanf("%d",&d);
        for(p=*l;p->prox!=NULL;p=p->prox);
        for(;p!=NULL&&_d<d;p=p->ant,_d++){
            switch (p->info.humor){
                case 0: _fel++; break;
                case 1: _tri++; break;
                case 2: _ans++; break;
                case 3: _can++; break;
                case 4: _mot++; break;
                case 5: _est++; break;
                case 6: _neu++; break;
            }
        }
        if(_d>0){
            char* nomesHumor[] = {
            "FELIZ", "TRISTE", "ANSIOSO", "CANSADO", "MOTIVADO", "ESTRESSADO", "NEUTRO"
            };
            int vet[7]={_fel,_tri,_ans,_can,_mot,_est,_neu}, pos=0;
            int maior = vet[0];
            for(int i=1;i<7;i++){
                if(maior<vet[i]){
                    maior=vet[i];
                }
            }
            printf("\n\033[0;35mHumor mais frequente: ");
            for (int i = 0; i < 7; i++) {
                if (vet[i] == maior) {
                    printf("|%s| ", nomesHumor[i]);
                }
            }
            printf("\033[0m\n");
        }
    }
    else{
        printf("\n\033[0;33mNao ha nenhum registro!\033[0m\n");
    }
}

void imprimirMotivoHumor(NoLista**l,int n){ //7
    if(!estaVazia(l)){
        int _h;
        printf("\n\033[0;34m0-Feliz\n1-Triste\n2-Ansioso\n3-Cansado\n4-Motivado\n5-Estressado\n6-Neutro\nDigite o humor a ser buscado: \033[0m");
        scanf("%d",&_h);
        NoLista*p;
        char* nomesHumor[] = {
        "FELIZ", "TRISTE", "ANSIOSO", "CANSADO", "MOTIVADO", "ESTRESSADO", "NEUTRO"
        };
        for(p=*l;p!=NULL&&p->info.humor!=_h;p=p->prox);
        if(p!=NULL){
            printf("\n\033[0;35mMotivos de estar %s: \033[0m\n",nomesHumor[_h]);
            for(p=*l;p!=NULL;p=p->prox){
                if(p->info.humor==_h){
                    imprimirMotivo(p->info,n);
                    n++;
                }
            }
            printf("\n\033[0;35mFim dos registros\033[0m\n\n");
        }
        else{
            printf("\n\033[0;33mNenhum registro com esse humor!\033[0m\n");   
        }
    }
    else{
        printf("\n\033[0;33mLista vazia!\033[0m\n");   
    }
}

void liberarLista(NoLista**l){
    NoLista*p = *l;
    while(p != NULL){
        NoLista *temp = p->prox;
        free(p);
        p = temp;
    }
    *l=NULL;
}

void salvaRegistro(NoLista**l){
    FILE* registrosWrite;
    registrosWrite = fopen("registros.txt","w");
    if(!registrosWrite){
        printf("\n\033[0;33mErro ao abrir o arquivo!\033[0m\n");
        return;
    }
    else if(!estaVazia(l)){
        NoLista*p;
        for(p=*l;p!=NULL;p=p->prox){
            fprintf(registrosWrite, "%d;%s;%d;%s;%d\n", p->info.id, p->info.data, p->info.humor, p->info.motivo, p->info.notaDoDia);
        }
    }
    fclose(registrosWrite);
}

void leRegistro(NoLista**l){
    FILE* registrosRead;
    registrosRead = fopen("registros.txt","r");
    if(!registrosRead){
        printf("\n\033[0;33mErro ao abrir o arquivo!\033[0m\n");
        return;
    }
    char linha[256];
    int id = -1;

    while (fgets(linha, sizeof(linha), registrosRead)) {
        RegistroDeHumor reg_lido;
        char data[Mdata];
        char motivo[Mmotivo];
        sscanf(linha, "%d;%11[^;];%d;%101[^;];%d", &reg_lido.id, data, (int*)&reg_lido.humor, motivo, &reg_lido.notaDoDia);
        strncpy(reg_lido.data, data, Mdata);
        strncpy(reg_lido.motivo, motivo, Mmotivo);
        if (reg_lido.id > id) id = reg_lido.id;

        inserirNoFinalLista(l, reg_lido);
    }
    fclose(registrosRead);
    id_global = id + 1;
}