#include "expressao.c"

#define MAX_INPUT 512

int main() {
    Expressao expr;

    printf("=== Avaliador de Expressoes Pos-Fixadas ===\n");
    printf("Digite uma expressao em notacao pos-fixada (ou 'sair' para encerrar):\n");
    printf("Exemplo de expressao em notacao pos-fixa: 3 12 4 + *\n");
    printf("Como deve-se aparecer a expressao em forma in-fixa: 3 * (12 + 4)\n");
    printf("E o resultado deve ser: 48.00\n");


    while (1) {
        printf("\nEscreva aqui -> ");

        if (fgets(expr.posFixa, MAX_INPUT, stdin) == NULL) {
            printf("Erro ao ler a entrada. Tente novamente.\n");
            continue;
        }

        expr.posFixa[strcspn(expr.posFixa, "\n")] = '\0';

        if (strcmp(expr.posFixa, "sair") == 0) {
            printf("Encerrando o programa.\n");
            break;
        }

        strcpy(expr.inFixa, getFormaInFixa(expr.posFixa));

        expr.Valor = getValor(expr.posFixa);
        

        printf("\nExpressao Pos-fixada: %s", expr.inFixa);
        printf("\nValor da Expressao: %.2f\n", expr.Valor);
    }

    return 0;
}