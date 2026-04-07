# Lista-de-Tarefas-Inteligente

Número da Lista: 17
Conteúdo da Disciplina: Estrutura de Dados 2

## Alunos

| Matrícula | Aluno        |
| --------- | ------------ |
| 211031682 | Davi Casseb  |
| 221022506  | Cayo Alencar |

## Sobre

Este projeto implementa um sistema de gerenciamento de tarefas diárias utilizando uma lista simplesmente encadeada em linguagem C.

O principal objetivo é demonstrar o uso de **busca sequencial otimizada** com a heurística **Move-to-Front (Mover para Frente)**. Sempre que uma tarefa é encontrada, ela é movida para o início da lista, tornando acessos futuros mais rápidos.

Funcionalidades:

* Inserção de tarefas
* Busca por ID
* Listagem de tarefas
* Otimização dinâmica baseada em frequência de acesso

## Screenshots

<img src="docs/assets/capturas%20de%20tela/screenshot_1.png" width="300"/> 
<img src="docs/assets/capturas%20de%20tela/screenshot_2.png" width="300"/> 
<img src="docs/assets/capturas%20de%20tela/screenshot_3.png" width="300"/>

## Instalação

Linguagem: C
Framework: Não possui

Pré-requisitos:

* GCC instalado
* Sistema Linux/Unix ou compatível (WSL, MSYS2, etc.)

Comandos para compilar:

```bash
make
```

## Uso

Após a compilação, execute:

```bash
./tarefas
```

Fluxo básico de uso:

1. Inserir tarefas pelo menu
2. Buscar tarefas pelo ID (ativa o Move-to-Front)
3. Listar tarefas para observar a reorganização da lista

## Outros

### Arquitetura do Projeto

* `tarefas.c / tarefas.h`: implementação da lista encadeada e regras de negócio
* `main.c`: interface de interação via terminal
* `Makefile`: automação da compilação

### Destaque Técnico

* Estrutura de dados dinâmica com alocação via `malloc`/`free`
* Implementação de **lista auto-organizável (self-organizing list)**
* Otimização de busca com heurística adaptativa

### Complexidade

* Busca padrão: O(n)
* Com otimização (uso frequente): tende a O(1)

### Demonstração

[Link do vídeo no YouTube](https://youtu.be/bHvEOC1Nx7M)
