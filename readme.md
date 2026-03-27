## Solicitação da Atividade

Nesta atividade, o estudante devera submeter a solução implementada em C Ansi para o seguinte problema:
- Abrir o arquivo myfile.dat (Data File) para leitura binária
- Ler os registros e carregá-los para a memória usando alguma estrutura de dados
- Permitir fazer uma projeção dos registros consultando apenas registros de um determinado tipo
  Estrutura do arquivo de dados é a seguinte:

```
  +-----+-------+-------+----+------+--------
  |Type |Length |Content|Type|Length|Content ..........
  +-----+-------+-------+----+------+--------
```

- Onde Type é o tipo do conteúdo (C - Character, I - Integer, F - Float e S - String), Length é o tamnho em bytes do conteúdo do registro e Content é o dado.
  A solução deve ter um "menu" para o usuário escolher a carga e a consulta.
  No caso da consulta, o usuário escolhe o tipo de dado. Por exemplo, caso escolher I, serão apresentados apenas os registros que contenham esse tipo.

## Compilação e execuçã

O projeto utiliza CMAKE para a compilação! Ele precisa estar instalado no sistema.
Para instalar, no ubuntu, basta rodar o seguinte comando:

    sudo apt install cmake

Para compilar o projeto, primeiro deve-se criar a pasta para a compilação, vamos chamar de cmake-build-debug:

    mkdir cmake-build-debug

Após a pasta criada, basta executar o seguinte comando:

    cmake --build ./cmake-build-debug --target prj1 -j 30

Com o programa compilado, basta executá-lo através do comando:

    ./cmake-build-debug/prj1


## Informações sobre o desenvolvimento

O sistema foi desenvolvido em C Ansi (89/90) e testado com target para linux-amd64.

## Solução apresentada

* O sistema apresenta um menu de opções para o usuário
* O sistema carrega o arquivo conforme a definição especificada no trabalho
* É possível listar apenas as 20 primeiras linhas do arquivo 
* É possível listar todos os registros do tipo especificado
