#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No* esqu;
    struct No* dir;
}Arvore;
 
Arvore* criar_arvore(){
    return NULL;
}

Arvore* inserir_arvore(Arvore* raiz, int info){
    if(raiz == NULL){
        Arvore *aux = (Arvore*)malloc(sizeof(Arvore));
        aux->info = info;
        aux->esqu = NULL;
        aux->dir = NULL;
        return aux;
    }else{
        if(info < raiz->info){
            raiz->esqu = inserir_arvore(raiz->esqu, info);
        }
        else if(info > raiz->info){
            raiz->dir = inserir_arvore(raiz->dir, info);
        }
        else{
            printf("Valor já existe\n");
        }
    }
    return raiz;

}

//Imprimir arvore
void imprimir_arvore(Arvore* raiz){
  if(raiz==NULL){
      return;
  }
  if(raiz!=NULL){
      printf("%d\n", raiz->info);
      imprimir_arvore(raiz->esqu);
      imprimir_arvore(raiz->dir);
  }
}
int main(){
    Arvore* raiz = criar_arvore();
    raiz= inserir_arvore(raiz, 2);
    raiz= inserir_arvore(raiz, 3);
    imprimir_arvore(raiz);
    return 0;
}