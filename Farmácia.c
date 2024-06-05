 #include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

struct TpFarma{
	char Nome[20];
	float Preco;
	int QEstoque;
  char Categoria[20];
  };
  
typedef struct TpFarma TpFARMA;

TpFARMA RgFarma;
  
FILE *ArqFarma;

long int Tamanho=20*sizeof(char)+sizeof(float)+sizeof(int)+20*sizeof(char);

void Incluir() {
  char R;
  char NovoMedicamento[20];
  do {
    printf("* inclusao *\n\n");
    printf("Nome: ");
    scanf("%s", NovoMedicamento);
    int medicamentoExistente = 0;

    fseek(ArqFarma, 0, 0); 
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
      if (strcmp(NovoMedicamento, RgFarma.Nome) == 0) {
        medicamentoExistente = 1;
        break;
      }
    }

    if (medicamentoExistente) {
      printf("Este Medicamento já existe, escolha um diferente.\n");
      continue;
    }

    strcpy(RgFarma.Nome, NovoMedicamento);
    printf("Preco: ");
    scanf("%f", &RgFarma.Preco);
    printf("Estoque: ");
    scanf("%d", &RgFarma.QEstoque);
    fseek(ArqFarma, 0, 2); 
    printf("Qual a categoria? ");
    scanf("%s", RgFarma.Categoria);
    fwrite(&RgFarma, Tamanho, 1, ArqFarma);
    printf("\nNova inclusao? S/N ");
    scanf(" %c", &R);
    R = toupper(R);
  } while (R != 'N');
}


void Excluir() {
  printf("Qual Medicamento deseja excluir? ");
  char Medicamento[20];
  scanf("%s", Medicamento);
  int Achou = 0;
  long int posicaoAtual = ftell(ArqFarma);
  fseek(ArqFarma, 0, 0);  
  
  FILE* TempArq = fopen("TempFarmacos.dat", "w+b");  

  while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
    if (strcmp(RgFarma.Nome, Medicamento) == 0) {
      Achou = 1;
      continue; 
    }
    fwrite(&RgFarma, Tamanho, 1, TempArq); 
  }

  fclose(ArqFarma);
  fclose(TempArq);

  remove("Farmacos.dat"); 
  rename("TempFarmacos.dat", "Farmacos.dat"); 
  
  if (Achou) {
    printf(">>> Exclusao efetuada com sucesso! <<<\n");
  } else {
    printf("Medicamento inexistente!\n");
  }

  ArqFarma = fopen("Farmacos.dat", "a+b");  
  fseek(ArqFarma, posicaoAtual, 0);  
}

long int TArquivo(){
	fseek(ArqFarma,0,2);
	long int R=ftell(ArqFarma)/Tamanho;
	return R;}
	
void Alterar(){
  if (TArquivo()!=0){
  fclose(ArqFarma);
  ArqFarma=fopen("Farmacos.dat","r+b");
  //system("cls");
  printf("*** alterar ***\n\n");  
  fseek(ArqFarma,0,0);
  printf("Qual farmaco? ");
  char Farmaco[20];
  scanf("%s",Farmaco);
  int Achou=0;
  do {
	fread(&RgFarma,Tamanho,1,ArqFarma);
	if (strcmp(RgFarma.Nome,Farmaco)==0){
	  Achou=1;	
	  printf("Nome: %s\n",RgFarma.Nome);
    printf("Valor: %.2f\n",RgFarma.Preco);
    printf("Estoque: %d\n",RgFarma.QEstoque);}
    printf("Categoria : %s\n", RgFarma.Categoria);
  }
  while (!feof(ArqFarma)&&(Achou==0));
  if (Achou==0)
    printf("Registro inexistente!"); 
  else{
    char SubOpcao;
		printf("\nOpcoes de alteracao:\n");
		printf("P - Alterar Preco\n");
		printf("Q - Alterar Quantidade\n");
    printf("C - Alterar Categoria\n");
		printf("S - Sair\n");
		printf("Escolha uma opcao: ");
		scanf(" %c", &SubOpcao);
		SubOpcao = toupper(SubOpcao);

		if (SubOpcao == 'P') {
			printf("Qual o novo preco? \n");
			scanf("%f", &RgFarma.Preco);
		} else if (SubOpcao == 'Q') {
			printf("Qual a nova quantidade? \n");
			scanf("%d", &RgFarma.QEstoque);
    } else if (SubOpcao == 'C') {
			printf("Qual a nova categoria? \n");
			scanf("%s", RgFarma.Categoria);
		} else if (SubOpcao == 'S'){
    printf("Saindo do submenu de alteracao.\n");
    } else {
    printf("Opcao invalida.\n");
    }
    fseek(ArqFarma,-Tamanho,1);
    fwrite(&RgFarma,Tamanho,1,ArqFarma);
    printf(">>> Alteracao efetuada com sucesso! <<<\n");}
  fclose(ArqFarma);
  ArqFarma=fopen("Farmacos.dat","a+b");}
  else{
    printf("Arquivo Vazio. Nao existem dados a alterar.");}
  return;}

