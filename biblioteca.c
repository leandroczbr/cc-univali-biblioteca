#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int diaParaNumero(const char *dia) {
    const char *dias[] = {"segunda", "terca", "quarta", "quinta", "sexta", "sabado", "domingo"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(dia, dias[i]) == 0) return i + 1;
    }
    return 0;
}

int lerIntValidado(const char *mensagem, int min, int max) {
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%d", &valor) == 1 && valor >= min && valor <= max) break;
        printf("Valor inválido! Tente novamente.\n");
        while (getchar() != '\n'); // limpa buffer
    }
    return valor;
}

void limparBuffer() {
    while (getchar() != '\n');
}

int main() {
    system("chcp 65001");
    char matricula[20], curso[50], dia[10];
    int idade, categoria, debito, diaNum, hora;

    printf("=== SISTEMA DE ACESSO À BIBLIOTECA ===\n");

    printf("Digite a matrícula: ");
    scanf("%s", matricula);
    limparBuffer();

    idade = lerIntValidado("Digite a idade (13 a 100): ", 13, 100);

    printf("Digite o curso: ");
    scanf(" %[^\n]", curso);
    limparBuffer();

    printf("\nCategoria do usuário:\n");
    printf("1 - Aluno de Graduação\n");
    printf("2 - Aluno de Pós-graduação\n");
    printf("3 - Professor\n");
    printf("4 - Visitante\n");
    categoria = lerIntValidado("Escolha (1-4): ", 1, 4);

    debito = lerIntValidado("Está em débito com a biblioteca? (1 - Sim / 0 - Não): ", 0, 1);

    while (1) {
        printf("Digite o dia da semana (ex: segunda, terca): ");
        scanf("%s", dia);
        diaNum = diaParaNumero(dia);
        if (diaNum != 0) break;
        printf("Dia inválido! Tente novamente.\n");
    }

    hora = lerIntValidado("Digite a hora do acesso (0 a 23): ", 0, 23);


    // Lógica de acesso
    if (categoria == 3) {
        printf("Acesso autorizado. Professores tem acesso irrestrito.\n");
    } else if (categoria == 1) { // Graduação
        if (debito == 1) {
            printf("Acesso negado. Aluno de graduação com débito.\n");
        } else if (diaNum >= 1 && diaNum <= 5 && hora >= 8 && hora <= 22) {
            printf("Acesso autorizado. Aluno de graduação dentro do horário.\n");
        } else {
            printf("Acesso negado. Biblioteca fechada nesse horário para graduação.\n");
        }
    } else if (categoria == 2) { // Pós-graduação
        if (debito == 1) {
            printf("Acesso negado. Aluno de pós-graduação com débito.\n");
        } else if (diaNum >= 1 && diaNum <= 6 && hora >= 8 && hora <= 22) {
            printf("Acesso autorizado. Aluno de pós-graduação dentro do horário.\n");
        } else {
            printf("Acesso negado. Biblioteca fechada nesse horário para pós-graduação.\n");
        }
    } else if (categoria == 4) { // Visitante
        if (debito == 1) {
            printf("Acesso negado. Visitantes não podem ter débitos.\n");
        } else if (diaNum >= 1 && diaNum <= 5 && hora >= 9 && hora <= 17) {
            printf("Acesso autorizado. Visitante dentro do horário.\n");
        } else {
            printf("Acesso negado. Biblioteca fechada nesse horário para visitantes.\n");
        }
    }

    return 0;
}
