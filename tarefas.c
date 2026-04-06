#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefas.h"

// Adiciona uma nova tarefa no final da lista
void inserir_tarefa(Tarefa **head, int id, const char *descricao) {
    Tarefa *nova = (Tarefa *)malloc(sizeof(Tarefa));
    if (!nova) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    nova->id = id;
    strncpy(nova->descricao, descricao, sizeof(nova->descricao) - 1);
    nova->descricao[sizeof(nova->descricao) - 1] = '\0';
    nova->prox = NULL;

    // Se a lista estiver vazia, o novo nó é o head
    if (*head == NULL) {
        *head = nova;
    } else {
        // Percorre até o final para inserir
        Tarefa *temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = nova;
    }
}

// Busca uma tarefa pelo ID com a heurística Move-to-Front
Tarefa* buscar_tarefa(Tarefa **head, int id) {
    if (*head == NULL) return NULL; // Lista vazia

    Tarefa *atual = *head;
    Tarefa *anterior = NULL;

    // Realiza a busca sequencial
    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se a tarefa não foi encontrada (chegou ao fim sem sucesso)
    if (atual == NULL) {
        return NULL;
    }

    // Se encontrou e a tarefa JÁ É a primeira (head), a lista permanece inalterada
    if (anterior == NULL) {
        return atual;
    }

    // Regra do Mover-Para-Frente:
    // O nó foi encontrado e NÃO é o primeiro.
    
    // 1. Desvincula o nó de sua posição atual
    anterior->prox = atual->prox;
    
    // 2. Coloca-o no início da lista (aponta para o head atual)
    atual->prox = *head;
    
    // 3. Atualiza o ponteiro do head para ser o nó recém-movido
    *head = atual;

    return atual;
}

// Imprime a lista de tarefas atual
void listar_tarefas(Tarefa *head) {
    if (head == NULL) {
        printf("A lista de tarefas esta vazia.\n");
        return;
    }
    printf("--- Lista de Tarefas ---\n");
    Tarefa *temp = head;
    while (temp != NULL) {
        printf("[ID: %d] %s\n", temp->id, temp->descricao);
        temp = temp->prox;
    }
    printf("------------------------\n");
}

// Libera a memória de todos os nós (ao encerrar o programa)
void liberar_lista(Tarefa **head) {
    Tarefa *atual = *head;
    Tarefa *prox;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *head = NULL;
}
