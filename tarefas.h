#ifndef TAREFAS_H
#define TAREFAS_H

// Definição da estrutura da Tarefa
typedef struct Tarefa {
    int id;
    char descricao[256];
    struct Tarefa *prox;
} Tarefa;

// Protótipos das funções da lógica da lista encadeada
void inserir_tarefa(Tarefa **head, int id, const char *descricao);
Tarefa* buscar_tarefa(Tarefa **head, int id);
void listar_tarefas(Tarefa *head);
void liberar_lista(Tarefa **head);

#endif // TAREFAS_H
