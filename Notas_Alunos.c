#include <stdio.h>

struct aluno{
    char nome[20];
    int nota[3];
    int frequencia;
} alunos[80];

int main(){

    int soma, aprovados = 0;
    float media_aluno, media_turma = 0;
    for (int i = 0; i < 80; ++i){
        soma = 0;
        printf("Para o aluno %d, digite o nome: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        printf("Digite a frequencia: ");
        scanf("%d", &alunos[i].frequencia);
        for (int j = 0; j < 3; ++j){
            printf("Digite a nota %d: ", j + 1);
            scanf("%d", &alunos[i].nota[j]);
            soma = soma + alunos[i].nota[j];
        }
        media_aluno = soma / 3.0;
        media_turma = media_turma + media_aluno;
        if ((media_aluno >= 6.0) && (alunos[i].frequencia >= 65)){
            printf("Nome do aluno: %s\n", alunos[i].nome);
            printf("Notas: %d %d %d\n", alunos[i].nota[0], alunos[i].nota[1], alunos[i].nota[2]);
            printf("Média: %.2f\n", media_aluno);
            printf("Situação: Aprovado\n");
            aprovados++;
        }
        else {
            printf("Nome do aluno: %s\n", alunos[i].nome);
            printf("Notas: %d %d %d\n", alunos[i].nota[0], alunos[i].nota[1], alunos[i].nota[2]);
            printf("Média: %.2f\n", media_aluno);
            printf("Situação: Reprovado\n");
        }
        // limpa o buffer do teclado
        while ((getchar()) != '\n');
    }
    media_turma = media_turma / 80.0;
    printf("Média da turma: %.2f\n", media_turma);
    printf("Número de alunos aprovados: %d\n", aprovados);

    return 0;
}