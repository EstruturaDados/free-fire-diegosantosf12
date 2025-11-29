#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define MAX_TEXTO 50

// Estrutura que representa um item da mochila
typedef struct {
    char nome[MAX_TEXTO];
    char tipo[MAX_TEXTO];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS]; // Vetor estático com até 10 itens
    int total = 0;           // Contador de itens cadastrados
    int opcao;

    // Menu interativo
    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        // Adicionar item
        if (opcao == 1 && total < MAX_ITENS) {
            printf("Nome: ");
            fgets(mochila[total].nome, MAX_TEXTO, stdin);
            mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0';

            printf("Tipo: ");
            fgets(mochila[total].tipo, MAX_TEXTO, stdin);
            mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = '\0';

            printf("Quantidade: ");
            scanf("%d", &mochila[total].quantidade);
            getchar();

            total++;
        }
        // Remover item
        else if (opcao == 2) {
            char nome[MAX_TEXTO];
            printf("Nome do item a remover: ");
            fgets(nome, MAX_TEXTO, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            int encontrado = 0;
            for (int i = 0; i < total; i++) {
                if (strcmp(mochila[i].nome, nome) == 0) {
                    mochila[i] = mochila[total - 1]; // substitui pelo último
                    total--;
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Item nao encontrado.\n");
            }
        }
        // Listar itens
        else if (opcao == 3) {
            printf("\nInventario:\n");
            for (int i = 0; i < total; i++) {
                printf("%s | %s | %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            }
        }
    } while (opcao != 0);

    return 0;
}