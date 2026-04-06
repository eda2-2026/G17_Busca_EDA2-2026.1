#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefas.h"

// Função utilitária para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Controla a exibição e lógica da tela de inserção
void tela_insercao(Tarefa **head) {
    int id;
    char descricao[256];

    printf("\n=== ADICIONAR TAREFA ===\n");
    printf("Digite o ID da tarefa (apenas numeros inteiros): ");
    if (scanf("%d", &id) != 1) {
        printf("\nERRO: ID invalido!\n");
        limpar_buffer();
        printf("Pressione 'Enter' para voltar ao menu...");
        getchar();
        return;
    }
    limpar_buffer(); // Limpa o '\n' deixado pelo scanf

    printf("Digite a descricao da tarefa: ");
    fgets(descricao, sizeof(descricao), stdin);
    descricao[strcspn(descricao, "\n")] = '\0'; // Remove o newline inserido pelo fgets

    inserir_tarefa(head, id, descricao);
    printf("\n>>> Sucesso: Tarefa '%s' adicionada ao final da lista! <<<\n", descricao);
    printf("\nPressione 'Enter' para continuar...");
    getchar();
}

// Controla a exibição e lógica da tela de busca com move-to-front
void tela_busca(Tarefa **head) {
    int id;

    printf("\n=== BUSCAR TAREFA ===\n");
    if (*head == NULL) {
        printf("A lista esta vazia. Nenhuma tarefa para buscar.\n");
        printf("\nPressione 'Enter' para voltar ao menu...");
        getchar();
        return;
    }

    printf("Digite o ID da tarefa que deseja buscar: ");
    if (scanf("%d", &id) != 1) {
        printf("\nERRO: ID invalido!\n");
        limpar_buffer();
        printf("Pressione 'Enter' para voltar ao menu...");
        getchar();
        return;
    }
    limpar_buffer();

    Tarefa *encontrada = buscar_tarefa(head, id);
    
    if (encontrada) {
        printf("\n+++ TAREFA ENCONTRADA +++\n");
        printf("ID.......: %d\n", encontrada->id);
        printf("Descricao: %s\n", encontrada->descricao);
        printf("-------------------------\n");
        printf(">>> AVISO IMPORTANTE: Esta tarefa foi movida para o topo da lista (Move-to-Front)! <<<\n");
    } else {
        printf("\n--- FALHA NA BUSCA ---\n");
        printf("Tarefa com ID %d nao foi encontrada na lista.\n", id);
    }
    printf("\nPressione 'Enter' para voltar ao menu...");
    getchar();
}

// Controla a exibição da tela de listagem de todas as tarefas
void tela_listagem(Tarefa *head) {
    printf("\n=== VISUALIZACAO GERAL DAS TAREFAS ===\n");
    listar_tarefas(head);
    printf("\nPressione 'Enter' para voltar ao menu...");
    getchar();
}

// Loop principal do programa gerenciando as telas
int main() {
    Tarefa *lista = NULL; // Head da lista
    int opcao = 0;

    while (opcao != 4) {
        // Menu Principal
        printf("\n===================================\n");
        printf("    LISTA DE TAREFAS INTELIGENTE   \n");
        printf("      (Auto-organizavel M-T-F)     \n");
        printf("===================================\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Buscar/Acessar Tarefa\n");
        printf("3. Listar Todas as Tarefas\n");
        printf("4. Sair\n");
        printf("===================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            opcao = 0; // Força cair no default
        }
        limpar_buffer();

        switch (opcao) {
            case 1:
                tela_insercao(&lista);
                break;
            case 2:
                tela_busca(&lista);
                break;
            case 3:
                tela_listagem(lista);
                break;
            case 4:
                printf("\nSaindo do sistema. Liberando memoria...\n");
                liberar_lista(&lista);
                printf("Programa encerrado com sucesso. Ate logo!\n\n");
                break;
            default:
                printf("\n>>> Opcao invalida. Tente novamente! <<<\n");
                printf("Pressione 'Enter' para voltar ao menu...");
                getchar();
                break;
        }
    }

    return 0;
}
