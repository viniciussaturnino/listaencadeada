#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
  int dado;
  struct celula *prox;
}celula;

//Função que insere elemento no final de uma lista encadeada
void insere(celula *le, int x){
  celula *p;
  celula *nova = malloc(sizeof(celula));
  nova->dado = x;
  for(p=le; p->prox!=NULL; p=p->prox);
  nova->prox = p->prox;
  p->prox = nova;
}

//Função que imprime a lista
void imprime(celula *le){
  if(le==NULL)
    printf("NULL\n");
  else{
    for(celula *p=le; p->prox!=NULL; p=p->prox)
      printf("%d -> ",p->prox->dado);
    printf("NULL\n");
  }
}

//Função recursiva para impressão da lista
void imprime_rec(celula *le){
  if(le->prox==NULL)
    printf("NULL\n");
  else{
    printf("%d -> ",le->prox->dado);
    imprime_rec(le->prox);
  }
}

//Função que busca por um elemento na lista e retorna sua posição
void busca(celula *le, int x){
  celula *p;
  int i=1;
  if(le==NULL)
    printf("Lista Vazia\n");
  else{
    for(p=le; p!=NULL&&p->prox->dado!=x; p=p->prox)
      i++;
    if(p!=NULL)
      printf("Elemento está no %dº nó da lista\n",i);
    else
      printf("Elemento não está na lista\n");
  }
}

//Função que remove a primeira ocorrência de um elemento dentro da lista
void remove_elemento(celula *le, int x){
  celula *p;
  for(p=le; p->prox!=NULL&&p->prox->dado!=x; p=p->prox);
  if(p->prox!=NULL){
    celula *tmp = p->prox;
    p->prox = tmp->prox;
    free(tmp);
  }
  else{
    printf("Elemento não está na lista\n");
  }
}

//Função que remove todas as ocorrências de um elemento dentro da lista
void remove_todos_elementos(celula *le, int x){
  celula *p = le;
  while(p->prox!=NULL){
    if(p->prox->dado==x){
      celula *tmp = p->prox;
      p->prox = tmp->prox;
      free(tmp);
    }
    else
      p=p->prox;
  }
}

int main(){
  celula *le;
  le = malloc(sizeof(celula));
  le->prox = NULL;
  int n,x;
  printf("Informe o tamanho da lista encadeada: ");
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    printf("Insira o %dº elemento: ",i+1);
    scanf("%d",&x);
    insere(le,x);
  }
  printf("\n");
  imprime_rec(le);
  printf("\nInforme o elemento a ser buscado na lista: ");
  scanf("%d",&x);
  busca(le,x);
  printf("\nInforme o elemento que deseja remover: ");
  scanf("%d",&x);
  remove_todos_elementos(le,x);
  //remove_elemento(le,x);
  printf("\n");
  imprime_rec(le);
  return 0;
}
