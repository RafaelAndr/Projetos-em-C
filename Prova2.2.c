// 1 questão

#include <stdio.h>

int main() {
    char contrato[7];
    int i, cont;

    do {
        printf("Digite o nome do contrato: ");
        scanf("%s", contrato);

        cont = 0;

        for (i = 0; i < 4; i++) {
            if (contrato[i] == '8') {
                contrato[i] = 'B';
                cont = 1;
            } else if (contrato[i] == '3') {
                contrato[i] = 'E';
                cont = 1;
            }
        }

        if (cont) {
            printf("O contrato correto é: %s\n", contrato);
        } else {
            printf("O contrato não precisa de correção.\n");
        }

        printf("\n");

    } while (1);

    return 0;
}


// 2 questão

#include <stdio.h>

int melhor_venda_filial(int MFilial1[4][5], int MFilial2[4][5], int fabricante, int categoria) {
    int vendas_filial1 = 0;
    int vendas_filial2 = 0;
    for (int i = 0; i < 4; i++) {
        if (i == fabricante) {
            vendas_filial1 += MFilial1[i][categoria];
            vendas_filial2 += MFilial2[i][categoria];
        }
    }
    if (vendas_filial1 > vendas_filial2) {
        return 1;
    } else if (vendas_filial2 > vendas_filial1) {
        return 2;
    } else { 
        return 0;
    }
}

int main() {
    int MFilial1[4][5] = {
        {8, 15, 12, 7, 9},
        {3, 20, 10, 8, 15},
        {15, 20, 15, 7, 10},
        {4, 8, 6, 2, 5}
    };
    int MFilial2[4][5] = {
        {12, 20, 15, 12, 10},
        {11, 17, 12, 9, 12},
        {23, 21, 19, 15, 13},
        {8, 16, 18, 5, 5}
    };
    int escolha_fabricante = 1; 
    int escolha_categoria = 2; 
    int filial_melhor_venda = melhor_venda_filial(MFilial1, MFilial2, escolha_fabricante, escolha_categoria);
    
    if (filial_melhor_venda == 1) {
        printf("A filial 1 tem a melhor venda do fabricante %d na categoria %d.\n", escolha_fabricante, escolha_categoria);
    } else if (filial_melhor_venda == 2) {
        printf("A filial 2 tem a melhor venda do fabricante %d na categoria %d.\n", escolha_fabricante, escolha_categoria);
    } else {
        printf("As vendas do fabricante %d na categoria %d são iguais em ambas filiais.\n", escolha_fabricante, escolha_categoria);
    }
    return 0;
}

// 3 questão

#include <stdio.h>

int main() {
    int UPA01[24] = {8, 18, 14, 22, 24, 28, 35, 35, 46, 47, 52, 55, 60, 65, 70, 79, 83, 71, 70, 62, 58, 52, 55, 44};
    int UPA02[24] = {4, 12, 18, 21, 26, 29, 24, 31, 34, 48, 55, 65, 72, 75, 85, 90, 83, 72, 71, 65, 60, 51, 42, 32};

    int total_upa1 = 0, total_upa2 = 0;
    float media_upa1, media_upa2;
    int horarios = 18 - 8 + 1;

    for (int i = 8; i <= 18; i++) {
        total_upa1 += UPA01[i];
        total_upa2 += UPA02[i];
    }
    media_upa1 = (float) total_upa1 / horarios;
    media_upa2 = (float) total_upa2 / horarios;

    if (media_upa1 > media_upa2) {
        printf("A UPA-01 tem a maior media nos horarios de 8 as 18hrs, com aproximadamente %.2f pacientes.\n", media_upa1);
    } else if (media_upa2 > media_upa1) {
        printf("A UPA-02 apresenta a maior media nos horarios de 8 as 18hrs, com aproximadamente %.2f pacientes.\n", media_upa2);
    } else {
        printf("Nenhuma UPA apresenta maior media de procura nos horarios de 8 as 18hrs.\n");
    }

    return 0;
}

// 4 questão

#include <stdio.h>
#include <string.h>

void traduz_mensagemP(char mensagemP[]) {
    int i, tamanho;
    tamanho = strlen(mensagemP);

    for (i = 1; i < tamanho; i++) {
        if (mensagemP[i] == 'p') {
            printf("%c", mensagemP[i + 1]);
            i++;
        } else {
            printf("%c", mensagemP[i]);
        }
    }
    printf("\n");
}

int main() {
    char mensagemP[201];
    int escolha;

    do {
        printf("Digite um texto na linguagem P: ");
        fgets(mensagemP, 201, stdin);

        traduz_mensagemP(mensagemP);

        printf("Deseja traduzir outra mensagem? (1-Sim / 0-Nao): ");
        scanf("%d", &escolha);
        getchar();

    } while (escolha == 1);

    return 0;
}
