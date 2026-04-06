# Lista de Tarefas Inteligente - EDA

## Objetivo do Projeto
O objetivo deste projeto é implementar um sistema gerenciador de tarefas diárias (focado em acompanhamento de atividades). O cerne técnico do sistema é a aplicação de uma lista simplesmente encadeada em Linguagem C, utilizando um algoritmo de busca sequencial otimizado com a heurística **Mover-Para-Frente** (Move-to-Front).

## Características dos Dados e Arquitetura

* **Estrutura de Dados em C:** Os itens são armazenados dinamicamente em uma `struct Tarefa`, contendo um identificador único (`id` numérico), uma string com a `descricao` e um ponteiro para o próximo nó.
* **Heurística Mover-Para-Frente:** Ao realizar uma busca bem-sucedida pelo ID, o nó correspondente é desvinculado de sua posição atual no meio/fim da lista e realocado para o topo (passando a ser o `head`). Essa política garante que os itens mais acessados fiquem no início, com um custo de acesso futuro que se aproxima de O(1).
* **Camadas Isoladas:** O projeto mantém e separa firmemente regras de negócio (`tarefas.c` e `tarefas.h`) das funções e telas iterativas em terminal (`main.c`).

## Divisão de Responsabilidades

O desenvolvimento desta estrutura funcional se divide fundamentalmente nas seguintes frentes (adaptáveis na sua documentação):

### Estrutura de Dados e Lógica
* Manuseio da fila dinâmica e alocação (`malloc`/`free`).
* Adição (`inserir_tarefa`) ao final da lista.
* Algoritmo complexo que recria vínculos `anterior->prox = atual->prox` para mover os nós em tempo de execução sem corromper memória.

### Interface em Terminal (UI)
* Confecção visual da "Tela Principal".
* Fluxo de navegação validada das telas de Inserção, Busca e Listagem.
* Proteção contra lixo de memória na entrada de dados via `scanf`. 

### Responsabilidade Compartilhada
* Integração limpa e modular através do arquivo `Makefile`, juntando o cabeçalho compartilhado para execução performática.

## 💻 Como Executar

O projeto é mantido modularizado e utiliza rotinas de compilação automáticas (`make`).

### ⚙️ 1. Compilando os Arquivos 
Para gerar o executável final ligando a *main* à biblioteca de funções da lista, é necessário que o GCC esteja instalado no sistema.

No terminal Unix/Linux, dentro da pasta raiz:

1. Acesse o diretório:
   `cd /home/cayoalencar/Documentos/eda2/G17_Busca_Eda2-2026.1`
2. Dispare o compilador com as flag patterns:
   `make`

*(O Makefile lidará com a compilação gerando o binário executável local "tarefas")*

### 🚀 2. Executando o Motor da Lista
Com a compilação concluída com sucesso:

1. Na mesma pasta, execute o gerenciador de tarefas:
   `./tarefas`
2. Teste todo o fluxo! Adicione duas tarefas e interaja com a **Opção 2 - Busca**. Ao visualizar a lista logo após (Opção 3), o nó pesquisado terá saltado automaticamente para a cabeça da fila.

## 🎥 Demonstração Visual

**Assista ao nosso vídeo explicativo no YouTube:**  
*(Mude para o link do seu vídeo na entrega acadêmica)*
[![Vídeo de Demonstração](https://img.youtube.com/vi/LINK_DO_SEU_VIDEO_AQUI/maxresdefault.jpg)](https://youtu.be/LINK_DO_SEU_VIDEO_AQUI)

### Capturas de Tela do Sistema
*(Subsitua pelos arquivos de print de tela rodando no terminal Linux)*
<img src="docs/assets/capturas%20de%20tela/screenshot_1.png" width="300"/> <img src="docs/assets/capturas%20de%20tela/screenshot_2.png" width="300"/> <img src="docs/assets/capturas%20de%20tela/screenshot_3.png" width="300"/>

## Equipe de Desenvolvimento

| <img src="docs/assets/fotos/Sua_foto_GitHub.png" width="120px;" alt="Cayo Alencar"/><br />**Cayo Alencar** | 
| :---: | 
| Matrícula: **Insira_sua_matricula_aqui** | 
| <img src="https://github.com/SeuUserGithub.png" width="16px;"/> [`@SeuUserGithub`](https://github.com/SeuUserGithub) | 
