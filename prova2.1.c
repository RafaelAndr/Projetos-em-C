#include <stdio.h>

int main() {
    int n, i, j;
      
    printf("Digite um número entre 0 e 15: ");
    scanf("%d", &n);
    if (n < 0 || n > 15)
        printf("Número inválido. Digite um número entre 0 e 15.\n");
 
    
    //exibe os dedos ou a mão fechada
    for (i = 0; i < 3; i++) {
        //caso o número de dedos seja maior que 0, exibe a quantidade de dedos
        if(n > 0)
            for (j = 0; j < 5; j++)
                if (n > 0) {
                    printf("I"); 
                    n--;
                //caso não haja mais dedos para exibir, sai do laço
                } else
                    break;
        //caso não seja maior que 0, exibe a mão fechada
        else
            printf("*");
        printf("\n"); 
    }
    return 0;
}

#include <stdio.h>

void MelhorVendaTotal(float f1[4][5], float f2[4][5], int cat) {
	float somaF1 = 0, somaF2 = 0;
	for(int l = 0; l < 4; l++) {
		somaF1 += f1[l][cat-1];
		somaF2 += f2[l][cat-1];
	}
	if(somaF1 > somaF2)
		printf("A filial 1 tem a maior venda total na categoria %d\n", cat);
	else if(somaF2 > somaF1)
		printf("A filial 2 tem a maior venda total na categoria %d\n", cat);
	else
		printf("Ambas possuem o mesmo valor de venda total na categoria %d\n", cat);
}

int main() {
	float mFilial1[4][5] = {{234, 201, 302, 191, 341}, {342, 213, 432, 201, 309}, {236, 330, 321, 390, 244}, {324, 121, 213, 291, 342}};
	float mFilial2[4][5] = {{223, 291, 222, 291, 441}, {312, 232, 478, 501, 303}, {266, 310, 301, 190, 244}, {304, 101, 113, 291, 312}};
	MelhorVendaTotal(mFilial1, mFilial2, 3);//compara qual a filial tem um total de venda maior na categoria 3
	return 0;
}

#include <stdio.h>

const int NLINHA = 8;
const int NCOLUNA = 11;

int main() {
	const char MAPA[8][11] = {{'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V'},
							  {'V', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'V', 'V', '.'},
							  {'V', 'A', 'A', 'A', 'A', 'A', 'A', 'A', '.', 'C', '.'},
							  {'V', 'A', 'A', 'A', 'A', 'A', 'A', 'A', '.', 'C', 'C'},
							  {'V', 'A', 'A', 'A', 'A', 'A', '.', ' ', '.', 'C', 'R'},
							  {'.', '.', '.', '.', '.', '.', 'C', 'C', 'C', 'R', 'R'},
							  {'.', '.', '.', '.', '.', '.', 'C', 'C', 'R', 'R', 'V'},
							  {'V', 'V', 'A', 'A', 'A', '.', '.', '.', '.', 'V', 'V'}};
	
	char elemento1, elemento2;
	int area1 = 0, area2 = 0;
	printf("INSIRA UM ELEMENTO: ");
	scanf(" %c", &elemento1);
	printf("INSIRA OUTRO ELEMENTO: ");
	scanf(" %c", &elemento2);
	
	for(int l = 0; l < NLINHA; l++) {
		for(int c = 0; c < NCOLUNA; c++)
			if(MAPA[l][c] == elemento1) {
				printf("%3c", MAPA[l][c]);
				area1++;
			} else if(MAPA[l][c] == elemento2) {
				printf("%3c", MAPA[l][c]);
				area2++; 
			} else
				printf("%3c", ' ');
		printf("\n");
	}
	printf("%dm quadrados de %c\n", area1, elemento1);
	printf("%dm quadrados de %c\n", area2, elemento2);
	return 0;
}

#include <stdio.h>

const int VUPA1[24] = {32, 30, 28, 29, 40, 21, 10, 92, 86, 87, 76, 65, 20, 12, 21, 35, 69, 32, 28, 21, 24, 16, 34, 22};
const int VUPA2[24] = {3, 1, 28, 31, 60, 2, 10, 9, 6, 7, 6, 6, 0, 2, 21, 3, 9, 2, 8, 1, 4, 16, 34, 22};

int main() {

	int qtdIguais = 0;
	printf("Horarios de demandas iguais:\n");
	for(int c = 0; c < 24; c++)
		for(int i = 0; i < 24; i++)
			if(VUPA1[c] == VUPA2[i]) {
				printf("%dh (UPA1) e %dh (UPA2)\n", c, i);
				qtdIguais++;
			}
	
	if(qtdIguais == 0)
			printf("Nao ha horario em que as demandas sao iguais.");
    return 0;
}