void Consultar(){
  //system("cls");
  printf("*** consulta ***\n\n");  
  fseek(ArqFarma,0,0);
  printf("Qual farmaco? ");
  char Farmaco[20];
  scanf("%s",Farmaco);
  int Achou=0;
  do{
	  fread(&RgFarma,Tamanho,1,ArqFarma);
	  if (strcmp(RgFarma.Nome,Farmaco)==0 && RgFarma.QEstoque != -1){
	    Achou=1;	
	    printf("Nome: %s\n",RgFarma.Nome);
      printf("Valor: %.2f\n",RgFarma.Preco);
      printf("Estoque: %d\n",RgFarma.QEstoque);}
      printf("Categoria : %s\n", RgFarma.Categoria);
    }
    while (!feof(ArqFarma)&&(Achou==0));
  if (Achou==0)
    printf("Registro inexistente!");  
  //system("pause");
  return;}

void ConsultaCategoria() {
	printf("Qual a categoria? ");
	char Categoria[20];
	scanf("%s", Categoria);
  printf("\n\n");
	int Achou = 0;
	
	fseek(ArqFarma, 0, 0); 

	while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
		if (strcmp(RgFarma.Categoria, Categoria) == 0 && RgFarma.QEstoque != -1) {
			Achou = 1;
			printf("Nome: %s\n", RgFarma.Nome);
			printf("Valor: %.2f\n", RgFarma.Preco);
			printf("Estoque: %d\n", RgFarma.QEstoque);
			printf("Categoria: %s\n", RgFarma.Categoria);
			printf("***\n\n");
		}
	}

	if (!Achou) {
		printf("Nenhum medicamento encontrado nessa categoria.\n");
	}
}


void LTodos(){
  //system("cls");
  printf("*** lista todos ***\n\n"); 
  fseek(ArqFarma,0,0);
  do {
	fread(&RgFarma,Tamanho,1,ArqFarma);
	if (!feof(ArqFarma) && RgFarma.QEstoque != -1){
	    printf("Nome: %s\n",RgFarma.Nome);
      printf("Valor: R$%.2f\n",RgFarma.Preco);
      printf("Estoque: %d\n",RgFarma.QEstoque);
      printf("Categoria : %s\n", RgFarma.Categoria);
      printf("***\n\n");}}
  while (!feof(ArqFarma));
  //system("pause");
  }

int main(){
  ArqFarma=fopen("Farmacos.dat","a+b");
  char Opcao;
  do{
	  //system("cls");
    printf("\n\n> > > Pague Pouco < < < \n\n");
    printf("Que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Excluir \n");
    printf("A - Alterar \n");
    printf("C - Consultar \n");
    printf("X - ConsultaCategoria \n");
    printf("T - Listar Todos \n");
    printf("S - Sair \n\n");
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    switch (Opcao){
      case 'I': Incluir(); break;
      case 'E': Excluir(); break;
      case 'A': Alterar(); break;
      case 'C': Consultar(); break;
      case 'X': ConsultaCategoria(); break;
      case 'T': LTodos(); break;}}
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;}