#include <stdio.h>

int main(){
    int index;
    char * alunos[3][3] = {
        {"Aluno 0", "Pt: 40", "Mat: 70"},
        {"Aluno 1", "Pt: 70", "Mat: 60"},
        {"Aluno 2", "Pt: 60", "Mat: 90"}
    };

    printf("Digite o número do aluno que queira ver as notas...\n");
    printf("Aluno 0, digite 0\n");
    printf("Aluno 1, digite 1\n");
    printf("Aluno 2, digite 2\n");
    scanf("%d", &index);

    printf("As notas do %s são: %s, %s...\n\n", alunos[index][0], alunos[index][1], alunos[index][2]);
    return 0;
}
