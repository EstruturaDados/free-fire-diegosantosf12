#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define MAX_TEXTO 50

// Estrutura que representa um item da mochila com prioridade
typedef struct {
    char nome[MAX_TEXTO];
    char tipo[MAX_TEXTO];
    int quantidade;
    int prioridade; // valor de 1 a 5
} Item;

// Função para ordenar os itens por nome usando Insertion Sort
void ordenarPorNome(Item mochila[], int total, int *comparacoes) {
    for (int i = 1; i < total; i++) {
        Item chave = mochila[i];
        int j = i - 1;
        while (j >= 0 && strcmp(mochila[j].nome, chave.nome) > 0) {
            mochila[j + 1] = mochila[j];
            j--;
            (*comparacoes)++;
        }
        mochila[j + 1] = chave;
    }
}

// Função para busca binária por nome (requer lista ordenada)
int buscaBinaria(Item mochila[], int total, char nome[]) {
    int inicio = 0, fim = total - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(mochila[meio].nome, nome);
        if (cmp == 0) return meio;
        else if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    // Menu principal do jogo
    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar item\n");
        printf("2 - Ordenar por nome\n");
        printf("3 - Buscar item (binaria)\n");
        printf("4 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        // Adiciona item à mochila
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

            printf("Prioridade (1 a 5): ");
            scanf("%d", &mochila[total].prioridade);
            getchar();

            total++;
        }

        // Ordena os itens por nome
        else if (opcao == 2) {
            int comparacoes = 0;
            ordenarPorNome(mochila, total, &comparacoes);
            printf("Itens ordenados por nome. Comparacoes realizadas: %d\n", comparacoes);
        }

        // Busca binária por nome
        else if (opcao == 3) {
            char nomeBusca[MAX_TEXTO];
            printf("Nome do item a buscar: ");
            fgets(nomeBusca, MAX_TEXTO, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

            int pos = buscaBinaria(mochila, total, nomeBusca);
            if (pos != -1) {
                printf("Item encontrado:\n");
                printf("Nome: %s\nTipo: %s\nQuantidade: %d\nPrioridade: %d\n",
                       mochila[pos].nome,
                       mochila[pos].tipo,
                       mochila[pos].quantidade,
                       mochila[pos].prioridade);
            } else {
                printf("Item nao encontrado.\n");
            }
        }

        // Lista todos os itens da mochila
        else if (opcao == 4) {
            printf("\nInventario:\n");
            for (int i = 0; i < total; i++) {
                printf("%s | %s | %d | Prioridade: %d\n",
                       mochila[i].nome,
                       mochila[i].tipo,
                       mochila[i].quantidade,
                       mochila[i].prioridade);
            }
        }

        // Encerra o programa
        else if (opcao == 0) {
            printf("Saindo do jogo. Ate a proxima!\n");
        }

        // Opção inválida
        else {
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}